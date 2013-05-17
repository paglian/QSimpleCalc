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
    SyntaxTree(const QStringList &tokens);

    ~SyntaxTree();

    Node * root();

private:
    SyntaxTree(const SyntaxTree &);
    SyntaxTree & operator=(const SyntaxTree &);

    Node *_root;
    QStringList _ops1;
    QStringList _ops2;
    QStringList _ops3;

    Node *buildTree(const QStringList &tokens, int start, int end);

    int findNextOp(const QStringList &tokens, int start, int end, const QStringList &ops);
};

#endif // SYNTAXTREE_H
