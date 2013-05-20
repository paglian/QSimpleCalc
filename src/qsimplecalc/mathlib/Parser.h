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

#ifndef PARSER_H
#define PARSER_H

#include <QString>
#include "Node.h"

/**
 * @brief The Parser class provides a parser for math expressions
 */
class Parser
{
public:

    /**
     * @brief Parses the string \a str and builds a syntax parse tree.
     *
     * The caller must free the node.
     *
     * @return If the expression is valid returns the root node of the parse tree.
     * Otherwise; throws InvalidSyntaxException
     *
     * @throw InvalidSyntaxException
     */
    Node * parse(const QString &str);
};

#endif // PARSER_H
