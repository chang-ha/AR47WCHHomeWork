#include <iostream>

int StringCount(const char* _String)
{
    int String_Length = 0;
    while (_String[String_Length] != '\0')
    {
        ++String_Length;
    }
    return String_Length;
}

void TrimDelete(char* _String)
{
    char Arr[1024] = {};
    int OriginCount = 0;
    int ReturnCount = 0;

    while (_String[OriginCount] != '\0')
    {
        if (_String[OriginCount] != ' ')
        {
            Arr[ReturnCount] = _String[OriginCount];
            ++ReturnCount;
        }
        ++OriginCount;
    }

    int CopyCount = 0;

    while (Arr[CopyCount] != '\0')
    {
        _String[CopyCount] = Arr[CopyCount];
        ++CopyCount;
    }

    _String[CopyCount] = 0;
}

int StringCount(const char* _String)
{
    int count = 0;
    while (_String[count] != 0)
    {
        ++count;
    }
    return count;
}
int StringToInt(const char* _String)
{
    int String_Number = StringCount(_String);
    int MulValue = 1;
    int MulCount = String_Number;
    while (MulCount - 1)
    {
        MulValue *= 10;
        --MulCount;
    }
    return 0;
}

int main()
{
    char Arr[1024] = "ab  cd e";
    TrimDelete(Arr);
}

