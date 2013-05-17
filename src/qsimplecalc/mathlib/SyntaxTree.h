#ifndef SYNTAXTREE_H
#define SYNTAXTREE_H

#include <QStringList>
#include "Node.h"

/**
 * @brief The SyntaxTree class
 */
class SyntaxTree
{
public:
    SyntaxTree();

    Node *buildTree(const QStringList &tokens);

private:
    SyntaxTree(const SyntaxTree &);
    SyntaxTree & operator=(const SyntaxTree &);

    Node *_root;
    QList<QStringList> _operators;

    Node *buildTree(const QStringList &tokens, int start, int end);
    int findNextOp(const QStringList &tokens, int start, int end);
    int findNextOp(const QStringList &tokens, int start, int end, const QStringList &ops);
};

#endif // SYNTAXTREE_H
