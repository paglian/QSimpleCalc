#include "SyntaxTree.h"
#include "StringConstants.h"
#include "Exceptions.h"

SyntaxTree::SyntaxTree(const QStringList &tokens)
    : _root(0)
{
    // Operators with precedence 1
    _ops1 = QStringList() << STR_ADD << STR_SUBS;
    // Operators with precedence 2
    _ops2 = QStringList() << STR_DIV << STR_MULT;
    // Operators with precedence 3
    _ops3 = QStringList() << STR_LOG;

    _root = buildTree(tokens, 0, tokens.size() - 1);
}

SyntaxTree::~SyntaxTree()
{
}

Node *SyntaxTree::root()
{
    return _root;
}

Node * SyntaxTree::buildTree(const QStringList &tokens, int start, int end)
{
    if (start < 0 || end >= tokens.size() || start > end) {
        throw InvalidSyntaxException();
    }

    if (start == end) {
        // If we found a leaf, it must be a float number
        bool ok = false;
        double d = tokens[start].toDouble(&ok);
        if (ok) {
            return new FloatValue(d);
        }
    } else {
        // Find next operator according to the operator precedence and parentheses
        int i = -1;

        i = findNextOp(tokens, start, end, _ops1);
        if (i != -1) {
            if (tokens[i] == STR_ADD) {
                return new AddOp(buildTree(tokens, start, i - 1), buildTree(tokens, i + 1, end));
            } else if (tokens[i] == STR_SUBS) {
                return new SubsOp(buildTree(tokens, start, i - 1), buildTree(tokens, i + 1, end));
            }
        }

        i = findNextOp(tokens, start, end, _ops2);
        if (i != -1) {
            if (tokens[i] == STR_MULT) {
                return new MultOp(buildTree(tokens, start, i - 1), buildTree(tokens, i + 1, end));
            } else if (tokens[i] == STR_DIV) {
                return new DivOp(buildTree(tokens, start, i - 1), buildTree(tokens, i + 1, end));
            }
        }

        i = findNextOp(tokens, start, end, _ops3);
        if (i != -1) {
            if (tokens[i] == STR_LOG && i == start) {
                return new LogOp(buildTree(tokens, i + 1, end));
            }
        }

        // If surrounded by parentheses, remove them and continue
        if (tokens[start] == STR_OPAR && tokens[end] == STR_CPAR) {
            return buildTree(tokens, start + 1, end - 1);
        }
    }

    throw InvalidSyntaxException();
}

int SyntaxTree::findNextOp(const QStringList &tokens, int start, int end, const QStringList &ops)
{
    int next = -1;
    int cpars = 0;

    // All operators are right-associative, so we start searching tokens from the end
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
