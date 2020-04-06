#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	int ans = 0;
	vector<int> arr(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	for(int i = 0;i < n;i++){
		ans += *max_element(arr.begin(), arr.end()) - arr[i];
	}
	cout << ans;
}
