/****************************************************************************
**
**    This file is part of Lorris.
**    Copyright (C) 2012 Vojtěch Boček
**
**    Contact: <vbocek@gmail.com>
**             https://github.com/Tasssadar
**
**    Lorris is free software: you can redistribute it and/or modify
**    it under the terms of the GNU General Public License as published by
**    the Free Software Foundation, either version 3 of the License, or
**    (at your option) any later version.
**
**    Lorris is distributed in the hope that it will be useful,
**    but WITHOUT ANY WARRANTY; without even the implied warranty of
**    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**    GNU General Public License for more details.
**
**    You should have received a copy of the GNU General Public License
**    along with Lorris.  If not, see <http://www.gnu.org/licenses/>.
**
****************************************************************************/

#ifndef TERMINAL_H
#define TERMINAL_H

#include <QString>
#include <QAbstractScrollArea>
#include <vector>
#include <QPoint>

class QMenu;
class QByteArray;
class QFile;

enum term_fmt
{
    FMT_TEXT,
    FMT_HEX,
    FMT_MAX
};

enum term_input
{
    INPUT_SEND_KEYPRESS,
    INPUT_SEND_COMMAND,
    INPUT_MAX
};

class Terminal : public QAbstractScrollArea
{
    Q_OBJECT

Q_SIGNALS:
    void keyPressedASCII(QByteArray key);

public:
    Terminal(QWidget *parent);
    ~Terminal();

    void writeToFile(QFile *file);

    const QByteArray& getData()
    {
        return m_data;
    }

    int getFmt() { return m_fmt; }

public slots:
    void clear();
    void pause(bool pause);
    void appendText(QByteArray text);
    void setFmt(int fmt);
    void setInput(quint8 input);

protected:
    void keyPressEvent(QKeyEvent *event);
    void paintEvent(QPaintEvent *e);
    void resizeEvent(QResizeEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void focusInEvent(QFocusEvent *);
    void focusOutEvent(QFocusEvent *);

private slots:
    void copyToClipboard();
    void pasteFromClipboard();

private:
    void handleInput(const QByteArray& data, int key = 0);
    void updateScrollBars();
    void addLine(quint32 pos, char *&line_start, char *&line_end);
    void addLines(QByteArray text);
    void addHex();
    QPoint mouseToTextPos(const QPoint& pos);

    void selectAll();

    inline void adjustSelectionWidth(int &w, quint32 i, quint32 max, int len);

    inline std::vector<QString>& lines()
    {
        return m_paused ? m_pause_lines : m_lines;
    }

    std::vector<QString> m_lines;
    std::vector<QString> m_pause_lines;
    QByteArray m_data;

    bool m_paused;
    quint8 m_fmt;
    quint8 m_input;
    int m_hex_pos;

    int m_char_height;
    int m_char_width;

    QPoint m_cursor_pos;
    QPoint m_cursor_pause_pos;
    QRect m_cursor;

    QPoint m_sel_start;
    QPoint m_sel_begin;
    QPoint m_sel_stop;

    QByteArray m_command;

    QMenu *m_context_menu;
    QAction *m_fmt_act[FMT_MAX];
};

#endif // TERMINAL_H