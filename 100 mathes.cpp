// s100.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

#define isTest true

int main()
{
    const int InitialCount = 100;
    int Count, Num, Player;
    bool Correct;

    setlocale(LC_ALL, "Russian");
    srand(time(0));
    system("cls");
    Player = 1;
    Count = InitialCount;

    int userTestNum = -2;
    int enemyTestNum = -2;
    if (isTest)
        Num = -2;
    do
    {
        if (Player == 1)
        {
            do
            {
                cout << "��� ���. �� ����� " << Count << " ������.\n";
                cout << "������� ������ �� ������?\n";
                if (isTest)
                {
                    Num = userTestNum++;
                    cout << "���� Num = "<<Num<<"\n";
                    if (userTestNum > 11)
                        userTestNum = -1;
                }
                else
                    cin >> Num;
                if (Num >= 1 && Num <= 10 && Num <= Count)
                    Correct = true;
                else
                {
                    cout << "�������! ��������� ����!\n";
                    Correct = false;
                }
            }
            while (!Correct);
        }
        else
        {
            do
            {
                if (isTest)
                {
                    Num = enemyTestNum++;
                    if (enemyTestNum > 11)
                        enemyTestNum = -1;
                }
                else
                    Num = rand() % 10 + 1;

                if (Num < 1 || Num > 10)
                    Num = 5;

                if (Num > Count)
                    Num = Count;
                cout << "��� ���. � ���� " << Num << " ������\n";
            }
            while (!Correct);
        }
        Count -= Num;
        if (Player == 1)
            Player = 2;
        else
            Player = 1;
    }
    while (Count>0);
    if (Player = 1)
        cout << "�� ��������!";
    else 
        cout << "�� ���������!";
    system("pause");
    return 0;
}