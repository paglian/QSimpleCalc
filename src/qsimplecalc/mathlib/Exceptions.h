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

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>

/**
 * @brief The MathException class is the base class for all math exceptions
 */
class MathException : public std::exception
{
};

/**
 * @brief The InvalidSyntaxException class
 */
class InvalidSyntaxException : public MathException
{
};

/**
 * @brief The DivByZeroException class
 */
class DivByZeroException : public MathException
{
};

/**
 * @brief The LogZeroException class
 */
class LogZeroException : public MathException
{
};

/**
 * @brief The LogNegativeException class
 */
class LogNegativeException : public MathException
{
};

/**
 * @brief The VariableEvalException class
 */
class VariableEvalException : public MathException
{
};

/**
 * @brief The UnbalancedParException class
 */
class UnbalancedParException : public InvalidSyntaxException
{
};

#endif // EXCEPTIONS_H
