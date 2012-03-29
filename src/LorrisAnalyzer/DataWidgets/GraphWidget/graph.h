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

#ifndef GRAPH_H
#define GRAPH_H

#include <qwt_plot.h>

class Graph : public QwtPlot
{
    Q_OBJECT

Q_SIGNALS:
    void updateSampleSize();

public:
    Graph(QWidget *parent = 0);

    void showLegend(bool show);

    double XupperBound();
    double XlowerBound();
    double YupperBound();
    double YlowerBound();

protected:
    void mousePressEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);

public slots:
    void showCurve(QwtPlotItem *item, bool on);
};

#endif // GRAPH_H
