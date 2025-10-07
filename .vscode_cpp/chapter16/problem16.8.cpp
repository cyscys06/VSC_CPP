#include <iostream>
#include <set>
#include <string>
#include <iterator>
#include <algorithm>
using namespace std;

void input(set<string> & s);

int main()
{
	set<string> Mat, Pat;
	cout << "Mat의 친구목록 입력(끝내려면 q):\n";
	input(Mat);
	cout << "Pat의 친구목록 입력(끝내려면 q):\n";
	input(Pat);
	ostream_iterator<string> out(cout, " "); // 반복자 선언

	cout << "Mat의 친구목록\n";
	copy(Mat.begin(), Mat.end(), out);
	cout << endl;

	cout << "Pat의 친구목록\n";
	copy(Pat.begin(), Pat.end(), out);
	cout << endl;

	set<string> MatPat;
	set_union(Mat.begin(), Mat.end(), Pat.begin(), Pat.end(), insert_iterator<set<string>>(MatPat, MatPat.begin()));

	cout << "Mat와 Pat의 친구 목록\n";
	copy(MatPat.begin(), MatPat.end(), out);
	cout << endl;

	return 0;
}

void input(set<string> & s)
{
	string temp;
	getline(cin, temp);
	while (temp != "q")
	{
		s.insert(temp);
		getline(cin, temp);
	}
}