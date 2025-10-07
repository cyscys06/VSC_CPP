#include <iostream>
#include <cstring>
int main()
{
    using namespace std;
    const int s = 20;
    char voca[s] = {"0"}; 
    int num = 0; 
    
    cout << "영어 단어들을 입력하십시오(끝내려면 done을 입력) : " << endl;
    cin >> voca; // voca 값 초기화(이 구문이 만약 없다면?)
    
    while (strcmp(voca, "done")) // strcmp(배열명, 문자열): 배열에 저장된 문자열이 함수에서 지정한 문자와 같으면 0을 출력(false)
    {
        num++;
        cin >> voca; // cin에서 공백을 만나면 자동으로 단어 하나 입력된 것으로 처리
    }
    
    cout << "총 " << num << "단어가 입력되었습니다." << endl;
    return 0;
}