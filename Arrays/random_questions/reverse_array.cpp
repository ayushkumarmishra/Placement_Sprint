#include <bits/stdc++.h>

using namespace std;

vector<int> reverse_arr(vector<int> arr) {
	int n = arr.size();
	vector<int> temp;
	for (int i = n ; i > 0; i--) {
		cout << "=========>" << arr[i - 1];
		cout << "nreegong";
		temp[n - i] = arr[i - 1];
		cout <<  "=========>" << temp[n - i] << endl;
	}
	return temp;
}

int main()
{
	vector<int> arr = {10, 5, 7, 30};
	arr = reverse_arr(arr);
	for (int i = 0 ; i < arr.size() ; i++)
		cout << arr[i] << " ";
	cout << endl;
}