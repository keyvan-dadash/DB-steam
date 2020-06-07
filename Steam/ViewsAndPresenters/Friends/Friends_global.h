#ifndef FRIENDS_GLOBAL_H
#define FRIENDS_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(FRIENDS_LIBRARY)
#  define FRIENDS_EXPORT Q_DECL_EXPORT
#else
#  define FRIENDS_EXPORT Q_DECL_IMPORT
#endif

#endif // FRIENDS_GLOBAL_H
