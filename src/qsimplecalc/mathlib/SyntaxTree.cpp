#include "SyntaxTree.h"

SyntaxTree::SyntaxTree(const QStringList &/*tokens*/)
    : _root(0)
{
    // TODO
}

SyntaxTree::~SyntaxTree()
{
    delete _root;
}

Node *SyntaxTree::root()
{
    return new NullValue();
}
