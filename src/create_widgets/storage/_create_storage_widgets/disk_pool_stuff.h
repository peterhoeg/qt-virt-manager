#ifndef DISK_POOL_STUFF_H
#define DISK_POOL_STUFF_H

#include "_pool_stuff.h"

class Disk_Pool_Stuff : public _Pool_Stuff
{
    Q_OBJECT
public:
    explicit Disk_Pool_Stuff(QWidget *parent = 0);

signals:

public slots:
    QDomDocument getStorageXMLDesc() const;
};

#endif // DISK_POOL_STUFF_H