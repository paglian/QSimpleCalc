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
    void tokenize(const QString &str, QStringList &tokens);
};

#endif // TOKENIZER_H
