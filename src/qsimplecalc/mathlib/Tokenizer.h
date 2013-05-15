#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <QString>
#include <QStringList>

/**
 * @brief The Tokenizer class
 */
class Tokenizer
{
public:
    Tokenizer();

    bool tokenize(const QString &str, QStringList &tokens);

private:

    enum TokenType
    {
        NullToken,
        NumberToken,
        CParToken,
        OtherToken
    };

    TokenType _lastToken;
    QStringList _knownTokens;

    bool getNumber(const QString &str, int i, QString &numb);
    bool getKnownToken(const QString &str, int i, QString &token);
    bool isSign(const QString &str, int i);
};

#endif // TOKENIZER_H
