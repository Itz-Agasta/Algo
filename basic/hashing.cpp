#include <bits/stdc++.h>
using namespace std;
// Count a num appear in a arr
// force
int force()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int num;
    cin >> num;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == num)
            cnt++;
    }
    return cnt;
}

void appare()
{ // Take the arr values
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Hasing precompute
    int hash[13] = {0}; // here used 13 but max size of arr given... here assume max size 12
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]] += 1;
    }

    // Take ans input
    int q;
    cin >> q;
    while (q--)
    {
        int num;
        cin >> num;
        // Fetch
        cout << hash[num] << endl;
    }
}

// Map appare
void mapAppare()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Fetch
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
        mpp[arr[i]]++;

    // Input & Output
    int q;
    cin >> q;
    while (q--)
    {
        int num;
        cin >> num;
        cout << mpp[num] << endl;
    }
}

void sAppare()
{
    string s;
    cin >> s;

    // Hashing precompute
    int hash[26] = {0};
    for (size_t i = 0; i < s.size(); i++)
    {
        hash[s[i] - 'a'] += 1;
    }
    // input query
    int q;
    cin >> q;
    while (q--)
    {
        char c;
        cin >> c;
        cout << hash[c - 'a'] << endl;
    }
}

void sMap()
{
    string s;
    cin >> s;

    // Fetch
    unordered_map<char, int> mpp;
    for (size_t i = 0; i < s.size(); i++)
    {
        mpp[s[i]]++;
    }

    // i&o
    int q;
    cin >> q;
    while (q--)
    {
        char c;
        cin >> c;
        cout << mpp[c] << endl;
    }
}

int main()
{
    sMap();
    return 0;
}