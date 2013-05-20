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

#include "LinearEq.h"

LinearEq::LinearEq(Node *leftSide, Node *rightSide)
    : _ls(leftSide), _rs(rightSide)
{
}

LinearEq::~LinearEq()
{
    delete _ls;
    delete _rs;
}

Result LinearEq::eval() const
{
    if (hasVariable(_ls)) {
        if (hasVariable(_rs)) {
            throw InvalidSyntaxException(); // Both sides have variable
        } else {
             return eval(_ls, _rs->eval());
        }
    } else if (hasVariable(_rs)) {
        return eval(_rs, _ls->eval());
    } else {
        throw InvalidSyntaxException(); // No variable found
    }
}


bool LinearEq::hasVariable(const Node *n) const
{
    // Trick not very performant:
    try {
        n->eval();
        return false;
    } catch (VariableEvalException &) {
        return true;
    }
}

Result LinearEq::eval(const Node *varSide, const Result constSide) const
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
    throw InvalidSyntaxException();
}

Result LinearEq::inverse(const BynaryOp *op, Result left, Result right) const
{
    if (dynamic_cast<const AddOp *>(op)) {
        return left - right;
    }
    if (dynamic_cast<const SubsOp *>(op)) {
        return left + right;
    }
    if (dynamic_cast<const DivOp *>(op)) {
        return left * right;
    }
    if (dynamic_cast<const MultOp *>(op)) {
        if (right != 0) {
            return left / right;
        } else {
            throw DivByZeroException();
        }
    }
    throw InvalidSyntaxException();
}
