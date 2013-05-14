#ifndef QSIMPLECALC_H
#define QSIMPLECALC_H

#include <QString>

class QSimpleCalc
{
public:
    QSimpleCalc();

    double eval(const QString &exp);
};

#endif // QSIMPLECALC_H
