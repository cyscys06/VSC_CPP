#include <iostream>
using namespace std;
long double probability1(unsigned numbers, unsigned picks);
long double probability2(unsigned numbers);

int main()
{
    double total1, choices1, total2; // choices2는 항상 1이다. 
    
    cout << "첫번째 범위에서 고를 전체 수의 개수와 뽑을 수의 개수,\n";
    cout << "두번째 범위(파워볼)에서 고를 수의 개수를 차례대로 입력하십시오(끝내려면 q): ";
    while (cin >> total1 >> choices1 >> total2 && total1 >= choices1) // 뽑는 수는 전체 수보다 크면 안됨
        {        
            double first = probability1(total1, choices1);
            double second = probability2(total2);
            cout << "첫번째 범위에서의 확률: " << first << endl;
            cout << "두번째 범위에서의 확률: 1/" << second << endl;
            cout << "복권에 당첨될 총 확률: 1/" << first * second << endl;
            cout << "다시 정해진 형식으로 수를 입력하시오(끝내려면 q): ";
        }
    cout << "프로그램을 종료합니다.\n";
    return 0;
}

long double probability1(unsigned numbers, unsigned picks) // 첫번째 범위
{
    long double result1 = 1.0, n1;
    unsigned p1;

    for (n1 = numbers, p1 = picks; p1 > 0; n1--, p1--)
    {
        result1 *= (p1 / n1);
    }
    return result1;
}

long double probability2(unsigned numbers) // 두번째 범위
{
    long double result2 = 1.0, n2;
    unsigned p2;

    for (n2 = numbers, p2 = 1; p2 > 0; n2--, p2--) // 처음부터 1로 초기화 해놓고 진행
    {
        result2 *= (n2 / p2);
    }
    return result2;
}