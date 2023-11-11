#ifndef ENCODING_H
#define ENCODING_H
#include <QString>


class Encoding
{
    std::string key = "aaaaabbbbbabbbaabbababbaaababaab";
    QString input;
    QString checkMessage = "Welcome to the Hotel California Such a lovely place Such a lovely place";
public:
    Encoding();

    QString encodingArrInp [10];
    QString encondingOutput;
    QString decodingOutput;

    QString getInput();
    void setInput(QString newInput);

    QString getCheckMessage();
    void setCheckMessage(QString newCheckMessage);

    void encode();
    void decode();
};;

#endif // ENCODING_H
