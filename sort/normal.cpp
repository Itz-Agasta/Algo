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
int main()
{
    // Input
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Fn call
    insertion_sort(arr, n);

    // Output;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}