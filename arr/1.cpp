#include <bits/stdc++.h>
using namespace std;

// Find the largest num in an array
// [1,22, 43 , 24, 21, 45, 24]
void sLargest(int arr[], int n)
{
    // // brute ---> sort & take the n-1
    // for (int i = 0; i <= n - 2; i++)
    // {
    //     int min = i;
    //     for (int j = i; j <= n - 1; j++)
    //     {
    //         if (arr[j] < arr[min])
    //             min = j;
    //     }
    //     int temp;
    //     temp = arr[i];
    //     arr[i] = arr[min];
    //     arr[min] = temp;
    // }
    // // sort dont now print n-1
    // int sLargest;
    // for (int i = n - 1; i >= 0; i--)
    // {
    //     if (arr[i] != arr[n - 1] && arr[i] < arr[n - 1])
    //     {
    //         sLargest = arr[i];
    //         break;
    //     }
    // }
    // cout << sLargest << endl;

    // Optimized
    int largest = arr[0];
    int sLargest = -1;

    for (int i = 1; i <= n - 1; i++)
    {
        if (arr[i] > largest)
        {
            sLargest = largest;
            largest = arr[i];
        }
        // if we find a i large than largest but small than sLargest
        else if (arr[i] < largest && arr[i] > sLargest)
            sLargest = arr[i];
    }
    cout << largest << " " << sLargest << endl;
}

void remove(int arr[], int n)
{
    // // Brute --> want to remove copies so lets use a set
    // set<int> st;
    // for (int i = 0; i <= n - 1; i++)
    // {
    //     st.insert(arr[i]);
    // }
    // // push the set content to the array again
    // int index = 0;
    // for (auto it : st)
    // {
    //     arr[index] = it;
    //     index++;
    // }

    // optimized
    int i = 0;
    for (int j = 1; j <= n - 1; j++)
    {
        if (arr[i] != arr[j])
        {
            arr[i + 1] = arr[j];
            i++;
        }
    }
}

// check if array is sorted
bool isSorted(int arr[], int n)
{
    for (int i = 1; i <= n - 1; i++)
    {
        if (arr[i - 1] > arr[i])

            return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if (isSorted(arr, n))
        cout << "Array is sorted" << endl;
    else
        cout << "Array is not sorted" << endl;

    return 0;
}