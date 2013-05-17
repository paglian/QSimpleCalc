#include "QSimpleCalc.h"
#include "mathlib/Parser.h"

QSimpleCalc::QSimpleCalc()
{
}

double QSimpleCalc::eval(const QString &strExp)
{
    Node *exp = Parser().parse(strExp);

    if (exp) {
        return exp->eval();
    } else {
        return 0;
    }
}
