#include <QString>
#include <QtTest>

#include "backend/QSimpleCalc.h"

class BackendTest : public QObject
{
    Q_OBJECT
    
private Q_SLOTS:
    void testCase1();
    void testCase1_data();
};

void BackendTest::testCase1()
{
    QFETCH(QString, exp);
    QFETCH(double, result);

    QCOMPARE(QSimpleCalc().eval(exp), result);
}

void BackendTest::testCase1_data()
{
    QTest::addColumn<QString>("exp");
    QTest::addColumn<double>("result");
    QTest::newRow("0") << QString("2+2") << double(4);
}

QTEST_APPLESS_MAIN(BackendTest)

#include "BackendTest.moc"
