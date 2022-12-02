#include <Windows.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#include "msclr\marshal_cppstd.h"
using namespace std;

//Функция шифрования
string EncryptResheto(string str) {

	string alfavit = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int count;

	char grid[4][4] =    { {'j', 'q', 'w', 'x'},
						   {'y', 'z', 'q', 'x'},
						   {'z', 'y', 'y', 'j'},
						   {'z', 'j', 'z', 'x'} };

	// 0 - y, 1 - x; таблица порядка размещения букв решетку
	int const order[16][2] = { {0, 0}, {1, 3}, {2, 2}, {3, 1},
							  {0, 3}, {1, 0}, {2, 1}, {3, 2},
							  {0, 2}, {1, 1}, {2, 0}, {3, 3},
							  {0, 1}, {1, 2}, {2, 3}, {3, 0} };

    string strCopy = str;
    string rez1 = "                                                                                                                                                                                                                ";
    string rez2 = "                                                                                                                                                                                                                       ";

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

    count = 0;
    for (int i = 0; i < textLength; i += 16)
    {
        for (int j = 0; j < 16; j++)
        {
            if (i + j < textLength)
                grid[order[j][0]][order[j][1]] = str[i + j];
        }
        int m = count * 16;
        for (int k = 0; k < 4; k++) {
            for (int l = 0; l < 4; l++) {
                rez1[m] = grid[k][l];
                m++;
            }
        }
        count++;
    }

    count = 0;
    for (int i = 0; i < strCopy.length(); i++)
    {
        for (int j = 0; j < alfavit.length(); j++)
            if (strCopy[i] == alfavit[j])
            {
                rez2[i] = rez1[count];
                count++;
                break;
            }
            else {
                rez2[i] = strCopy[i];
            }
    }

    int n = strCopy.length();
    if (rez1[count] != ' ') {
        while (rez1[count] != ' ') {
            rez2[n] = rez1[count];
            count++;
            n++;
        }
    }

	return rez2;
}

//Функция дешифрования
string DecodeResheto(string str) {

    string alfavit = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int count;

    char grid[4][4] = { {'j', 'q', 'w', 'x'},
                           {'y', 'z', 'q', 'x'},
                           {'z', 'y', 'y', 'j'},
                           {'z', 'j', 'z', 'x'} };

    // 0 - y, 1 - x; таблица порядка размещения букв решетку
    int const order[16][2] = { {0, 0}, {1, 3}, {2, 2}, {3, 1},
                              {0, 3}, {1, 0}, {2, 1}, {3, 2},
                              {0, 2}, {1, 1}, {2, 0}, {3, 3},
                              {0, 1}, {1, 2}, {2, 3}, {3, 0} };

    string strCopy = str;
    string rez1 = "                                                                                                                                                                                                                ";
    string rez2 = "                                                                                                                                                                                                                       ";

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

    count = 0;
    for (int i = 0; i < textLength; i += 16)
    {
        int m = count * 16;
        for (int k = 0; k < 4; k++) {
            for (int l = 0; l < 4; l++) {
                grid[k][l] = str[i + k * 4 + l];
            }
        }
        for (int j = 0; j < 16; j++)
        {
            rez1[m] = (grid[order[j][0]][order[j][1]]);
            m++;
        }
        count++;
    }

    count = 0;
    for (int i = 0; i < strCopy.length(); i++)
    {
        for (int j = 0; j < alfavit.length(); j++)
            if (strCopy[i] == alfavit[j])
            {
                rez2[i] = rez1[count];
                count++;
                break;
            }
            else {
                rez2[i] = strCopy[i];
            }
    }

    int n = strCopy.length();
    if (rez1[count] != ' ') {
        while (rez1[count] != ' ') {
            rez2[n] = rez1[count];
            count++;
            n++;
        }
    }

    return rez2;
}



