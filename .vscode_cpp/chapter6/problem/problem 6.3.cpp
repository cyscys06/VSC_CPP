#include <iostream>
int main()
{
    using namespace std;
    char option;
    cout << "다음 선택 사항 중에서 하나를 선택하십시오.  (끝내려면 q)\n"
            "c) camera      p) pianist\n"
            "t) tree        g) game\n";
    
    while (option != 'q') // q누르면 종료
    {
        cin >> option;
        switch(option)
            {
	            case 'c': cout << "c\n";
                          continue;
	            case 'p': cout << "p\n";
                          continue;
	            case 't': cout << "단풍나무는 잎이 별처럼 생겼습니다.\n";
                          continue;
                case 'g': cout << "g\n";
                          continue;
                case 'q': break;
                
                default : cout << "c, p, t, g 중에서 하나를 선택하십시오.  (끝내려면 q)\n";
                          continue;
            }
    }
    return 0;
}