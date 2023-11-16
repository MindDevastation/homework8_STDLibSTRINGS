#ifndef ENCODING_H
#define ENCODING_H
#include <QString>
#include <string>


class Encoding
{
    std::string key = "aaaaabbbbbabbbaabbababbaaababaab";
    QString input;
    QString checkMessage = "Welcome to the Hotel California Such a lovely place Such a lovely place";
    QString *encodingArrInp = new QString [50];
    QString encondingOutput;
    QString decodingOutput;
public:
    Encoding();
    ~Encoding();

    QString getInput();
    void setInput(QString newInput);

    QString getCheckMessage();
    void setCheckMessage(QString newCheckMessage);

    void encode();
    void encodeClear();
    QString getEncode();
    void decode();
    void decodeClear();
    QString getDecode();
};;

#endif // ENCODING_H
