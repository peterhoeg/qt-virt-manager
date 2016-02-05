#ifndef HV_FEATURES_H
#define HV_FEATURES_H

#include <QWidget>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QDomDocument>
#include "create_widgets/domain/_changed.h"

class HV_Features : public _Changed
{
    Q_OBJECT
public:
    explicit HV_Features(QWidget *parent = 0);
    QTextEdit       *features;

signals:
    //void             dataChanged();

private:
    QVBoxLayout     *commonLayout;

public slots:
    void             setFeatures(QDomDocument&);
};

#endif // HV_FEATURES_H
