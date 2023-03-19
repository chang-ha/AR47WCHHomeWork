#include <iostream>

// 영어만 씁니다.
// 문자열을 넣어주면 글자 개수를 알아냅니다.
// 0을 포함할지 아닐지는 스스로 정하세요
int StringCount(const char* _String)
{
    int String_Length = 0;
    char String = _String[0];
    while (String != 0)
    {
        String_Length += 1;
        String = _String[String_Length];
    }
    return String_Length;
}

char TrimDelete(char* _String)
{
    char* String = _String;
    char Value = *String;
    while (Value != 0)
    {
        Value = *String;
        if (Value == ' ')
        {
            int Location = 0;
            while (String[Location] != 0)
            {
                String[Location] = String[Location + 1];
                ++Location;
            }
        }
        else
        {
            String += 1;
        }
    }
    return *_String;
}

int StringToInt(const char* _String)
{
    const char* String = _String;
    int Value = 0;
    if (*String == '-')
    {
        ++String;
        while (*String != 0)
        {
            Value = Value * 10 + (*String - '0');
            ++String;
        }
        return -Value;
    }
    else
    {
        while (*String != 0)
        {
            Value = Value * 10 + (*String - '0');
            ++String;
        }
        return Value;
    }
}

int main()
{
    // StringCount Test
    printf_s("StringCount Test\n");

    int Count1 = StringCount("abcde");
    printf_s("%d\n", Count1);
    int Count2 = StringCount("aaaa ggg sss        asjas001293---123-1--123-");
    printf_s("%d\n", Count2);
    int Count3 = StringCount("ckask aksdoc askdkcklll");
    printf_s("%d\n", Count3);
    int Count4 = StringCount("abcdefg hijklmn opqrstu vwxyz");
    printf_s("%d\n\n", Count4);


    // TrimDelete Test
    printf_s("TrimDelete Test\n");

    char Arr0[1024] = "       a b c  d    e  rkdksksdkaqkwdk dqkwodkqs cksodkcao ccna    ashdasjkd   ";
    TrimDelete(Arr0);
    printf_s("%s\n", Arr0);
    char Arr1[1024] = "dkaskc    askdaskdk";
    TrimDelete(Arr1);
    printf_s("%s\n", Arr1);
    char Arr2[1024] = " a b c d e f g";
    TrimDelete(Arr2);
    printf_s("%s\n", Arr2);
    char Arr3[1024] = "a b c d e f g";
    TrimDelete(Arr3);
    printf_s("%s\n", Arr3);
    char Arr4[1024] = "                           ";
    TrimDelete(Arr4);
    printf_s("%s\n\n", Arr4);


    // StringToInt Test
    printf_s("StringToInt Test\n");

    int RValue0 = StringToInt("1234");
    printf_s("%d\n", RValue0);
    int RValue1 = StringToInt("0043200");
    printf_s("%d\n", RValue1);
    int RValue2 = StringToInt("4523312");
    printf_s("%d\n", RValue2);
    int RValue3 = StringToInt("432231");
    printf_s("%d\n", RValue3);
    // INT 최댓값
    int RValue4 = StringToInt("002147483647");
    printf_s("%d\n", RValue4);
    // -값
    int RValue5 = StringToInt("-47123647");
    printf_s("%d\n", RValue5);

}

