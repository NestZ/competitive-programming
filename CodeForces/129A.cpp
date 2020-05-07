#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	int sum = 0;
	vector<int> arr(n);
	for(int i = 0;i < n;i++){
		cin >> arr[i];
		sum += arr[i];
	}
	int ans = 0;
	for(int i = 0;i < n;i++){
		if((sum - arr[i]) % 2 == 0)ans++;
	}
	cout << ans;
}
