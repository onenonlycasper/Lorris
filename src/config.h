#ifndef CONFIG_H
#define CONFIG_H

#include <QSettings>
#include <map>

#include "singleton.h"

enum cfg_quint32
{
    CFG_QUINT32_CONNECTION_TYPE = 0,
    CFG_QUINT32_TAB_TYPE,
    CFG_QUINT32_SERIAL_BAUD,
    CFG_QUINT32_ANALYZER_UPDATE_TIME,

    CFG_QUINT32_NUM
};

enum cfg_string
{
    CFG_STRING_SERIAL_PORT = 0,
    CFG_STRING_SHUPITO_PORT,
    CFG_STRING_HEX_FOLDER,
    CFG_STRING_ANALYZER_FOLDER,

    CFG_STRING_NUM
};

enum cfg_bool
{
    CFG_BOOL_SHUPITO_TUNNEL = 0,

    CFG_BOOL_NUM
};

class Config : public Singleton<Config>
{
    typedef std::map<cfg_quint32, quint32> def_map_quint32;
    typedef std::map<cfg_string, QString> def_map_string;
    typedef std::map<cfg_bool, bool> def_map_bool;

public:
    Config();
    ~Config();

    quint32 get(cfg_quint32 item);
    QString get(cfg_string item);
    bool    get(cfg_bool item);

    void set(cfg_quint32 item, quint32        val);
    void set(cfg_string  item, const QString& val);
    void set(cfg_bool    item, bool           val);

private:
    QSettings *m_settings;
    def_map_quint32 m_def_quint32;
    def_map_string m_def_string;
    def_map_bool m_def_bool;
};

#define sConfig Config::GetSingleton()

#endif // CONFIG_H