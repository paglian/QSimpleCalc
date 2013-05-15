#include "Tokenizer.h"
#include "StringConstants.h"

namespace
{

inline bool isToken(const QString &str, int i, const QString &token)
{
    int j = 0;
    for (; i < str.size() && j < token.size(); ++i, ++j) {
        if (str[i] != token[j]) {
            break;
        }
    }
    return j == token.size();
}

inline bool isDigit(const QString &str, int i)
{
    return str[i].isDigit();
}

inline bool isDot(const QString &str, int i)
{
    return isToken(str, i, STR_DOT);
}

} // namespace


Tokenizer::Tokenizer()
    : _lastToken(NullToken)
{
    _knownTokens.append(STR_ADD);
    _knownTokens.append(STR_SUBS);
    _knownTokens.append(STR_MULT);
    _knownTokens.append(STR_DIV);
    _knownTokens.append(STR_LOG);
    _knownTokens.append(STR_OPAR);
    _knownTokens.append(STR_CPAR);
    _knownTokens.append(STR_X);
    _knownTokens.append(STR_EQ);
}

bool Tokenizer::tokenize(const QString &str, QStringList &tokens)
{
    QString token;
    _lastToken = NullToken;

    int i = 0;
    bool err = false;

    while (i < str.size() && !err) {

        // just ignore spaces
        if (str[i].isSpace()) {
            ++i;
            continue;
        }

        token = "";

        if (getNumber(str, i, token)) {
            _lastToken = NumberToken;
        } else if (getKnownToken(str, i, token)){
            _lastToken = (token == STR_CPAR) ? CParToken : OtherToken;
        } else {
            // if unknown token, set token equal to the remaining string and set set error flag
            token = str.mid(i);
            _lastToken = OtherToken;
            err = true;
        }

        if (!token.isEmpty()) {
            tokens.append(token);
            i += token.size();
        }
    }

    return !err;
}

bool Tokenizer::getNumber(const QString &str, int i, QString &numb)
{
    // Examples of valid numbers are:
    // 1234
    // +1234
    // -1234
    // -1234.99
    // .99
    // +.99
    // -1234.

    numb.clear();

    bool first = true;
    bool dotFound = false;

    for (; i < str.size(); ++i) {
        if (first && isSign(str, i)) {
            numb.append(str[i]);
        } else if (isDigit(str, i)) {
            numb.append(str[i]);
        } else if (!dotFound && isDot(str, i)) {
            numb.append(str[i]);
            dotFound = true;
        } else {
            break;
        }

        first = false;
    }

    return numb.size() > 0;
}

bool Tokenizer::getKnownToken(const QString &str, int i, QString &token)
{
    foreach (QString t, _knownTokens) {
        if (isToken(str, i, t)) {
            token = t;
            return true;
        }
    }
    return false;
}

bool Tokenizer::isSign(const QString &str, int i)
{
    // Quite complex to disambiguates cases such as:
    // 2+2
    // 2++2 (i.e. 2 + +2)
    // +2

    if (isToken(str, i, STR_ADD) || isToken(str, i, STR_SUBS)) {
        if (i + 1 < str.size() && (isDigit(str, i + 1) || isDot(str, i + 1))) {
            if (_lastToken != NumberToken && _lastToken != CParToken) {
                return true;
            }
        }
    }
    return false;
}

