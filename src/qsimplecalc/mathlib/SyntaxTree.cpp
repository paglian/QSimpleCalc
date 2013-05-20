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

#include "SyntaxTree.h"
#include "StringConstants.h"
#include "Exceptions.h"
#include "LinearEq.h"

SyntaxTree::SyntaxTree()
{
    _operators.append(QStringList() << STR_EQ);                 // Operators with precedence 1
    _operators.append(QStringList() << STR_ADD << STR_SUBS);    // Operators with precedence 2
    _operators.append(QStringList() << STR_DIV << STR_MULT);    // Operators with precedence 3
    _operators.append(QStringList() << STR_LOG);                // Operators with precedence 4
}

Node * SyntaxTree::buildTree(const QStringList &tokens)
{
    return buildTree(tokens, 0, tokens.size() - 1);
}

Node * SyntaxTree::buildTree(const QStringList &tokens, int start, int end)
{
    if (start < 0 || end >= tokens.size() || start > end) {
        return new SyntaxErrorNode();
    }

    if (start == end) {
        // If we found a leaf, it must be a variable or a floating point number

        if (tokens[start] == STR_X) {
            return new VariableNode();
        } else {
            bool ok = false;
            double d = tokens[start].toDouble(&ok);
            if (ok) {
                return new FloatValue(d);
            }
        }
    } else {
        // If not a leaf, find next operator according to the operator precedence and parentheses

        int i = -1;

        try {
            i = findNextOp(tokens, start, end);
        } catch (UnbalancedParException) {
            return new UnbalancedParErrorNode();
        }

        if (i != -1) {
            if (tokens[i] == STR_ADD) {
                return new AddOp(buildTree(tokens, start, i - 1), buildTree(tokens, i + 1, end));
            }
            if (tokens[i] == STR_SUBS) {
                return new SubsOp(buildTree(tokens, start, i - 1), buildTree(tokens, i + 1, end));
            }
            if (tokens[i] == STR_MULT) {
                return new MultOp(buildTree(tokens, start, i - 1), buildTree(tokens, i + 1, end));
            }
            if (tokens[i] == STR_DIV) {
                return new DivOp(buildTree(tokens, start, i - 1), buildTree(tokens, i + 1, end));
            }
            if (tokens[i] == STR_LOG && i == start) {
                return new LogOp(buildTree(tokens, i + 1, end));
            }
            if (tokens[i] == STR_EQ && start == 0 && end == tokens.size() - 1) {
                return new LinearEq(buildTree(tokens, start, i - 1), buildTree(tokens, i + 1, end));
            }
        }

        // If surrounded by parentheses, remove them and continue
        if (tokens[start] == STR_OPAR && tokens[end] == STR_CPAR) {
            return buildTree(tokens, start + 1, end - 1);
        }
    }

    return new SyntaxErrorNode();
}

int SyntaxTree::findNextOp(const QStringList &tokens, int start, int end)
{
    for (int i = 0; i < _operators.size(); ++i) {
        int next = findNextOp(tokens, start, end, _operators[i]);
        if (next != -1) {
            return next;
        }
    }
    return -1;
}

int SyntaxTree::findNextOp(const QStringList &tokens, int start, int end, const QStringList &ops)
{
    int next = -1;
    int cpars = 0;

    // Left-to-right associativity
    for (int i = end; i >= start; --i) {
        const QString &token = tokens[i];

        if (token == STR_CPAR) {
            ++cpars;
        } else if (token == STR_OPAR) {
            --cpars;
            if (cpars < 0) {
                throw UnbalancedParException();
            }
        }

        // if next operator not found and we are not inside parentheses
        if (next == -1 && cpars == 0) {
            if (ops.contains(token)) {
                next = i;
            }
        }
    }

    if (cpars > 0) {
        throw UnbalancedParException();
    }

    return next;
}

