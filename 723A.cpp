#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	vector<int> arr(3);
	for(int i = 0;i < 3;i++)cin >> arr[i];
	sort(arr.begin(), arr.end());
	cout << arr[1] - arr[0] + arr[2] - arr[1];
}
