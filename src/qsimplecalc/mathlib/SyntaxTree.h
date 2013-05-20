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

#ifndef SYNTAXTREE_H
#define SYNTAXTREE_H

#include <QStringList>
#include "Node.h"

/**
 * @brief The SyntaxTree class provides a Syntax Parse Tree (SAT) for math expressions
 */
class SyntaxTree
{
public:

    /**
     * @brief Creates a SyntaxTree object.
     */
    SyntaxTree();

    /**
     * @brief Builds a syntax parse tree for the given \a tokens
     *
     * @return The root node of the tree.
     */
    Node *buildTree(const QStringList &tokens);

private:
    QList<QStringList> _operators;

    Node *buildTree(const QStringList &tokens, int start, int end);
    int findNextOp(const QStringList &tokens, int start, int end);
    int findNextOp(const QStringList &tokens, int start, int end, const QStringList &ops);
    Node *buildLinearEqTree(const QStringList &tokens, int eqPos);
    Node *getA(const QStringList &tokens, int start, int end, int xPos);
    Node *getB(const QStringList &tokens, int start, int end, int xPos);
    Node *getC(const QStringList &tokens, int start, int end);
};

#endif // SYNTAXTREE_H
