#ifndef NODE_H
#define NODE_H

#include <cmath>

#include "Exceptions.h"

/**
 * @brief Result
 */
typedef double Result;

/**
 * @brief The Node class
 */
class Node
{
public:
    virtual Result eval() const = 0;

    virtual ~Node() { }
};

/**
 * @brief The NullValue class
 */
class NullValue : public Node
{
public:
    virtual Result eval() const
    {
        throw NullValueException();
    }
};

/**
 * @brief The FloatValue class
 */
class FloatValue : public Node
{
public:

    FloatValue(double value)
        : _value(value)
    { }

    virtual Result eval() const
    {
        return _value;
    }

private:
    double _value;
};

/**
 * @brief The UnaryOp class
 */
class UnaryOp : public Node
{
public:

    UnaryOp(Node *exp)
        : _exp(exp)
    { }

    virtual ~UnaryOp()
    {
        delete _exp;
    }

protected:
    Node *_exp;

private:
    UnaryOp(const UnaryOp &);
    UnaryOp & operator=(const UnaryOp &);
};

/**
 * @brief The BynaryOp class
 */
class BynaryOp : public Node
{
public:

    BynaryOp(Node *exp1, Node *exp2)
        : _exp1(exp1), _exp2(exp2)
    { }

    virtual ~BynaryOp()
    {
        delete _exp1;
        delete _exp2;
    }

protected:
    Node *_exp1;
    Node *_exp2;

private:
    BynaryOp(const BynaryOp &);
    BynaryOp & operator=(const BynaryOp &);
};

/**
 * @brief The AddOp class
 */
class AddOp : public BynaryOp
{
public:

    AddOp(Node *exp1, Node *exp2)
        : BynaryOp(exp1, exp2)
    { }

    virtual Result eval() const
    {
        return _exp1->eval() + _exp2->eval();
    }
};


/**
 * @brief The SubsOp class
 */
class SubsOp : public BynaryOp
{
public:

    SubsOp(Node *exp1, Node *exp2)
        : BynaryOp(exp1, exp2)
    { }

    virtual Result eval() const
    {
        return _exp1->eval() - _exp2->eval();
    }
};


/**
 * @brief The MultOp class
 */
class MultOp : public BynaryOp
{
public:

    MultOp(Node *exp1, Node *exp2)
        : BynaryOp(exp1, exp2)
    { }

    virtual Result eval() const
    {
        return _exp1->eval() * _exp2->eval();
    }
};


/**
 * @brief The DivOp class
 */
class DivOp : public BynaryOp
{
public:

    DivOp(Node *exp1, Node *exp2)
        : BynaryOp(exp1, exp2)
    { }

    virtual Result eval() const
    {
        Result d = _exp2->eval();
        if (d != 0) {
            return _exp1->eval() / d;
        } else {
            throw DivByZeroException();
        }
    }
};

/**
 * @brief The LogOp class
 */
class LogOp : public UnaryOp
{
public:

    LogOp(Node *exp)
        : UnaryOp(exp)
    { }

    virtual Result eval() const
    {
        Result d = _exp->eval();
        if (d > 0) {
            return std::log10(d);
        } else if (d == 0) {
            throw LogZeroException();
        } else {
            throw LogNegativeException();
        }
    }
};


#endif // NODE_H
