#ifndef PROFILE_H
#define PROFILE_H

#include "Profile_global.h"
#include <QtWidgets>

#include "../../Steam/copyablewidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Profile; }
QT_END_NAMESPACE


class PROFILE_EXPORT Profile : public CopyableWidget
{
    Q_OBJECT
public:
    Profile(QWidget *parent = nullptr);
    ~Profile();

    CopyableWidget * copy() override;

private:
    Ui::Profile *ui;
};

#endif // PROFILE_H
