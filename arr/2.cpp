#include <bits/stdc++.h>
using namespace std;

// left rotation
void left_by1(int arr[], int n)
{
    int temp = arr[0];
    for (int i = 1; i <= n - 1; i++)
    {
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = temp;
}

// left rotate by D
void left_byD(int arr[], int n, int d)
{
    // // brute force
    // //  [1, 2 , 3 ,4,5, 6] d=3
    // d = d % n;
    // int temp[d];
    // for (int i = 0; i <= d - 1; i++)
    //     temp[i] = arr[i]; // [1,2,3]

    // // shift
    // for (int i = d; i <= n - 1; i++)
    // {
    //     arr[i - d] = arr[i]; // 3 --> 0; 4 ---> 1 so (i-d)
    // }
    // // join
    // int j = 0;
    // for (int i = n - d; i <= n - 1; i++)
    // {
    //     arr[i] = temp[j]; // temp[i-(n-d)]
    //     j++;
    // }

    // optimize
    reverse(arr, arr + d);
    reverse(arr + d, arr + n);
    reverse(arr, arr + n);
}

// Right by D
void right_byD(int arr[], int n, int d)
// same logic as left
{
    reverse(arr + d, arr + n);
    reverse(arr, arr + d);
    reverse(arr, arr + n);
}

// Move all 0 to last
void removeZero(int arr[], int n)
{
    // // TC ==O(2N)   sc == O(n)
    // // s1--> store all non zero in a temp array
    // vector<int> temp;
    // for (int i = 0; i <= n - 1; i++)
    // {
    //     if (arr[i] != 0)
    //         temp.push_back(arr[i]);
    // }

    // // s2--> fill the array again with teh temp element
    // int nz = temp.size();
    // for (int i = 0; i < nz; i++)
    // {
    //     arr[i] = temp[i];
    // }

    // // s3 --> we know the size is n so fill teh others with zero
    // for (int i = nz; i < n; i++)
    // {
    //     arr[i] = 0;
    // }

    // optimized
    // TC = O(n) sc == O(1)
    // s1 --> find teh 1st zeo in the array
    int j = -1;
    for (int i = 0; i <= n - 1; i++)
    {
        if (arr[i] == 0)
        {
            j = i;
            break;
        }
    }

    // s2 --> lets go from j+1 and swap non zeros with zero's place
    for (int i = j + 1; i <= n - 1; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i <= n - 1; i++)
        cin >> arr[i];
    // fn call
    int d;
    cin >> d;
    removeZero(arr, n);
    for (int i = 0; i <= n - 1; i++)
        cout << arr[i] << " ";
}