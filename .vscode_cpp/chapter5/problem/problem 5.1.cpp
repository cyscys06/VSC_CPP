#include <iostream>
int main()
{
    using namespace std;
    cout << "첫 번째 정수를 입력하시오: ";
    int FI; // First Integer
    cin >> FI;
    cout << "두 번째 정수를 입력하시오: ";
    int SI; // Second Integer
    cin >> SI;
    int total = 0;
    
    for (int i = FI; i <= SI; i++)
        total += i;
    
    cout << "모든 정수들의 합: " << total << endl;
    return 0;
}