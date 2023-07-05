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
#ifndef VENUSREADJSONPLUGIN_H
#define VENUSREADJSONPLUGIN_H

#include <QtScript>

class VenusReadJsonPlugin : public QScriptExtensionPlugin {
  Q_OBJECT
#if (QT_VERSION >= 0x050000)
  Q_PLUGIN_METADATA(IID "org.qmrlab.venus.rthreadjsonplugin" FILE "VenusReadJsonPlugin.json")
#endif

public:
  QStringList keys() const;
  void initialize( const QString &key, QScriptEngine *engine );
};
#endif
