#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, d;cin >> n >> d;
	vector<int> arr(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	int ans = 0;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			if(i == j)continue;
			if(abs(arr[i] - arr[j]) <= d)ans++;
		}
	}
	cout << ans;
}
