#include <iostream>
#include <string>
int main()
{
    using namespace std;
    string voca; 
    int num = 0; 
    
    cout << "영어 단어들을 입력하십시오(끝내려면 done을 입력) : " << endl;
    cin >> voca; 
    
    while (voca != "done") 
    {
        num++;
        cin >> voca; 
    }
    
    cout << "총" << num << "단어가 입력되었습니다." << endl;
    return 0;
}