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
};

#endif // SYNTAXTREE_H
