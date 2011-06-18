#include "WorkTabMgr.h"
#include "WorkTabInfo.h"

#include "LorrisProbe/lorrisprobeinfo.h"

WorkTabMgr::WorkTabMgr()
{
    //put ALL plugins into this vector
    m_workTabInfos.push_back(new LorrisProbeInfo);
}

WorkTabMgr::~WorkTabMgr()
{
    for(uint8_t itr = 0; itr < m_workTabInfos.size(); ++itr)
        delete m_workTabInfos[itr];
}

std::vector<WorkTabInfo*> *GetWorkTabInfos()
{
    return NULL;
}
