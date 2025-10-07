#include <iostream>
int main()
{
    using namespace std;
    double income, tax_income;
    cout << "소득을 입력하십시오: ";
    cin >> income;
    
    if (income <= 5000)
    {
        tax_income = income * 0.00;
    }
    else if (income > 5000 && income <= 10000)
    {
        tax_income = 5000 * 0.00 + (income - 5000) * 0.10;
    }
    else if (income > 10000 && income <= 20000)
    {
        tax_income = 5000 * 0.00 + 10000 * 0.10
        + (income - 15000) * 0.15;
    }
    else if (income > 35000)
    {
        tax_income = 5000 * 0.00 + 10000 * 0.10
        + 20000 * 0.15 + (income - 35000) * 0.20;
    }
    else if (isdigit(income))
    {
        cout << "프로그램을 종료합니다.";
    }
    cout << "소득세: " << tax_income << endl;
}