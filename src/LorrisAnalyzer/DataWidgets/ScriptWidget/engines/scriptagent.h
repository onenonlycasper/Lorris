/**********************************************
**    This file is part of Lorris
**    http://tasssadar.github.com/Lorris/
**
**    See README and COPYING
***********************************************/

#ifndef SCRIPTAGENT_H
#define SCRIPTAGENT_H

#include <QScriptEngineAgent>
#include <QElapsedTimer>

class QtScriptEngine;
class ScriptAgent : public QScriptEngineAgent
{
public:
    explicit ScriptAgent(QtScriptEngine *qtengine, QScriptEngine * engine);

    void restartEnterFuncCnt() { m_enterFuncCnt = 0; }

    void exceptionThrow (qint64 scriptId, const QScriptValue & exception, bool hasHandler);
    void scriptLoad(qint64, const QString &, const QString &, int);
    void functionEntry(qint64 scriptId);
    void functionExit(qint64 scriptId, const QScriptValue &returnValue);

private:
    QElapsedTimer m_timer;
    quint8 m_errors;
    QtScriptEngine *m_engine;
    int m_enterFuncCnt;
};

#endif // SCRIPTAGENT_H
