#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	vector<int> arr(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	sort(arr.begin(), arr.end());
	int ans = 0;
	for(int i = 0;i < n;i += 2){
		ans += abs(arr[i] - arr[i + 1]);
	}
	cout << ans;
}
