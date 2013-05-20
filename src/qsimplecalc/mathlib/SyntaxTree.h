#ifndef SYNTAXTREE_H
#define SYNTAXTREE_H

#include <QStringList>
#include "Node.h"

/**
 * @brief The SyntaxTree class provides a Syntax Parse Tree (SAT) for math expressions
 */
class SyntaxTree
{
public:

    /**
     * @brief Creates a SyntaxTree object.
     */
    SyntaxTree();

    /**
     * @brief Builds a syntax parse tree for the given \a tokens
     *
     * @return The root node of the tree.
     */
    Node *buildTree(const QStringList &tokens);

private:
    QList<QStringList> _operators;

    Node *buildTree(const QStringList &tokens, int start, int end);
    int findNextOp(const QStringList &tokens, int start, int end);
    int findNextOp(const QStringList &tokens, int start, int end, const QStringList &ops);
    Node *buildLinearEqTree(const QStringList &tokens, int eqPos);
    Node *getA(const QStringList &tokens, int start, int end, int xPos);
    Node *getB(const QStringList &tokens, int start, int end, int xPos);
    Node *getC(const QStringList &tokens, int start, int end);
};

#endif // SYNTAXTREE_H
