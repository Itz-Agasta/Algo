#include <bits/stdc++.h>
using namespace std;

/* Selection Sort
 * TC= O(n**2)------> sum of n natural num;
 * SC= O()
 */
void selection_sort(int arr[], int n)
{
    for (int i = 0; i <= n - 2; i++)
    {
        int min = i; // Assume index 0 is lowset & so on
        for (int j = i; j <= (n - 1); j++)
        {
            if (arr[j] < arr[min])
                min = j; // if our assume wrong --> swap the index
        }
        // swap arr acc new index
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

// Bubble sort
// TC= O(n**2)---> Avg, Worst | O(n) --> Best case (if arr is already sorted)
void bubble_sort(int arr[], int n)
{
    for (int i = n - 1; i >= 1; i--)
    {
        int isSorted = 1; // To get the best case O(n) --> we wont do a full array swap if its sorted
        for (int j = 0; j <= n - 2; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                isSorted = 0;
            }
        }
        if (isSorted)
            break;
    }
}

// Insertion Sort
// TC= O(n**2)--> Worst, Avg | O(n)--> Best
void insertion_sort(int arr[], int n)
{
    for (int i = 0; i <= n - 1; i++)
    {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;

            j--;
        }
    }
}

// Merge Sort
// Rule: divide & merge
// low high mid these are indexs
// TC= O(log2 n)
// SC= O(n)--> worst
void merge(vector<int> &arr, int low, int high, int mid)
{
    vector<int> temp;
    int left = low;      // [left.........mid]---> arr1
    int right = mid + 1; // [right......high]----> arr2

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(arr[left]);
        left++;
    }

    // Merge the two sorted array
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}
void merge_sort(vector<int> &arr, int low, int high)
{
    if (low == high)
        return;
    int mid = (high + low) / 2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);
    merge(arr, low, high, mid);
}

// Quick sort
// TC= O(Nlogn)
// SC = O(1)
int findP(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;
    while (i < j)
    {
        while (arr[i] <= pivot && i <= high - 1)
            i++;
        while (arr[j] > pivot && j >= low + 1)
            j--;
        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void quick_sort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pIndex = findP(arr, low, high);
        quick_sort(arr, low, pIndex - 1);
        quick_sort(arr, pIndex + 1, high);
    }
}
int main()
{
    // Input
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Fn call
    quick_sort(arr, 0, n - 1);

    // Output;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}