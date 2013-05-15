#include <QString>
#include <QStringList>
#include <QtTest>

#include "mathlib/Tokenizer.h"

class TokenizerTest : public QObject
{
    Q_OBJECT
    
private Q_SLOTS:
    void testCase1();
    void testCase1_data();
};

void TokenizerTest::testCase1()
{
    QFETCH(QString, str);
    QFETCH(QStringList, expectedTokens);

    QStringList tokens;
    Tokenizer().tokenize(str, tokens);

    QCOMPARE(tokens, expectedTokens);
}

void TokenizerTest::testCase1_data()
{
    QTest::addColumn<QString>("str");
    QTest::addColumn<QStringList>("expectedTokens");

    QTest::newRow("0.0") << QString("")
                         << QStringList();

    QTest::newRow("0.1") << QString("   ")
                         << QStringList();

    QTest::newRow("1.0") << QString("1234")
                         << (QStringList() << "1234");

    QTest::newRow("1.1") << QString("-1234")
                         << (QStringList() << "-1234");

    QTest::newRow("1.2") << QString("+22.3")
                         << (QStringList() << "+22.3");

    QTest::newRow("2.1") << QString("2+2")
                         << (QStringList() << "2" << "+" << "2");

    QTest::newRow("2.2") << QString("2 + 2/3")
                         << (QStringList() << "2" << "+" << "2" << "/" << "3");

    QTest::newRow("2.3") << QString("2.5 - +2 / 3 * 100.3")
                         << (QStringList() << "2.5" << "-" << "+2" << "/" << "3" << "*" << "100.3");

    QTest::newRow("3.1") << QString("log 2")
                         << (QStringList() << "log" << "2");

    QTest::newRow("3.1") << QString("log 2 + 3.0001")
                         << (QStringList() << "log" << "2" << "+" << "3.0001");

    QTest::newRow("4.1") << QString("2*x=3.2")
                         << (QStringList() << "2" << "*" << "x" << "=" << "3.2");

    QTest::newRow("4.2") << QString("2 * x + 0.5 = 3.2")
                         << (QStringList() << "2" << "*" << "x" << "+" << "0.5" << "=" << "3.2");

}

QTEST_APPLESS_MAIN(TokenizerTest)

#include "TokenizertestTest.moc"
