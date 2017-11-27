#include <ctest.h>
#include <stdlib.h>

int GetUserNum(int Count)
{
    const int InitialCount = 100;
    int Correct;
    int Num;
    do
    {
        //cin >> Num;
        Num = rand() % 10 + 1;
        if (Num >= 1 && Num <= 10 && Num <= Count)
            Correct = 1;
        else
        {
            Correct = 0;
        }
    }
    while (Correct == 0);
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