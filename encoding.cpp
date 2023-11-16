#include "encoding.h"
#include <QString>

Encoding::Encoding()
{

}

Encoding::~Encoding(){
    delete[] encodingArrInp;
}

void Encoding::encode(){
    std::string input = this->input.toStdString();
    std::string encondingOutputStr;
    std::string one;
    int length = input.length();
    std::string encodingArr [length];
    encodingArrInp->resize(length);
    int id = 0;
    for(int i = 0; i < length; i++){
        if(input[i] >= 65 && input[i] <= 92){
           id = static_cast <int>(input[i]) - 65;
        }else {
           id = static_cast <int>(input[i]) - 97;
        }
        encodingArr[i] = key.substr(id , 5);
        encodingArrInp[i] = QString::fromStdString(encodingArr[i]);
        encondingOutputStr.append(encodingArr[i]);
    }

    encondingOutput = QString::fromStdString(encondingOutputStr);

    QString newCheckMessage;
    newCheckMessage.append(checkMessage);
    erase(newCheckMessage, ' ');
    newCheckMessage.resize(encondingOutputStr.length());
    std::string newCheckMessageStr = newCheckMessage.toStdString();



    for(int i = 0; i < newCheckMessage.length(); i++){
        if(encondingOutput[i] != 'a'){
            newCheckMessageStr[i] = tolower(newCheckMessageStr[i]);

        }else if(encondingOutput[i] == 'a'){
            newCheckMessageStr[i] = toupper(newCheckMessageStr[i]);
        }
    }

    int space = 0;
    std::string checkMessageStr = checkMessage.toStdString();
    newCheckMessageStr.resize(checkMessageStr.length());
    for( ; ; ){
        space = checkMessageStr.find(' ', space);
        if (space != std::string::npos){
            newCheckMessageStr.insert(space, " ");
            space++;
        }else{
            break;
        }
    }


     encondingOutput = QString::fromStdString(newCheckMessageStr);
}

QString Encoding::getInput(){return input;}
void Encoding::setInput(QString newInput){input = newInput;}

QString Encoding::getCheckMessage(){return checkMessage;}
void Encoding::setCheckMessage(QString newCheckMessage){checkMessage = newCheckMessage;}

void Encoding::decode(){
    decodingOutput.append(encondingOutput);
    erase(decodingOutput, ' ');

    std::string decodingOutputStr = decodingOutput.toStdString();
    for(int i = 0; i < decodingOutput.length(); i++){
        if(decodingOutputStr[i] >= 97 && decodingOutputStr[i] <= 122){
            decodingOutputStr[i] = 'b';
        }else if (decodingOutputStr[i] >= 65 && decodingOutputStr[i] <= 92){
            decodingOutputStr[i] = 'a';
        }else{
            decodingOutputStr[i] = ' ';
        }
    }

    int sp = 0;
    for (int i = 0; i < decodingOutputStr.length(); i++){
        if (decodingOutputStr[i] != ' '){
            sp++;
        }
    }
    decodingOutputStr.resize(sp);

    int decodeArrLength = decodingOutputStr.length() / 5;
    std::string *decodeArr = new std::string [decodeArrLength];

    std::string decodePart;
    std::string decodingMessage;
    int id = 0;
    for(int i = 0; i < decodingOutputStr.length(); i+=5){
        decodePart = decodingOutputStr.substr(i, 5);
        decodeArr[id] = key.find(decodePart) + 97;
        id++;
    }

    for(int i = 0; i < id ; i ++){
        decodingMessage.append(decodeArr[i]);
    }

    decodingOutput = QString::fromStdString(decodingMessage);
}

void Encoding::encodeClear(){encondingOutput.clear();}

void Encoding::decodeClear(){decodingOutput.clear();}

QString Encoding::getDecode(){return decodingOutput;}

QString Encoding::getEncode(){return encondingOutput;}
