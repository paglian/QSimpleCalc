#include "QSimpleCalc.h"
#include "mathlib/Parser.h"

#include <memory>

double QSimpleCalc::eval(const QString &strExp)
{
    std::auto_ptr<Node> node(Parser().parse(strExp));

    if (node.get()) {
        return node->eval();
    } else {
        return 0;
    }
}
