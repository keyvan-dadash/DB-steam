#ifndef STORE_GLOBAL_H
#define STORE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(STORE_LIBRARY)
#  define STORE_EXPORT Q_DECL_EXPORT
#else
#  define STORE_EXPORT Q_DECL_IMPORT
#endif

#endif // STORE_GLOBAL_H
