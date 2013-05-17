#include "SyntaxTree.h"
#include "StringConstants.h"
#include "Exceptions.h"

SyntaxTree::SyntaxTree(const QStringList &tokens)
    : _root(0)
{
    _root = buildTree(tokens, 0, tokens.size() - 1);
}

SyntaxTree::~SyntaxTree()
{
    //delete _root;
}

Node *SyntaxTree::root()
{
    return _root;
}

Node * SyntaxTree::buildTree(const QStringList &tokens, int start, int end)
{
    if (start < 0 || end >= tokens.size()) {
        throw InvalidSyntaxException();
    }

    // Remove parenthesis
    if (tokens[start] == STR_OPAR && tokens[end] == STR_CPAR) {
        return buildTree(tokens, start + 1, end - 1);
    }

    //
    if (start == end) {
        bool ok = false;
        double d = tokens[start].toDouble(&ok);
        if (ok) {
            return new FloatValue(d);
        }
    } else {
        //
        for (int i = end; i >= start; --i) {
            if (tokens[i] == STR_ADD) {
                return new AddOp(buildTree(tokens, start, i - 1), buildTree(tokens, i + 1, end));
            } else if (tokens[i] == STR_SUBS) {
                return new SubsOp(buildTree(tokens, start, i - 1), buildTree(tokens, i + 1, end));
            }
        }

        //
        for (int i = end; i >= start; --i) {
            if (tokens[i] == STR_MULT) {
                return new MultOp(buildTree(tokens, start, i - 1), buildTree(tokens, i + 1, end));
            } else if (tokens[i] == STR_DIV) {
                return new DivOp(buildTree(tokens, start, i - 1), buildTree(tokens, i + 1, end));
            }
        }
    }

    throw InvalidSyntaxException();
}
