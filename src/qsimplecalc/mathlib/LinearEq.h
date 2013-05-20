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
 * @brief The VariableNode class
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
    LinearEq(Node *leftSide, Node *rightSide)
        : _ls(leftSide), _rs(rightSide)
    { }

    /**
     * @brief Destroys \a this and its child nodes
     */
    virtual ~LinearEq()
    {
        delete _ls;
        delete _rs;
    }

    /**
     * @brief Solves the linear equation and returns its value.
     *
     * @throw InvalidLinearEqException
     */
    virtual Result eval() const
    {
        if (hasVariable(_ls)) {
            if (hasVariable(_rs)) {
                throw InvalidLinearEqException(); // Both sides have variable
            } else {
                 return eval(_ls, _rs->eval());
            }
        } else if (hasVariable(_rs)) {
            return eval(_rs, _ls->eval());
        } else {
            throw InvalidLinearEqException(); // No variable found
        }
    }

private:

    LinearEq(const LinearEq &);
    LinearEq & operator=(const LinearEq &);

    Node *_ls;
    Node *_rs;

    bool hasVariable(const Node *n) const
    {
        // Trick not very performant:
        try {
            n->eval();
            return false;
        } catch (VariableEvalException &) {
            return true;
        } catch (MathException &) {
            throw InvalidLinearEqException();
        }
    }

    Result eval(const Node *varSide, const Result constSide) const
    {
        if (dynamic_cast<const VariableNode*>(varSide)) {
            return constSide;
        } else if (const BynaryOp * op = dynamic_cast<const BynaryOp *>(varSide)) {
            if (hasVariable(op->left()) && !hasVariable(op->right())) {
                return eval(op->left(), inverse(op, constSide, op->right()->eval()));
            } else if (hasVariable(op->right()) && !hasVariable(op->left())) {
                return eval(op->right(), inverse(op, constSide, op->left()->eval()));
            }
        }
        throw InvalidLinearEqException();
    }

    Result inverse(const BynaryOp *op, Result left, Result right) const
    {
        if (dynamic_cast<const AddOp *>(op)) {
            return left - right;
        }
        if (dynamic_cast<const SubsOp *>(op)) {
            return left + right;
        }
        if (dynamic_cast<const MultOp *>(op)) {
            return left / right;
        }
        if (dynamic_cast<const DivOp *>(op)) {
            return left * right;
        }
        throw InvalidLinearEqException();
    }
};


#endif // LINEAREQ_H
