#include "Parser.h"
#include "Tokenizer.h"
#include "SyntaxTree.h"

Node *Parser::parse(const QString &str)
{
    QStringList tokens;
    Tokenizer().tokenize(str, tokens);

    SyntaxTree tree(tokens);

    return tree.root();
}


