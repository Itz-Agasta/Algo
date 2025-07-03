#include <bits/stdc++.h>
using namespace std;

// count num
// Time Complexity: O(d)
// Space Complexity: O(1)
int count(int n)
{
    int count = 0;
    while (n > 0)
    {
        n = n / 10;
        count++;
    }
    return count;
}
// Another Method
int count2(int n)
{
    int count = int(log10(n) + 1);
    return count;
}

// Rev a num
int rev(int n)
{
    int rev = 0;
    while (n > 0)
    {
        int temp = n % 10;
        rev = ((rev * 10) + temp);
        n = n / 10;
    }
    return rev;
}

// Palindrome
bool isPal(int n)
{

    return n == rev(n);
}

// Armstrong
bool isArm(int n)
{
    int num = n;
    int armNum = 0;
    while (n > 0)
    {
        int temp = n % 10;
        armNum += pow(temp, 3);
        n = n / 10;
    }

    return num == armNum;
}

// Division
void div(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";
        }
    }
}

bool isPrime(int n)
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
            cnt++;
    }
    return (cnt == 2);
}

// GCD
// gcd(a,b) = gcd(a%b, b)
int gcd(int a, int b)
{
    while (a > 0 && b > 0)
    {
        if (a > b)
            a = a % b;
        else
            b = b % a;
    }
    if (a == 0)
        return b;
}

int main()
{
    int n;
    cin >> n;
    // div(n);
    cout << isPrime(n) << endl;
    return 0;
}