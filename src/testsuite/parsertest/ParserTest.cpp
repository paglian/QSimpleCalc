#include <QString>
#include <QtTest>

#include "mathlib/Parser.h"
#include "mathlib/Exceptions.h"

class ParserTest : public QObject
{
    Q_OBJECT
    
private Q_SLOTS:
    void testWellFormed();
    void testWellFormed_data();

    void testIllFormed();
    void testIllFormed_data();

    void testUnbalancedPar();
    void testUnbalancedPar_data();
};

void ParserTest::testWellFormed()
{
    QFETCH(QString, exp);
    QFETCH(double, result);

    try {
        QCOMPARE(Parser().parse(exp)->eval(), result);
    } catch (MathException &) {
        QFAIL("MathException");
    }
}

void ParserTest::testWellFormed_data()
{
    QTest::addColumn<QString>("exp");
    QTest::addColumn<double>("result");

    QTest::newRow("0")   << QString("-123.4")
                         << double(-123.4);

    QTest::newRow("1")   << QString("2+2")
                         << double(4);

    QTest::newRow("2")   << QString(" 2  -  +3  ")
                         << double(-1);

    QTest::newRow("2.1") << QString("2 - +2/3")
                         << double(2 - 2/double(3));

    QTest::newRow("2.2") << QString("-2/3 + 2")
                         << double(-2/double(3) + 2);

    QTest::newRow("4.0") << QString("(((2.5 - 2*3)))")
                         << double(-3.5);

    QTest::newRow("4.1") << QString("(2.5 - 2) * -3")
                         << double((2.5 - 2) * -3);

    QTest::newRow("4.2") << QString("(2.5 - 2) * ((-3 + 0.33)) / (1.1)")
                         << double((2.5 - 2) * (-3 + 0.33) / 1.1);

    QTest::newRow("4.3") << QString("(2) + (2)")
                         << double(4);

    QTest::newRow("5")   << QString("(2.5 - 2) * log 1000 * log 100 + 0.222")
                         << double(3.222);

    QTest::newRow("5.1") << QString("log (50 + 50)")
                         << double(2);

    QTest::newRow("7")   << QString("99.9/30/3/5.1 + 1 - 1")
                         << double(99.9/30/3/double(5.1) + 1 - 1);
}

void ParserTest::testIllFormed()
{
    QFETCH(QString, exp);

    try {
        Parser().parse(exp)->eval();
        QFAIL("InvalidSyntaxException not thrown");
    } catch (InvalidSyntaxException &) {
    }
}

void ParserTest::testIllFormed_data()
{
    QTest::addColumn<QString>("exp");

    QTest::newRow("0") << QString("");
    QTest::newRow("1") << QString("2+");
    QTest::newRow("2") << QString("*2");
    QTest::newRow("3") << QString("9%3");
    QTest::newRow("4") << QString("sin 4");
    QTest::newRow("5") << QString("((2+2)*sin 4)");
    QTest::newRow("6") << QString("log");
    QTest::newRow("7") << QString("2 log 10");
}

void ParserTest::testUnbalancedPar()
{
    QFETCH(QString, exp);
    QFETCH(bool, unbalanced);

    try {
        Parser().parse(exp)->eval();
        QVERIFY(!unbalanced);
    } catch (UnbalancedParException &) {
        QVERIFY(unbalanced);
    }
}

void ParserTest::testUnbalancedPar_data()
{
    QTest::addColumn<QString>("exp");
    QTest::addColumn<bool>("unbalanced");

    QTest::newRow("0")   << QString("(2)")
                         << false;

    QTest::newRow("1")   << QString("(2+(2))")
                         << false;

    QTest::newRow("2")   << QString("((2+2)*(3*(2+2)*(3))/9)")
                         << false;

    QTest::newRow("3")   << QString("((2+2)*3")
                         << true;

    QTest::newRow("4")   << QString("(2+2)*3)")
                         << true;

    QTest::newRow("5")   << QString("((2+2)*(3*2+2)*(3)))")
                         << true;

}

QTEST_APPLESS_MAIN(ParserTest)

#include "ParserTest.moc"
