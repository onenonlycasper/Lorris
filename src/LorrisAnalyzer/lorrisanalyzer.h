#ifndef LORRISANALYZER_H
#define LORRISANALYZER_H

#include "WorkTab/WorkTab.h"
#include "packet.h"

class QVBoxLayout;
class QHBoxLayout;
class QMdiArea;
class Parser;

enum states_
{
    STATE_DISCONNECTED    = 0x01,
    STATE_DIALOG          = 0x02
};

namespace Ui {
  class LorrisAnalyzer;
}

class LorrisAnalyzer : public WorkTab
{
    Q_OBJECT

    public:
        explicit LorrisAnalyzer();
        virtual ~LorrisAnalyzer();

        void onTabShow();

    private slots:
        void connectButton();
        void textLabelButton();
        void packetLenChanged(int val);

        void connectionResult(Connection*,bool);
        void connectedStatus(bool connected);

        void dataStructure(analyzer_packet pkt, QByteArray curData);

    private:
        void readData(QByteArray data);

        QVBoxLayout *layout;
        QHBoxLayout *layout_area;
        QMdiArea *m_area;
        quint16 m_state;
        Parser *m_parser;
        Ui::LorrisAnalyzer *ui;
};

#endif // LORRISANALYZER_H
