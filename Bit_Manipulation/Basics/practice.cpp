/*
 Basics Bits Questions
 */
#include <bits/stdc++.h>
using namespace std;

// Doing n & 1 ==> doing and operations with 0000001 which makes us to check the last digit only and making other digit as 0.

void checkEvenOdd(int n)
{
    if ((n & 1) == 1)
        cout << "Odd";
    else
        cout << "Even";
}

int setIthBit(int n, int i)
{
    int bitMask = (1 << i);
    return n | bitMask;
}

void getIthBit(int n, int i)
{
    int bitMask = 1 << i;
    if ((n & bitMask) == 0)
        cout << "0";
    else
        cout << "1";
}

int clearIthBit(int n, int i)
{
    int bitMask = ~(1 << i);
    return n & bitMask;
}

int updateIthBit(int n, int i, int newBit)
{
    if (newBit == 0)
        return clearIthBit(n, i);
    else
        return setIthBit(n, i);
}

int clearLastIthBit(int n, int i)
{
    int bitMask = (~0) << i;
    return n & bitMask;
}

int solution(string street)
{
    street = "H" + street + "H";
    int n = street.length();
    int minBuckets = 0;
    int lastBucketPos = -1;
    for (int i = 1; i < n - 1; i++)
    {
        int c = street[i];
        if (c == 'H' && lastBucketPos != i - 1)
        {
            if (street[i + 1] == '-')
            {
                minBuckets++;
                lastBucketPos = i + 1;
            }
            else if (street[i - 1] == '-')
            {
                minBuckets++;
                lastBucketPos = i - 1;
            }
            else
            {
                return -1;
            }
        }
    }
    return minBuckets;
}

void solve()
{
    // checkEvenOdd(40);
    // getIthBit(10, 3);
    // cout << clearIthBit(10, 1);
    // cout << updateIthBit(10, 0, 1);
    // cout << clearLastIthBit(7, 1);
    cout << solution("H-H-") << endl;
}

int main()
{
    solve();
    return 0;
}