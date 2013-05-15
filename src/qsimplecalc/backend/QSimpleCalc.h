#ifndef QSIMPLECALC_H
#define QSIMPLECALC_H

#include <QString>

class QSimpleCalc
{
public:
    QSimpleCalc();

    double eval(const QString &strExp, QString *errMsg = 0);
};

#endif // QSIMPLECALC_H
