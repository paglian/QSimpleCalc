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

#ifndef NODE_H
#define NODE_H

#include <cmath>

#include "Exceptions.h"

/**
 * @brief The Result of evaluating a node
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

    /**
     * @brief Constructs a FloatValue object with \a value
     */
    FloatValue(double value)
        : _value(value)
    { }

    /**
     * @brief Returns the floating point value given at construction time
     */
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

    /**
     * @brief Constructs an abstract unary operator with operand \a a.
     *
     * After construction the object owns \a a.
     */
    UnaryOp(Node *a)
        : _a(a)
    { }

    /**
     * @brief Destroys \a this and its child nodes
     */
    virtual ~UnaryOp()
    {
        delete _a;
    }

protected:
    Node *_a;

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

    /**
     * @brief Constructs an abstract binary operator with operands \a a and \a b.
     *
     * After construction the object owns \a a and \a b.
     */
    BynaryOp(Node *a, Node *b)
        : _a(a), _b(b)
    { }

    /**
     * @brief Destroys \a this and its child nodes
     */
    virtual ~BynaryOp()
    {
        delete _a;
        delete _b;
    }

    /**
     * @brief Returns the left operand
     */
    const Node *left() const
    {
        return _a;
    }

    /**
     * @brief Returns the right operand
     */
    const Node *right() const
    {
        return _b;
    }

protected:
    Node *_a;
    Node *_b;

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

    /**
     * @brief Constructs an addition operator with operands \a a and \a b
     *
     * After construction the object owns \a a and \a b.
     */
    AddOp(Node *a, Node *b)
        : BynaryOp(a, b)
    { }

    /**
     * @brief Evaluates the addition of the nodes given at contruction time and returns its value
     */
    virtual Result eval() const
    {
        return _a->eval() + _b->eval();
    }
};


/**
 * @brief The SubsOp class provides the substraction operator
 */
class SubsOp : public BynaryOp
{
public:

    /**
     * @brief Constructs a substraction operator with operands \a a and \a b.
     *
     * After construction the object owns \a a and \a b.
     */
    SubsOp(Node *a, Node *b)
        : BynaryOp(a, b)
    { }

    /**
     * @brief Evaluates the substraction of the nodes given at contruction time and returns
     * its value
     */
    virtual Result eval() const
    {
        return _a->eval() - _b->eval();
    }
};


/**
 * @brief The MultOp class provides multiplication operator
 */
class MultOp : public BynaryOp
{
public:

    /**
     * @brief Constructs a BynaryOp object with operands \a a and \a b
     *
     * After construction the object owns \a a and \a b
     */
    MultOp(Node *a, Node *b)
        : BynaryOp(a, b)
    { }

    /**
     * @brief Evaluates the multiplication of the nodes given at contruction time and returns
     * its value
     */
    virtual Result eval() const
    {
        return _a->eval() * _b->eval();
    }
};


/**
 * @brief The DivOp class provides the division operator
 */
class DivOp : public BynaryOp
{
public:

    /**
     * @brief Constructs a division operator with operands \a a and \a b.
     *
     * After construction the object owns \a a and \a b
     */
    DivOp(Node *a, Node *b)
        : BynaryOp(a, b)
    { }

    /**
     * @brief Evaluates the division of the nodes given at contruction time and returns its value
     *
     * @throw DivByZeroException
     */
    virtual Result eval() const
    {
        Result d = _b->eval();
        if (d != 0) {
            return _a->eval() / d;
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

    /**
     * @brief Constructs a log operator with operand \a a.
     *
     * After construction the object owns \a a.
     */
    LogOp(Node *a)
        : UnaryOp(a)
    { }

    /**
     * @brief Evaluates the log of the node given at contruction time and returns its value
     *
     * @throw LogZeroException, LogNegativeException
     */
    virtual Result eval() const
    {
        Result d = _a->eval();
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
};


/**
 * @brief The SyntaxErrorNode class provides a node that means a syntactic error
 */
class SyntaxErrorNode : public ErrorNode
{
public:

    /**
     * @brief This method always throws InvalidSyntaxException
     *
     * @throw InvalidSyntaxException
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
     *
     * @throw UnbalancedParException
     */
    virtual Result eval() const
    {
        throw UnbalancedParException();
    }
};

#endif // NODE_H
