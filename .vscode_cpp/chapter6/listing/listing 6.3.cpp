#include <iostream>
const int Fave = 27; // 고정값 설정
int main()
{
    using namespace std;
    
    int n;

    cout << "1부터 100까지중 숫자맞추기 게임.\n";
    cout << "수를 맞춰보시오";
    do // do while문: while구문과 상관없이 do구문 속 문장을 먼저 한번 실행 
    {
        cin >> n;
        if (n < Fave) // 입력한 수가 정답보다 작으면
        {
            cout << "그것보다 큽니다."; // 정답이 입력한 수보다
        }
        else if(n > Fave) // 입력한 수가 정답보다 크면
        {
            cout << "그것보다 작습니다."; // 정답이 입력한 수보다
        }
        else // 입력한 수가 정답보다 작거나 크거나 같음(3가지 경우), 마지막은 같은 경우
            cout << "맞았습니다. 정답은" << Fave << "입니다.";
    } 
    while (n != Fave);
    return 0;
}