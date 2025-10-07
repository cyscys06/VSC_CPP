#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Person
{
private:
    static const int LIMIT = 25;
    string lname; // 성씨
    char fname[LIMIT]; // 이름
public:
    Person() {lname = ""; fname[0] = '\0';} // 디폴트값
    Person(const string & ln, const char * fn = "Heyyou"); // #2
    void Show() const; // 이름 성씨 형식
    void FormalShow() const; // 성씨 이름 형식
};

int main()
{
    Person one; // 디폴트값 가지는 객체
    Person two("Smythecraft"); // 디폴트 1개, 매개변수 1개 객체
    Person three("Dimwiddy", "Sam"); // 매개변수만 2개 객체

    one.Show(); // lname = "", fname[0] = '\0'
    cout << endl;
    one.FormalShow(); // lname = "", fname[0] = '\0'
    cout << endl;
    two.Show();
    cout << endl;
    two.FormalShow();
    cout << endl;
    three.Show();
    cout << endl;
    three.FormalShow();
    cout << endl;
}

Person::Person(const string & ln, const char * fn)
{
    lname = ln; // 매개변수 ln을 lname멤버에 할당
    strncpy(fname, fn, (LIMIT - 1)); // fname멤버에 fn매개변수를 최대(LIMIT - 1)개수만큼 할당
    fname[LIMIT - 1] = '\0';
}

void Person::Show() const
{
    cout << "name: " << fname << " " << lname << endl;
}

void Person::FormalShow() const
{
    cout << "name: " << lname << " " << fname << endl;
}