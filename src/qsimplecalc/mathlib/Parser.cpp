#include "Parser.h"
#include "Tokenizer.h"
#include "SyntaxTree.h"

#include <QObject>

Node *Parser::parse(const QString &str, QString *errMsg)
{
    QStringList tokens;
    if (Tokenizer().tokenize(str, tokens)) {
        SyntaxTree tree(tokens);

        return tree.root();
    } else {
        if (errMsg) {
            if (tokens.size() > 0) {
                *errMsg = QObject::tr("Invalid expression '%1'").arg(tokens.last());
            } else {
                *errMsg = QObject::tr("Invalid expression");
            }
        }

        return 0;
    }
}


