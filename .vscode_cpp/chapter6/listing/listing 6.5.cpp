#include <iostream>
const int Arsize = 6; // 고정값 설정(배열 크기)
int main()
{
    using namespace std;
    float naaq[Arsize]; // naaq: 뉴에이지 자각 지수, 배열 선언
    int i = 0, count = 0; // i: while문에서 쓸 카운터 미리 선언 
                          // count: 사용자보다 naaq가 높은 사람들의 수
    float temp, you; // temp: 사람들의 naaq 지수 저장할 변수 you: 사용자의 naaq지수 저장할 변수
    cout << "동료들의 뉴에이지 자각 지수를 입력하시오.\n"
         << Arsize << "명의 데이터를 모두 입력했거나, 음수를 입력하면\n"
         << "while 루프를 탈출합니다.\n";
    cout << "첫 번째 값: ";
    cin >> temp; 
    while (i < Arsize && temp >= 0) // 비교연산자(>=)에서 부등호 먼저 입력하기
                                    // 데이터 전부 입력했거나 음수 입력하면 루프 종료
    {
        naaq[i] = temp; 
        ++i; // i에 1 추가
        if (i < Arsize) // 여전히 i가 Arsize보다 크면 if구문 코드블록 실행
        {
            cout << "그 다음 값: ";
            cin >> temp;
        }
    }
    if (i == 0) // 맨 처음부터 음수를 입력해서 i가 0인채로 루프가 종료된 경우
    {
        cout << "입력한 데이터가 없으므로 프로그램을 종료합니다.\n";
    }
    else // 6명 전부 또는 입력 중간에 음수를 입력한 경우
    {
        cout << "본인의 뉴에이지 자각 지수를 입력하시오: ";
        cin >> you;
        for (int j = 0; j < i; j++) // 문장 전부 진행 후 맨 마지막에 j에 1추가
            if (naaq[j] > you) // 사용자가 입력한 지수보다 높은 값을 가진 사람이 있을 경우
            {
                ++count; // 카운트 1 추가
            }
        cout << "동료들 중에서 " << count;
        cout << "명이 당신보다 naaq가 높습니다.\n";
    }
    return 0;
}