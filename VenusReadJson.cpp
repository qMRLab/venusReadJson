#include "VenusReadJson.h"
#include <QDateTime>
#include <QStringList>
#include <QFile>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QVariantMap>
#include <QJsonObject>
#include <QDebug>


//RthDisplayImageViewTool ( RthMainImageDisplay   parent)

RTHLOGGER_CREATE_PREFIX("VenusDisplay", VenusReadJson)

RTHDISPLAYIMAGEVIEWTOOL_SCRIPTCONSTRUCTOR(readJsonConstructor, VenusReadJson)

VenusReadJson::VenusReadJson(RthMainImageDisplay *parent) 
: RthDisplayImageViewTool(parent) {
}

VenusReadJson::~VenusReadJson()
{
}

bool VenusReadJson::readJsonFile(const QString& filename) {
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Failed to open file:" << filename;
        return false;
    }

    QByteArray jsonData = file.readAll();
    file.close();

    QJsonParseError error;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonData, &error);
    if (jsonDocument.isNull() || error.error != QJsonParseError::NoError) {
        qDebug() << "Failed to parse JSON file:" << filename;
        return false;
    }

    this->jsonData = jsonDocument.object();
    return true;
}

bool VenusReadJson::writeJsonFile(const QString& filename) {
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly)) {
        qDebug() << "Failed to create file:" << filename;
        return false;
    }

    QJsonDocument jsonDocument(this->jsonData.toObject());
    file.write(jsonDocument.toJson());
    file.close();

    return true;
}

const QJsonValue& VenusReadJson::getJsonData() const {
    return jsonData;
}