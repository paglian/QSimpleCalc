#include "QSimpleCalc.h"
#include "mathlib/Parser.h"

QSimpleCalc::QSimpleCalc()
{
}

double QSimpleCalc::eval(const QString &strExp, QString *errMsg)
{
    Node *exp = Parser().parse(strExp, errMsg);

    if (exp) {
        return exp->eval();
    } else {
        return 0;
    }

}
