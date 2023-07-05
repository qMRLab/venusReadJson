#ifndef VENUSREADJSON_H
#define VENUSREADJSON_H

#include <QObject>
#include <QJsonValue>
#include <QtScript>
#include "RthLogger.h"
#include "RthDisplayImageViewTool.h"


class VenusReadJson : public RthDisplayImageViewTool {
    Q_OBJECT
    RTHLOGGER_DECLARE

private:
    QJsonValue jsonData;

public:
    VenusReadJson(RthMainImageDisplay *parent);
    QString toolId() const
    {
        return "json";
    };
    ~VenusReadJson();
    bool readJsonFile(const QString& filename);
    bool writeJsonFile(const QString& filename);
    const QJsonValue& getJsonData() const;
};

QScriptValue readJsonConstructor(QScriptContext *context, QScriptEngine *engine);

//RTHUPDATE_DECLARE_QMETAOBJECT(VenusReadJson, QObject *)
#endif // RTHREADJSON_H