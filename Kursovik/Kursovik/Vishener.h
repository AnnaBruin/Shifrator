#include <Windows.h>
#include <iostream>
#include <vector>
#include <string.h>
#define CIPHER 0
#define DECIPHER 1
#include "msclr\marshal_cppstd.h"
using namespace std;

char getNextChar(char c)
{
    string const RUS_ALPHABET = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
    int const RUS_ALPHABET_COUNT = RUS_ALPHABET.length();
    for (int i = 0; i < RUS_ALPHABET_COUNT; i++)
    {
        if (c == RUS_ALPHABET[i])
            return RUS_ALPHABET[(i + 1) % RUS_ALPHABET_COUNT];
    }
    return 'X';
}

char GetVisionerChar(char alpha, char beta, int mode)
{
    string const RUS_ALPHABET = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
    int const RUS_ALPHABET_COUNT = RUS_ALPHABET.length();
    int alphaInt = 0, betaInt = 0;
    for (int i = 0; i < RUS_ALPHABET_COUNT; i++)
    {
        if (RUS_ALPHABET[i] == alpha)
        {
            alphaInt = i;
            if (mode == DECIPHER)
                alphaInt = RUS_ALPHABET_COUNT - alphaInt;
        }
        if (RUS_ALPHABET[i] == beta)
            betaInt = i;
    }
    return RUS_ALPHABET[(alphaInt + betaInt) % RUS_ALPHABET_COUNT];
}

//Функция шифрования
string EncryptVishener(string str, string Key) {

    string alfavit = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
    string rezK = "                                                                                                                                                                                                                        ";
    int keyLength = Key.length();
    int count;
    string strCopy = str;

    //Удаление лишних символов из исходного ключа
    for (int i = 0; i < keyLength; i++)
    {
        count = 0;
        for (int j = 0; j < alfavit.length(); j++) {
            if (Key[i] == alfavit[j]) {
                count = 1;
            }
        }
        if (count == 0) {
            Key.erase(i, 1);
            i--;
            keyLength--;
        }
    }

    if (Key == "")
    {
        return "Oshibka";
    }
    else {

        //Удаление лишних символов из исходного текста
        int textLength = str.length();
        for (int i = 0; i < textLength; i++)
        {
            count = 0;
            for (int j = 0; j < alfavit.length(); j++) {
                if (str[i] == alfavit[j]) {
                    count = 1;
                }
            }
            if (count == 0) {
                str.erase(i, 1);
                i--;
                textLength--;
            }
        }

        //Прогрессирующий ключ
        int gap = Key.length(), max = gap - 1;
        int m = gap;
        for (int i = 0; i < Key.length(); i++) {
            rezK[i] = Key[i];
        }
        while (m < str.length())
        {
            rezK[m] = getNextChar(rezK[max - gap + 1]);
            max++;
            m++;
        }

        int chosenMode = CIPHER;
        for (int i = 0; i < str.length(); i++)
            str[i] = (GetVisionerChar(rezK[i], str[i], chosenMode));

        count = 0;
        for (int i = 0; i < strCopy.length(); i++)
        {
            for (int j = 0; j < alfavit.length(); j++)
                if (strCopy[i] == alfavit[j])
                {
                    strCopy[i] = str[count];
                    count++;
                    break;
                }
        }

        return strCopy;
    }
}

//Функция дешифрования
string DecodeVishener(string str, string Key) {
    string alfavit = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
    string rezK = "                                                                                                                                                                                                                        ";
    int keyLength = Key.length();
    int count;
    string strCopy = str;

    //Удаление лишних символов из исходного ключа
    for (int i = 0; i < keyLength; i++)
    {
        count = 0;
        for (int j = 0; j < alfavit.length(); j++) {
            if (Key[i] == alfavit[j]) {
                count = 1;
            }
        }
        if (count == 0) {
            Key.erase(i, 1);
            i--;
            keyLength--;
        }
    }

    if (Key == "")
    {
        return "Oshibka";
    }
    else {

        //Удаление лишних символов из исходного текста
        int textLength = str.length();
        for (int i = 0; i < textLength; i++)
        {
            count = 0;
            for (int j = 0; j < alfavit.length(); j++) {
                if (str[i] == alfavit[j]) {
                    count = 1;
                }
            }
            if (count == 0) {
                str.erase(i, 1);
                i--;
                textLength--;
            }
        }

        //Прогрессирующий ключ
        int gap = Key.length(), max = gap - 1;
        int m = gap;
        for (int i = 0; i < Key.length(); i++) {
            rezK[i] = Key[i];
        }
        while (m < str.length())
        {
            rezK[m] = getNextChar(rezK[max - gap + 1]);
            max++;
            m++;
        }

        int chosenMode = DECIPHER;
        for (int i = 0; i < str.length(); i++)
            str[i] = (GetVisionerChar(rezK[i], str[i], chosenMode));

        count = 0;
        for (int i = 0; i < strCopy.length(); i++)
        {
            for (int j = 0; j < alfavit.length(); j++)
                if (strCopy[i] == alfavit[j])
                {
                    strCopy[i] = str[count];
                    count++;
                    break;
                }
        }

        return strCopy;
    }
}
