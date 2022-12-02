#include <Windows.h>
#include <iostream>
#include <vector>
#include <string.h>
#include "msclr\marshal_cppstd.h"
using namespace std;

//������� ����������
string EncryptZabor(string str, string key)
{
    string digits = "0123456789";
    std::string key_d = "";

    const int stroki = 100;
    const int shirina = 100;
    string alfavit = "�����Ũ����������������������������������������������������������";
    char arr[stroki][shirina];
    int n = 0; //���-�� �����
    int m = 0; //���-�� ��������
    int count = 0;

    //������ ����� �� �����
    for (int i = 0; i < key.length(); i++) {
        if (i == 0) {
            for (int j = 1; j < digits.length(); j++) {
                if (key[i] == digits[j]) {
                    key_d += key[i];
                }
            }
        }
        else {
            for (int j = 0; j < digits.length(); j++) {
                if (key[i] == digits[j]) {
                    key_d += key[i];
                }
            }
        }
    }
    if (key_d == "")
    {
        return "Oshibka";
    }
    else {
        int Key = stoi(key_d); //����������� ����� � �����

        string strCopy = str;

        //�������� ������ �������� �� ��������� ������
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

        if (str.length() > Key || Key != 1) {

            //���������� ������� ���������
            for (int i = 0; i < 100; i++) {
                for (int j = 0; j < 100; j++) {
                    arr[i][j] = ' ';
                }
            }

            //���������� ������� �������
            count = 1;
            for (int m = 0; m < str.length(); m++) {
                arr[n][m] = str[m];
                n += count;
                if (n == (Key - 1) || (n == 0)) {
                    count *= -1;
                }
            }

            textLength = strCopy.length();
            int strLength = str.length();

            count = 0;
            for (int i = 0; i < Key; i++)
                for (int j = 0; j < strLength; j++)
                    if (arr[i][j] != ' ')
                    {
                        str[count] = arr[i][j];
                        count++;
                    }

            count = 0;
            for (int i = 0; i < textLength; i++)
            {
                for (int j = 0; j < alfavit.length(); j++)
                    if (strCopy[i] == alfavit[j])
                    {
                        strCopy[i] = str[count];
                        count++;
                        break;
                    }
            }
        }

        return strCopy;
    }
}

//������� ������������
string DecodeZabor(string str, string key)
{
    string digits = "0123456789";
    std::string key_d = "";

    const int stroki = 100;
    const int shirina = 100;
    string alfavit = "�����Ũ����������������������������������������������������������";
    char arr[stroki][shirina];
    int n = 0; //���-�� �����
    int m = 0; //���-�� ��������
    int count = 0;

    //������ ����� �� �����
    for (int i = 0; i < key.length(); i++) {
        if (i == 0) {
            for (int j = 1; j < digits.length(); j++) {
                if (key[i] == digits[j]) {
                    key_d += key[i];
                }
            }
        }
        else {
            for (int j = 0; j < digits.length(); j++) {
                if (key[i] == digits[j]) {
                    key_d += key[i];
                }
            }
        }
    }

    if (key_d == "")
    {
        return "Oshibka";
    }
    else {
        int Key = stoi(key_d); //����������� ����� � �����

        string strCopy = str;

        //�������� ������ �������� �� ��������� ������
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

        if (str.length() > Key || Key != 1) {

            //���������� ������� ���������
            for (int i = 0; i < 100; i++) {
                for (int j = 0; j < 100; j++) {
                    arr[i][j] = ' ';
                }
            }

            //��������� ����� ��� �������� �����������
            count = 1;
            n = 0;
            for (int m = 0; m < str.length(); m++) {
                arr[n][m] = 'F';
                n += count;
                if (n == (Key - 1) || (n == 0)) {
                    count *= -1;
                }
            }

            textLength = strCopy.length();
            int strLength = str.length();

            //��������� ������� ������������
            count = 0;
            for (int i = 0; i < Key; i++) {
                for (int j = 0; j < strLength; j++)
                    if (arr[i][j] == 'F')
                    {
                        arr[i][j] = str[count];
                        count++;
                    }
            }

            n = 0;
            count = 1;
            for (int m = 0; m < str.length(); m++) {
                str[m] = arr[n][m];
                n += count;
                if (n == (Key - 1) || (n == 0)) {
                    count *= -1;
                }
            }

            count = 0;
            for (int i = 0; i < textLength; i++)
            {
                for (int j = 0; j < alfavit.length(); j++)
                    if (strCopy[i] == alfavit[j])
                    {
                        strCopy[i] = str[count];
                        count++;
                        break;
                    }
            }

        }

        return strCopy;
    }
}
