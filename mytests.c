#include <ctest.h>
#include <iostream>
#include <ctime>
#include <cstdlib>

int GetUserNum(int Count)
{
    const int InitialCount = 100;
    bool Correct;
    int Num;
    do
    {
        cout << "Ваш ход. На столе " << Count << " спичек.\n";
        cout << "Сколько спичек Вы берете?\n";
        //cin >> Num;
        Num = rand() % 10 + 1;
        if (Num >= 1 && Num <= 10 && Num <= Count)
            Correct = true;
        else
        {
            cout << "Неверно! Повторите ввод!\n";
            Correct = false;
        }
    }
    while (!Correct);
    return Num;
}

CTEST(suite1, test1)
{
    // Given
    const int a = 20;

    // When
    const int result = GetUserNum(a);

    // Then
    ASSERT_INTERVAL(1, 10, result);
}