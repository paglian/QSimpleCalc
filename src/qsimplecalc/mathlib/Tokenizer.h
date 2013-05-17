#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <QString>
#include <QStringList>

/**
 * @brief The Tokenizer provides a tokenizer for math expressions
 *
 * Example: Tokenizer().tokenize("(2 + 2) * 3"); // Returns [ "(", "2", "+", "2", ")", "*", "3", ")" ]
 */
class Tokenizer
{
public:

    /**
     * @brief Constructs a Tokenizer object.
     */
    Tokenizer();


    /**
     * @brief Tokenizes the string \a str and returns the list of \a tokens
     *
     * @return Returns true on success and initializes \a tokens. Otherwise; returns false.
     */
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
