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

// Liner search
int find(int arr[], int n, int num)
{
    for (int i = 0; i <= n - 1; i++)
    {
        if (arr[i] == num)
            return i;
    }
    return -1;
}

// Union of two array
set<int> unionFun(int arrayA[], int arrayB[], int n1, int n2)
{
    set<int> unionArray;
    for (int i = 0; i <= n1 - 1; i++)
        unionArray.insert(arrayA[i]);
    for (int i = 0; i <= n2 - 1; i++)
        unionArray.insert(arrayB[i]);

    return unionArray;
}

vector<int> unionFun2(int arrayA[], int arrayB[], int n1, int n2)
{
    int i = 0;
    int j = 0;
    vector<int> newArray;
    while (i < n1 && j < n2)
    {
        if (arrayA[i] <= arrayB[j])
        {
            if (newArray.size() == 0 || newArray.back() != arrayA[i])
                newArray.push_back(arrayA[i]);
            i++;
        }
        else
        {
            if (newArray.size() == 0 || newArray.back() != arrayB[j])
                newArray.push_back(arrayB[j]);
            j++;
        }
    }
    while (i < n1)
    {
        if (newArray.size() == 0 || newArray.back() != arrayA[i])
            newArray.push_back(arrayA[i]);
        i++;
    }
    while (j < n2)
    {
        if (newArray.size() == 0 || newArray.back() != arrayB[j])
            newArray.push_back(arrayB[j]);
        j++;
    }
    return newArray;
}
int main()
{
    int n1, n2;
    cout << "Enter size of first array: ";
    cin >> n1;
    int arrA[n1];
    cout << "Enter elements of first array: ";
    for (int i = 0; i < n1; i++)
        cin >> arrA[i];

    cout << "Enter size of second array: ";
    cin >> n2;
    int arrB[n2];
    cout << "Enter elements of second array: ";
    for (int i = 0; i < n2; i++)
        cin >> arrB[i];

    vector<int> uni = unionFun2(arrA, arrB, n1, n2);
    cout << "Union: ";
    for (int x : uni)
        cout << x << " ";
    cout << endl;
    return 0;
}