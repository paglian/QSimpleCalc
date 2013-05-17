#ifndef QSIMPLECALC_H
#define QSIMPLECALC_H

#include <QString>

/**
 * @brief The QSimpleCalc class provides the back-end entry point to evaluate math expressions
 *
 * Example: double result = QSimpleCalc().eval("2 + 2*3");  // result == 8
 */
class QSimpleCalc
{
public:

    /**
     * @brief Evaluates the expression \a strExp and returns its result.
     *
     * @return If the expression is valid returns the result. Otherwise; throws a MathException
     *
     * @see MathException derived classes to get the list of possible errors
     */
    double eval(const QString &strExp);
};

#endif // QSIMPLECALC_H
