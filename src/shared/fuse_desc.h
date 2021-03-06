/**********************************************
**    This file is part of Lorris
**    http://tasssadar.github.com/Lorris/
**
**    See README and COPYING
***********************************************/

#ifndef FUSE_DESC_H
#define FUSE_DESC_H

#include <QString>
#include <QList>
#include <QHash>

#include <vector>

class fuse_desc
{
public:
    explicit fuse_desc(const QString &name, const QStringList &chipSigns, const QString &desc);

    void setDesc(const QString& desc) { m_desc = desc; }
    void setName(const QString& name) { m_name = name; }

    QString getDesc() const { return m_desc; }
    QString getName() const { return m_name; }

    bool isForChip(const QString& sign) const
    {
        return m_chipIds.contains(sign);
    }

    QString getOptDesc(const QString& opt)
    {
        return m_optDesc.contains(opt) ? m_optDesc[opt] : QString();
    }

    void addOption(const QString& binary, const QString& text)
    {
        m_optDesc[binary] = text;
    }

    void setChips(const QList<QString>& chips)
    {
        m_chipIds = chips;
    }

private:
    QString m_name;
    QString m_desc;

    QList<QString> m_chipIds;
    QHash<QString, QString> m_optDesc;
};

#endif // FUSE_DESC_H
