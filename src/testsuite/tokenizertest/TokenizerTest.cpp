/*
 * Copyright (C) 2013 Andres Pagliano.
 *
 * This file is part of QSimpleCalc.
 *
 * QSimpleCalc is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * QSimpleCalc is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with QSimpleCalc.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

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
    QFETCH(bool, success);
    QFETCH(QString, str);
    QFETCH(QStringList, expectedTokens);

    QStringList tokens;
    QCOMPARE(Tokenizer().tokenize(str, tokens), success);
    QCOMPARE(tokens, expectedTokens);
}

void TokenizerTest::testCase1_data()
{
    QTest::addColumn<bool>("success");
    QTest::addColumn<QString>("str");
    QTest::addColumn<QStringList>("expectedTokens");

    QTest::newRow("0.0") << true
                         << QString("")
                         << QStringList();

    QTest::newRow("0.1") << true
                         << QString("   ")
                         << QStringList();

    QTest::newRow("1.0") << true
                         << QString("1234567890")
                         << (QStringList() << "1234567890");

    QTest::newRow("1.1") << true
                         << QString("-1234")
                         << (QStringList() << "-1234");

    QTest::newRow("1.2") << true
                         << QString("+22.3")
                         << (QStringList() << "+22.3");

    QTest::newRow("2.1") << true
                         << QString("2+2")
                         << (QStringList() << "2" << "+" << "2");

    QTest::newRow("2.2") << true
                         << QString("  2 + -2/3  ")
                         << (QStringList() << "2" << "+" << "-2" << "/" << "3");

    QTest::newRow("2.3") << true
                         << QString("122.5 - +92 / (3 * 100.3)")
                         << (QStringList() << "122.5" << "-" << "+92" << "/" << "("
                             << "3" << "*" << "100.3" << ")");

    QTest::newRow("3.1") << true
                         << QString("log .2")
                         << (QStringList() << "log " << ".2");

    QTest::newRow("3.1") << true
                         << QString("log ( 0.2 + 3.0001 )")
                         << (QStringList() << "log " << "(" << "0.2" << "+" << "3.0001" << ")");

    QTest::newRow("4.1") << true
                         << QString("2*x=3.2")
                         << (QStringList() << "2" << "*" << "x" << "=" << "3.2");

    QTest::newRow("4.2") << true
                         << QString("2 * x + 0.5 = 3.2222222")
                         << (QStringList() << "2" << "*" << "x" << "+" << "0.5" << "="
                             << "3.2222222");

    QTest::newRow("4.3") << true
                         << QString("0.5 + x * 2 = 44444444442233.2222222")
                         << (QStringList() << "0.5" << "+" << "x" << "*" << "2" << "="
                             << "44444444442233.2222222");

    QTest::newRow("e1")  << false
                         << QString("!")
                         << (QStringList() << "!");

    QTest::newRow("e2")  << false
                         << QString("32 % 2")
                         << (QStringList() << "32" << "% 2");

    QTest::newRow("e3")  << false
                         << QString("2 + sin .2")
                         << (QStringList() << "2" << "+" << "sin .2");
}

QTEST_APPLESS_MAIN(TokenizerTest)

#include "TokenizerTest.moc"
