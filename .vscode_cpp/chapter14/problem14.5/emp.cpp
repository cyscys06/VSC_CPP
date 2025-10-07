#include "emp.h"
#include <iostream>
using namespace std;

abstr_emp::abstr_emp() : fname("none"), lname("none"), job("none") {}
abstr_emp::abstr_emp(const string & fn, const string & ln, const string & j) : fname(fn), lname(ln), job(j) {}
abstr_emp::~abstr_emp() {}

void abstr_emp::ShowAll() const 
{
	cout << "이름: " << fname << ", " << lname << endl;
	cout << "직업: " << job << endl;
}

void abstr_emp::SetAll() 
{
	cout << "퍼스트 네임 입력 : "; getline(cin, fname);
	cout << "라스트 네임 입력 : "; getline(cin, lname);
	cout << "직업 입력 : "; getline(cin, job);
}

ostream & operator<<(ostream & os, const abstr_emp & e) 
{
	os << e.fname << ", " << e.lname << endl;
	return os;
}

employee::employee() : abstr_emp() {}
employee::employee(const string & fn, const string & ln, const string & j) : abstr_emp(fn, ln, j) {}

manager::manager() : abstr_emp(), inchargeof(0) {}
manager::manager(const string & fn, const string & ln, const string & j, int ico) : abstr_emp(fn, ln, j), inchargeof(ico) {}
manager::manager(const abstr_emp & e, int ico) : abstr_emp(e), inchargeof(ico) {}
manager::manager(const manager & m) : abstr_emp(m), inchargeof(m.inchargeof) {}

void manager::ShowAll() const 
{
	abstr_emp::ShowAll();
	cout << "inchargeof : " << inchargeof << endl;
}

void manager::SetAll() 
{
	abstr_emp::SetAll();
	cout << "inchargeof 입력 : "; 
    cin >> inchargeof;
	while (cin.get() != '\n') 
    {
        continue;
    }
}

fink::fink() : abstr_emp(), reportsto("none") {}
fink::fink(const string & fn, const string & ln, const string & j, const string & rpo) : abstr_emp(fn, ln, j), reportsto(rpo) {}
fink::fink(const abstr_emp & e, const string & rpo) : abstr_emp(e), reportsto(rpo) {}
fink::fink(const fink & e) : abstr_emp(e), reportsto(e.reportsto) {}

void fink::ShowAll() const 
{
	abstr_emp::ShowAll();
	cout << "reportsto : " << reportsto << endl;
}

void fink::SetAll() 
{
	abstr_emp::SetAll();
	cout << "reportsto 입력 : "; getline(cin, reportsto);
}

highfink::highfink() : abstr_emp(), manager(), fink() {}
highfink::highfink(const string & fn, const string & ln, const string & j, const string & rpo, int ico)
	: abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo) {}
highfink::highfink(const abstr_emp & e, const string & rpo, int ico)
	: abstr_emp(e), manager(e, ico), fink(e, rpo) {}
highfink::highfink(const fink & f, int ico)
	: abstr_emp(f), manager(f, ico), fink(f) {}
highfink::highfink(const manager & m, const string & rpo)
	: abstr_emp(m), manager(m), fink(m, rpo) {}
highfink::highfink(const highfink & h)
	: abstr_emp(h), manager(h), fink(h) {}

void highfink::ShowAll() const 
{
	abstr_emp::ShowAll();
	cout << "inchargeof : " << manager::InChargeOf() << endl;
	cout << "reportsto : " << fink::ReportsTo() << endl;
}

void highfink::SetAll() 
{
	abstr_emp::SetAll();
	cout << "inchargeof 입력 : "; 
    cin >> manager::InChargeOf();
	while (cin.get() != '\n') continue;
	cout << "reportsto 입력 : ";
	string& rpo = fink::ReportsTo();
	getline(cin, rpo);
}
