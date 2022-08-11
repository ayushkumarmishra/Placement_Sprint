/*

 */
#include <bits/stdc++.h>
using namespace std;

void solve(string str, int n, int min)
{
    bool haslower = false;
    bool hasUpper = false;
    bool hasDigit = false;
    bool specialChar = false;
    bool notRequired = false;
    string normalChar = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";

    for (int i = 0; i < n; i++)
    {
        if (str[i] == ' ' || str[i] == '+')
        {
            notRequired = true;
            break;
        }
        if (islower(str[i]))
            haslower = true;
        if (isupper(str[i]))
            hasUpper = true;
        if (isdigit(str[i]))
            hasUpper = true;

        auto special = str.find_first_not_of(normalChar);
        if (special != string::npos)
            specialChar = true;
    }

    cout << "The Password is : ";
    if (haslower && hasUpper && hasDigit && specialChar)
        cout << "Valid" << endl;
    else
        cout << "Invalid" << endl;
}

int main()
{
    string str;
    cin >> str;
    int n = str.length();
    int min;
    cin >> min;
    if (n < min || (str[0] - '0' >= 0 && str[0] - '0' <= 9))
        cout << "Invalid" << endl;
    else
        solve(str, n, min);
    return 0;
}