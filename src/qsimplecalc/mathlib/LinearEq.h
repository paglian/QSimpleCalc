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

#ifndef LINEAREQ_H
#define LINEAREQ_H

#include "Node.h"

/**
 * @brief The VariableNode class provides a variable
 */
class VariableNode : public Node
{
public:

    /**
     * @brief This method always throws VariableEvalException
     */
    virtual Result eval() const
    {
        throw VariableEvalException();
    }
};


/**
 * @brief The LinearEq class provides a linear equation
 */
class LinearEq : public Node
{
public:

    /**
     * @brief Constructs a linear equation \a leftSide = \a rightSide
     *
     * After construction the object owns \a leftSide and \a rightSide
     */
    LinearEq(Node *leftSide, Node *rightSide);

    /**
     * @brief Destroys \a this and its child nodes
     */
    virtual ~LinearEq();

    /**
     * @brief Solves the linear equation and returns its value.
     *
     * @throw InvalidSyntaxException, VariableEvalException
     */
    virtual Result eval() const;

private:

    LinearEq(const LinearEq &);
    LinearEq & operator=(const LinearEq &);

    Node *_ls;
    Node *_rs;

    bool hasVariable(const Node *n) const;
    Result eval(const Node *varSide, const Result constSide) const;
    Result inverse(const BynaryOp *op, Result left, Result right) const;
};


#endif // LINEAREQ_H
