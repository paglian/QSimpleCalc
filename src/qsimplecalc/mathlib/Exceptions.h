#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <QString>
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
 * @brief The NullValueException class
 */
class NullValueException : public MathException
{
};

/**
 * @brief The UnbalancedParException class
 */
class UnbalancedParException : public MathException
{
};

#endif // EXCEPTIONS_H
