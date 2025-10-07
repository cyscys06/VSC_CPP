#include <iostream>
#include <array>
int main()
{
    using namespace std;
    const int size = 10;
    double total = 0;
    int count1 = 0, count2 = 0; // count1: 입력된 기부금 수 count2: 평균보다 큰 기부금 수
    
    array<double, size> donate; // 자료형 double이므로 double만 받을수 있다
    cout << "기부금을 입력하시오(최대 10개까지): " << endl;
    cout << "숫자 외의 문자를 입력 시 프로그램 종료." << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> donate[i];
         if (cin.fail())
            {
                cout << "부적절한 문자 입력으로 인해 프로그램이 종료되었습니다.\n";
                break;
            }
        total += donate[i];
        ++count1;
    }
    
    double average = total / count1;
    cout << "입력된 기부금들의 평균은 " << average << "입니다.\n";
    for (int j = 0; j < size; j++)
    { 
        if (donate[j] > (total / size))
        {
            ++count2;
        }
    }
    cout << "기부금들의 평균보다 큰 기부금의 수는 " << count2 << "입니다.\n";
    return 0;
}