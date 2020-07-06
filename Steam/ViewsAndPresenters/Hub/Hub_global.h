#ifndef HUB_GLOBAL_H
#define HUB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(HUB_LIBRARY)
#  define HUB_EXPORT Q_DECL_EXPORT
#else
#  define HUB_EXPORT Q_DECL_IMPORT
#endif

#endif // HUB_GLOBAL_H
