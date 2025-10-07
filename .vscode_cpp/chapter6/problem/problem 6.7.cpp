#include <iostream>
#include <cctype>
int main()
{
    const int size = 20;
    using namespace std;
    char words;
    int count1 = 0, count2 = 0, count3 = 0; // 자음, 모음, 기타
    cout << "단어들을 입력하시오 (끝내려면 q): ";
    cin >> words;

    while (words != 'q')
    {
        if (!(isalpha(words))) // 숫자
        {
            ++count3;
        }
        else if (words = 'a' || 'e' || 'i' || 'o' || 'u') // 모음
        {
            ++count2;
        }
        else // 자음
        {
            ++count1;
        }
        cin >> words;
    }
    cout << "자음으로 시작하는 단어 수: " << count1 << endl;
    cout << "모음으로 시작하는 단어 수: " << count2 << endl;
    cout << "기타: " << count3 << endl;
    return 0;
}