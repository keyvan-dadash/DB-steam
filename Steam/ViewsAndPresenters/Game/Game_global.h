#ifndef GAME_GLOBAL_H
#define GAME_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(GAME_LIBRARY)
#  define GAME_EXPORT Q_DECL_EXPORT
#else
#  define GAME_EXPORT Q_DECL_IMPORT
#endif

#endif // GAME_GLOBAL_H
