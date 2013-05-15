#ifndef NODE_H
#define NODE_H

/**
 * @brief Result
 */
typedef double Result;

/**
 * @brief The Node class
 */
class Node
{
public:
    virtual Result eval() const = 0;

    virtual ~Node() { }
};

/**
 * @brief The NullValue class
 */
class NullValue : public Node
{
public:
    virtual Result eval() const
    {
        return 0;
    }
};

/**
 * @brief The FloatValue class
 */
class FloatValue : public Node
{
public:

    FloatValue(double value)
        : _value(value)
    { }

    virtual Result eval() const
    {
        return _value;
    }

private:
    double _value;
};

/**
 * @brief The UnaryOp class
 */
class UnaryOp : public Node
{
public:

    UnaryOp(Node *exp)
        : _exp(exp)
    { }

    virtual ~UnaryOp()
    {
        delete _exp;
    }

protected:
    Node *_exp;

private:
    UnaryOp(const UnaryOp &);
    UnaryOp & operator=(const UnaryOp &);
};

/**
 * @brief The BynaryOp class
 */
class BynaryOp : public Node
{
public:

    BynaryOp(Node *exp1, Node *exp2)
        : _exp1(exp1), _exp2(exp2)
    { }

    virtual ~BynaryOp()
    {
        delete _exp1;
        delete _exp2;
    }

protected:
    Node *_exp1;
    Node *_exp2;

private:
    BynaryOp(const BynaryOp &);
    BynaryOp & operator=(const BynaryOp &);
};

/**
 * @brief The AddOp class
 */
class AddOp : public BynaryOp
{
public:

    AddOp(Node *exp1, Node *exp2)
        : BynaryOp(exp1, exp2)
    { }

    virtual Result eval() const
    {
        return _exp1->eval() + _exp2->eval();
    }
};

#endif // NODE_H
