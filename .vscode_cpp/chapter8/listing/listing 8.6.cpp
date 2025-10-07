#include <iostream>
#include <string>
using namespace std;
struct free_throws
{
    string name;
    int made;
    int attempts;
    float percent;
};

void display(const free_throws & ft);
void set_pc(free_throws & ft);
free_throws & accumulate(free_throws & target, const free_throws & sourse);

int main()
{
    // 부분 초기화 - 멤버는 0에 세팅된 상태로 남는다
    free_throws one = {"a", 13, 14};
    free_throws two = {"b", 10, 16};
    free_throws three = {"c", 7, 9};
    free_throws four = {"d", 5, 9};
    free_throws five = {"e", 6, 14};
    free_throws team = {"f", 0, 0};
    
    // 초기화 안함
    free_throws dup;
    set_pc(one); // 계산
    display(one); // 출력
    accumulate(team, one); // 데이터 누적
    display(team); // 누적된 데이터 출력

    // 리턴 값을 매개변수로 사용
    display(accumulate(team, two)); 
    accumulate(accumulate(team, three), four);
    display(team);

    // 리턴 값을 대입 값으로 사용
    dup = accumulate(team, five);
    cout << "team: \n";
    display(team);
    cout << "dup: \n";
    display(dup);
    set_pc(four);

    // 문제의 소지가 있는 대입
    accumulate(dup, five) = four;
    cout << "dup: \n";
    display(dup);
    return 0;
}

void display(const free_throws & ft) // 선수 정보 출력 함수
{
    cout << "name: " << ft.name << endl;
    cout << "made: " << ft.made << endl;
    cout << "attempts: " << ft.attempts << endl;
    cout << "percent: " << ft.percent << endl;
}

void set_pc(free_throws & ft) // 성공률 계산 함수
{
    if (ft.attempts != 0) // 성공률 0 아닐때
    {
        ft.percent = 100.0f *float(ft.made) / float(ft.attempts);
    }
    else
    {
        ft.percent = 0; // 0일때
    }
}

free_throws & accumulate(free_throws & target, const free_throws & source) // 기록 합산 함수
{
    target.attempts += source.attempts; // target: 기존값 source: 기존값에 더하는 값
    target.made += source.made;
    set_pc(target);
    return target;
}