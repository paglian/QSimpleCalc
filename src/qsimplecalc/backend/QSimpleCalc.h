/*
 * Copyright (C) 2013 Andres Pagliano.
 *
 * This file is part of QSimpleCalc.
 *
 * QSimpleCalc is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * QSimpleCalc is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with QSimpleCalc.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

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
