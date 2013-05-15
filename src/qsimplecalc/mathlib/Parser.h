#ifndef PARSER_H
#define PARSER_H

#include <QString>
#include "Node.h"

/**
 * @brief The Parser class
 */
class Parser
{
public:
    Node * parse(const QString &str, QString *errMsg = 0);
};

#endif // PARSER_H
