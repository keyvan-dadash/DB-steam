#ifndef PROFILE_H
#define PROFILE_H

#include "Profile_global.h"
#include <QtWidgets>

QT_BEGIN_NAMESPACE
namespace Ui { class Profile; }
QT_END_NAMESPACE


class PROFILE_EXPORT Profile : public QWidget
{
    Q_OBJECT
public:
    Profile(QWidget *parent = nullptr);
    ~Profile();

private:
    Ui::Profile *ui;
};

#endif // PROFILE_H
