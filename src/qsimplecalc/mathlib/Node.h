#ifndef NODE_H
#define NODE_H

#include <cmath>

#include "Exceptions.h"

/**
 * @brief Result
 */
typedef double Result;

/**
 * @brief The Node class provides the base class for all nodes in the syntax parse tree.
 *
 * @see SyntaxTree
 */
class Node
{
public:

    /**
     * @brief Evaluates \a this and returns the result.
     */
    virtual Result eval() const = 0;

    /**
     * @brief Destroys the object.
     */
    virtual ~Node() { }
};

/**
 * @brief The FloatValue class provides a node with a floting point value
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
 * @brief The UnaryOp class provides the base class for all unary operators
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
 * @brief The BynaryOp class provides the base class for all binary operators
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
 * @brief The AddOp class provides the addition operator
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
 * @brief The SubsOp class provides the substraction operator
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
 * @brief The MultOp class provides multiplication operator
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
 * @brief The DivOp class provides the division operator
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
 * @brief The LogOp class provides the log operator
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

/**
 * @brief The ErrorNode class provides the base class for all error nodes
 */
class ErrorNode : public Node
{
public:

    /**
     * @brief This method always throws std::exception
     */
    virtual Result eval() const
    {
        throw std::exception();
    }
};

/**
 * @brief The SyntaxErrorNode class provides a node that means a syntactic error
 */
class SyntaxErrorNode : public ErrorNode
{
public:

    /**
     * @brief This method always throws InvalidSyntaxException
     */
    virtual Result eval() const
    {
        throw InvalidSyntaxException();
    }
};

/**
 * @brief The UnbalancedParErrorNode class provides a node that means unbalanced paragraph found
 */
class UnbalancedParErrorNode : public SyntaxErrorNode
{
public:

    /**
     * @brief This method always throws UnbalancedParException
     */
    virtual Result eval() const
    {
        throw UnbalancedParException();
    }
};


#endif // NODE_H
