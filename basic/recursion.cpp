#include <bits/stdc++.h>
using namespace std;

// Print name 4 times
void name(int i, int n)
{
    if (i > n)
        return;
    cout << "agasta" << " ";
    cout << endl;
    name(i + 1, n);
}

// Print 1-->N
void printNum(int i, int n)
{
    if (i > n)
        return;
    cout << i;
    cout << endl;
    printNum(i + 1, n);
}

// i--->N (backtracking)
void backPrint(int i, int n)
{
    if (i < 1)
        return;
    backPrint(i - 1, n);
    cout << i << "";
}
// Print N----> 1
void printRev(int i, int n)
{
    if (i < n)
        return;
    cout << i << endl;
    printRev(i - 1, n);
}
void backRev(int i, int n)
{
    if (i > n)
        return;
    backRev(i + 1, n);
    cout << i << "";
}
// Sum of 1st N num
int sum(int i, int n)
{
    if (i > n)
        return 0;

    return i += sum(i + 1, n);
}

// Factorial
int fact(int i, int n)
{
    if (i > n)
        return 1; // This is not 0 ... or last 0* ans = 0
    return i *= fact(i + 1, n);
}

// int main()
// {
//     int n;
//     cin >> n;
//     cout << fact(1, n) << endl;
//     return 0;
// }

// Swap a Arr
void swapArr(int i, int n, int arr[])
{
    if (i >= n / 2)
        return;
    swap(arr[i], arr[n - i - 1]);
    swapArr(i + 1, n, arr);
}

// int main()
// {
//     int n;
//     cin >> n;
//     int arr[n];
//     // Input the arr
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     // swap
//     swapArr(0, n, arr);
//     // Print arr
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }
// SC, TC = O(n)
// Pal
bool isPal(size_t i, string &s) // If not "&" the space and time complexity will inc to O(2**n)
{
    if (i >= s.size() / 2)
        return true;
    if (s[i] != s[s.size() - i - 1])
        return false;
    return isPal(i + 1, s);
}

// int main()
// {
//     string s = "madam";
//     if (isPal(0, s))
//         cout << "yes";
//     else
//         cout << "no";
// }

// Fibonaci using Recursion
// TC = o(2**n)
int fibo(int n)
{
    if (n <= 1)
        return n;
    int lastNum = fibo(n - 1);
    int sLastNum = fibo(n - 2);
    return lastNum + sLastNum;
}

int main()
{
    int n;
    cin >> n;
    cout << fibo(n) << "";
    return 0;
}