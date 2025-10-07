#include <iostream>
int main()
{
    using namespace std;
    char ch;
    int space = 0, total = 0;
    cin.get(ch); // 사용자가 입력한 여러 문자들을 한 글자씩 인식(while 구문에서 한글자씩 루프 안으로 넣는다)
    while (ch != '.') // 조건식에 문자 넣을때는 반드시 작은 따옴표로 입력(중요)
    {
        if (ch == ' ') // 변수 ch가 빈칸과 같으면 true
        {
            ++space; // true면 변수 space에 1 추가
        }    
        ++total;
        cin.get(ch);
    }
    cout << "이 문장의 총 문자 수는 " << total << "글자이고, ";
    cout << "그 중에서 빈칸 수는 " << space << "칸입니다.\n";
    return 0;
}