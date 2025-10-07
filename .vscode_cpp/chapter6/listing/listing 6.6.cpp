#include <iostream>
const char * qualify[4] = // 자료형이 char형이고, 배열의 크기가 4인 qualify 배열을 포인터로 지시
                          // 추가로 const로 배열 크기가 변하지 않도록 고정
{
    "만미터 달리기",
    "모래사장 씨름",
    "비치 발리",
    "부메랑 던지기"
};
int main()
{
    using namespace std;
    int age, index; // age: 나이 index: 배열의 n번째 인덱스를 의미
    cout << "나이를 입력하십시오: ";
    cin >> age;

    if (age > 17 && age < 35) // 사용자 나이 18세 이상 34세 이하만 해당 
    {                         
        index = 0; // 0번째 인덱스의 값
    }                          
    else if (age >= 35 && age < 50) // 사용자 나이 35세 이상 49세 이하만 해당
    {                               
        index = 1; // 1번째 인덱스의 값
    }
    else if (age >= 50 && age < 65) // 사용자 나이 50세 이상 64세 이하만 해당
    {
        index = 2; // 2번째 인덱스의 값
    }
    else // 사용자 나이 65세 이상만 해당
    {
        index = 3; // 3번째 인덱스의 값
    }
    cout << "당신은 " << qualify[index] << "에 참가할 수 있습니다.\n";
    return 0;   
}