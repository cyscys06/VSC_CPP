#ifndef EMP_H_
#define EMP_H_

#include <string>
using namespace std;

class abstr_emp
{
private:
    string fname; // 퍼스트 네임
    string lname; // 라스트 네임
    string job;   // 직업
public:
    abstr_emp();
    abstr_emp(const string & fn, const string & ln, const string & j);
    virtual void ShowAll() const; // 정보 출력
    virtual void SetAll(); // 정보 입력
    friend ostream & operator<<(ostream & os, const abstr_emp & e);
    virtual ~abstr_emp(); // 가상 소멸자
};

class employee : public abstr_emp
{
public:
    employee();
    employee(const string & fn, const string & ln, const string & j);
};

class manager : virtual public abstr_emp
{
private:
    int inchargeof; // 관리 인원 수
protected:
    int InChargeOf() const { return inchargeof; } 
    int & InChargeOf() { return inchargeof; } 
public:
    manager();
    manager(const string & fn, const string & ln, const string & j, int ico = 0);
    manager(const abstr_emp & e, int ico);
    manager(const manager & m);
    virtual void ShowAll() const;
    virtual void SetAll();
};

class fink : virtual public abstr_emp
{
private:
    string reportsto; // 보고 대상
protected:
    const string ReportsTo() const { return reportsto; } 
    string & ReportsTo() { return reportsto; } 
public:
    fink();
    fink(const string & fn, const string & ln, const string & j, const string & rpo);
    fink(const abstr_emp & e, const string & rpo);
    fink(const fink & e);
    virtual void ShowAll() const;
    virtual void SetAll();
};

class highfink : public manager, public fink
{
public:
    highfink();
    highfink(const string & fn, const string & ln, const string & j, const string & rpo, int ico);
    highfink(const abstr_emp & e, const string & rpo, int ico);
    highfink(const fink & f, int ico);
    highfink(const manager & m, const string & rpo);
    highfink(const highfink & h);
    virtual void ShowAll() const;
    virtual void SetAll();
};

#endif
