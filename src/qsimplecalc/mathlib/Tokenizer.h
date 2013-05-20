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

#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <QString>
#include <QStringList>

/**
 * @brief The Tokenizer provides a tokenizer for math expressions
 *
 * Example:
 *
 * \code{.cpp}
 * Tokenizer().tokenize("(2 + 2) * 3"); // Returns [ "(", "2", "+", "2", ")", "*", "3", ")" ]
 * \endcode
 */
class Tokenizer
{
public:

    /**
     * @brief Constructs a Tokenizer object.
     */
    Tokenizer();

    /**
     * @brief Tokenizes the string \a str and returns the list of \a tokens
     *
     * @return Returns true on success and initializes \a tokens. Otherwise; returns false.
     */
    bool tokenize(const QString &str, QStringList &tokens);

private:

    enum TokenType { NullToken, NumberToken, CParToken, OtherToken };

    TokenType _lastToken;
    QStringList _knownTokens;

    bool getNumber(const QString &str, int i, QString &numb);
    bool getKnownToken(const QString &str, int i, QString &token);
    bool isSign(const QString &str, int i);
};

#endif // TOKENIZER_H
