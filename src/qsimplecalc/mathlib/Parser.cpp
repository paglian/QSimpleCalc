#include "Parser.h"
#include "Tokenizer.h"
#include "SyntaxTree.h"
#include "Exceptions.h"

#include <QObject>

Node *Parser::parse(const QString &str)
{
    QStringList tokens;
    if (Tokenizer().tokenize(str, tokens)) {
        SyntaxTree tree(tokens);

        return tree.root();
    } else {
        throw InvalidSyntaxException();
    }
}


