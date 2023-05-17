#include <bits/stdc++.h>
using namespace std;
int findPeakValue(int arr[], int length)
{
    int left = 0;
    int right = length - 1;
    if (length == 1)
    return arr[0];
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
            return arr[mid];
        else if (arr[mid] < arr[mid + 1])
            left = mid + 1;
        else if (arr[mid] > arr[mid + 1])
            right = mid - 1;
    }
    return arr[left];
}

int main()
{
    system("cls");
    int n;
    cout << "Enter array size: ";
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the " << i + 1 << " element of the array: ";
        cin >> arr[i];
    }
    int peak_value = findPeakValue(arr, n);
    cout << "\nThe peak value of the array is : " << peak_value << endl;
    return 0;
}