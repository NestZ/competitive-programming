#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	vector<int> arr(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	sort(arr.begin(), arr.end());
	for(int i = 0;i + 2 < n;i++){
		if(arr[i] + arr[i + 1] > arr[i + 2])return cout << "YES", 0;
	}
	cout << "NO";
}
