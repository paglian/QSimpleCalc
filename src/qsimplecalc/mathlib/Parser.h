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
     * @brief parses the string \a str and builds a syntax parse tree.
     *
     * The caller must free the node.
     *
     * @return If the expression is valid returns the root node of the parse tree.
     * Otherwise; throws a MathException.
     *
     * @see MathException derived classes to get the list of possible errors
     */
    Node * parse(const QString &str);
};

#endif // PARSER_H
