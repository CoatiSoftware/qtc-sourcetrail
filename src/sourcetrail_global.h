#pragma once

#include <QtGlobal>

#if defined(QTCREATORSOURCETRAIL_LIBRARY)
#  define QTCREATORSOURCETRAILSHARED_EXPORT Q_DECL_EXPORT
#else
#  define QTCREATORSOURCETRAILSHARED_EXPORT Q_DECL_IMPORT
#endif

namespace Sourcetrail
{

enum SourcetrailPluginOptions
{
    hostAddress = 1,
    pluginPort = 2,
    sourcetrailPort = 3
};

} // namespace Sourcetrail
