// /*

//  */
// #include <bits/stdc++.h>
// using namespace std;

// // Insertion sort
// /*
//     insertion sort worst case time complexity is O(n2)
//     It is an inplace algo
//     It is a stable algorithm
//     Used in practices for small arrays.
//     O(N) in best case.

// */

// void solve(int arr[], int n)
// {
//     for (int i = 1; i < n; i++)
//     {
//         int key = arr[i];
//         int j = i - 1;

//         while (j >= 0 && arr[j] > key)
//         {
//             arr[j + 1] = arr[j];
//             j--;
//         }
//         arr[j + 1] = key;
//     }
// }

// int main()
// {
//     solve();
//     return 0;
// }

// // Selection sort
// // It is a type of sorting algorithm which is used to sort the array in O(n2) time complexity and it traverse the array and find the minimum element and swap it to its correct position.

// for (int i = 0; i < n; i++)
// {
//     int mid_indx = i;

//     for (int j = i + 1; j < n; j++)
//     {
//         if (arr[j] < arr[mid_indx])
//         {
//             mid_indx = j;
//         }
//     }
//     swap(arr[mid_indx], arr[i]);
// }

// // Merge Sort Algorithm :

// // Is is a divide and conquer algorithm.
// // this is the by default sorting algorithm used in c++ stl.
// // worst case time complexity : O(nlogn)
// // It is a stabel algorithm
// // But it is not an inplace algrithm because it uses the extra array space to divide the array into two halfes.

// void merge(int arr[], int l, int h, int mid)
// {
//     int n1 = mid - l + 1;
//     int n2 = h - l;
//     int left[n1];
//     int right[n2];

//     for (int i = 0; i < n1; i++)
//         left[i] = arr[low + i];
//     for (int i = 0; i < n2; i++)
//         right[i] = arr[mid + 1 + i];

//     int i = 0, j = 0, k = 0;
//     while (i < n1 && j < n2)
//     {
//         if (left[i] < right[j])
//         {
//             arr[k] = left[i];
//             i++;
//             k++;
//         }
//         else if (left[i] > right[j])
//         {
//             arr[k] = right[i];
//             j++;
//             k++;
//         }
//     }
//     while (i < n1)
//     {
//         arr[k] = left[i];
//         i++;
//         k++;
//     }

//     whilej < n2
//     {
//         arr[k] = right[j];
//         j++;
//         k++;
//     }
// }

// void mergeSort(int arr[], int l, int h)
// {
//     while (r > l)
//     {
//         int mid = l + (r - l) / 2;

//         mergeSort(arr, l, mid);
//         mergeSort
//         arr, mid+1 , h);
//         merge(arr, l, h, mid);
//     }
// }