/***************************************************************************

 Copyright 2013 HeartVista Inc.  All rights reserved.
 Contact: HeartVista, Inc. <rthawk-info@heartvista.com>

 This file is part of the RTHawk system.

 $HEARTVISTA_BEGIN_LICENSE$

 THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF HEARTVISTA
 The copyright notice above does not evidence any
 actual or intended publication of such source code.

 $HEARTVISTA_END_LICENSE$

 ***************************************************************************/
#include "VenusReadJsonPlugin.h"

#include "VenusReadJson.h"

QStringList VenusReadJsonPlugin::keys() const
{
  QStringList list;
  list << QLatin1String("venus");
  list << QLatin1String("venus.readJson");
  return list;
}

void VenusReadJsonPlugin::initialize( const QString &key, QScriptEngine *engine )
{
  if (key == QLatin1String("venus")) {
  } else if (key == QLatin1String("venus.readJson")) {

    QScriptValue readJsonScriptConstructor = engine->newFunction(readJsonConstructor);
    QScriptValue readJsonMeta = engine->newQMetaObject(&VenusReadJson::staticMetaObject, readJsonScriptConstructor);
    engine->globalObject().setProperty("VenusReadJson", readJsonMeta);

    // QScriptValue rthReadJsonClass = engine->scriptValueFromQMetaObject<VenusReadJson>();
    // engine->globalObject().setProperty("VenusReadJson", rthReadJsonClass);

  } else {
    Q_ASSERT_X(false, "VenusReadJsonPlugin::initialize", qPrintable(key));
  }
}

#if (QT_VERSION < 0x050000)
Q_EXPORT_PLUGIN(VenusReadJsonPlugin)
#endif