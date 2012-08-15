/**********************************************
**    This file is part of Lorris
**    http://tasssadar.github.com/Lorris/
**
**    See README and COPYING
***********************************************/

#include "tab.h"

Tab::Tab(quint8 type, QWidget *parent) :
    QWidget(parent)
{
    m_type = type;
    m_windowId = 0;
}

Tab::~Tab()
{

}

bool Tab::onTabClose()
{
    return true;
}
