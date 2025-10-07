#include <iostream>

#define endl /n
int main()
{
    using namespace std;
    cout << "수를 입력하시오(0을 출력하면 종료): ";
    int num;
    cin >> num;

    int total = 0;
    while (num != 0) 
    {
        total += num;
        cout << "입력된 수들의 누계: " << total << endl;
        cout << "수를 입력하시오(0을 입력하면 종료): ";
        cin >> num;
    }
    cout << "프로그램이 종료되었습니다." << endl;
    return 0;
}