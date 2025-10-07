#include <iostream>
#include <string>
int main()
{
    using namespace std;
    struct car
    {
        char company[20];
        int year;
    };
    int num;
    cout << "몇 대의 차를 목록으로 관리하시겠습니까? ";
    cin >> num;
    cin.get();

    car * cars = new car[num];

    for(int i = 0; i < num; i++)
    {
        cout << "자동차 #" << i + 1 << ":" << endl;
        cout << "제작업체: ";
        cin.getline(cars[i].company, 20);
        cout << "제작년도: ";
        cin >> cars[i].year;
        cin.get();
    }

    cout << "현재 귀하가 보유하고 있는 자동차 목록은 다음과 같습니다: " << endl;
    
    for (int i = 0; i < num; i++)
    cout << cars[i].year << "년형 " << cars[i].company << endl;
    delete[] cars;


}