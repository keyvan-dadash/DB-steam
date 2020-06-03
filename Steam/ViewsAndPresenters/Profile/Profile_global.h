#ifndef PROFILE_GLOBAL_H
#define PROFILE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(PROFILE_LIBRARY)
#  define PROFILE_EXPORT Q_DECL_EXPORT
#else
#  define PROFILE_EXPORT Q_DECL_IMPORT
#endif

#endif // PROFILE_GLOBAL_H
