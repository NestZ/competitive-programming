#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<int> arr(n);
	int mx = 0;
	int ans = 0;
	int mn = INT_MAX;
	for(int i = 0;i < n;i++){
		cin >> arr[i];
		if(arr[mx] < arr[i])mx = i;
	}
	for(int i = 0;i < n;i++){
		if(i == mx)continue;
		if(abs(arr[mx] / 2 - arr[i]) < mn){
			mn = abs(arr[mx] / 2 - arr[i]);
			ans = arr[i];
		}
	}
	cout << arr[mx] << ' ' << ans << endl;
}
