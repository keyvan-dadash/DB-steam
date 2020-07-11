#ifndef LIBRARY_GLOBAL_H
#define LIBRARY_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(LIBRARY_LIBRARY)
#  define LIBRARY_EXPORT Q_DECL_EXPORT
#else
#  define LIBRARY_EXPORT Q_DECL_IMPORT
#endif

#endif // LIBRARY_GLOBAL_H
