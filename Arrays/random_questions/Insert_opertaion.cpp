// #include <bits/stdc++.h>
// using namespace std;

// int insertOperationFunctions(int arr[], int n, int cap, int pos, int x)
// {
//     n = n - 1;
//     pos = pos - 1;
//     while (pos < n)
//     {
//         arr[n] = arr[n - 1];
//         n--;
//     }
//     arr[n] = x;
//     return arr[pos];
// }

// int main()
// {
//     int *arr;
//     int cap;
//     int n;

//     // cout << "Enter the values inside the error" << endl;

//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     n = sizeof(arr) / sizeof(arr[0]);
//     // cout << "Enter the cap in the array" << endl;
//     cin >> cap;
//     int x = 0;
//     // cout << "Enter the value for the arrays" << endl;
//     cin >> x;
//     int pos = 0;
//     // cout << "Enter the array on which the element needs to get inserted" << endl;
//     cin >> pos;

//     cout << insertOperationFunctions(arr, n, cap, pos, x) << endl;
// }

#include <bits/stdc++.h>
using namespace std;

// Function to insert an element at a given position
int insertOperationFunctions(int arr[], int &n, int cap, int pos, int x)
{
    if (n >= cap) {
        cout << "Array is full" << endl;
        return -1; // Indicates an error
    }
    
    if (pos < 1 || pos > n + 1) {
        cout << "Invalid position" << endl;
        return -1; // Indicates an error
    }

    // Shift elements to the right to make space for the new element
    for (int i = n; i >= pos - 1; --i) {
        arr[i + 1] = arr[i];
    }

    // Insert the new element
    arr[pos - 1] = x;
    n++; // Increase the size of the array
    
    return arr[pos - 1];
}

int main()
{
    int cap;
    cout << "Enter the capacity of the array: ";
    cin >> cap;

    int* arr = new int[cap]; // Allocate memory for the array
    int n;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    if (n > cap) {
        cout << "Number of elements cannot be more than the capacity" << endl;
        delete[] arr;
        return 1;
    }

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int x;
    cout << "Enter the value to insert: ";
    cin >> x;

    int pos;
    cout << "Enter the position to insert the element: ";
    cin >> pos;

    int result = insertOperationFunctions(arr, n, cap, pos, x);

    if (result != -1) {
        cout << "Array after insertion: ";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    delete[] arr; // Free the allocated memory
    return 0;
}
