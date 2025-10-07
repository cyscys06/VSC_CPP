#include <iostream>
#include <string>
int main()
{
    using namespace std;

    const int months = 12, sales = 20; 
    string year[months] = 
    {
        "jan","feb","mar","apr","may","jun",
        "jul","aug","sep","oct","nov","dec"
    };
    int i = 0;
    int total = 0; // 연간 총 판매량(쓰레기값 생성 방지를 위해 임의의 값(0) 할당 필요)
    int MS[sales]; // 월간 판매량 저장하는 int형 배열 생성
    
    while (i < 12)
    {
        cout << year[i] << "의 책 판매량을 입력하시오: ";
        cin >> MS[i];
        total = total + MS[i]; 
        i++;
    }
    cout << "올해의 연간 총 판매량: " << total << endl;
    return 0;
}