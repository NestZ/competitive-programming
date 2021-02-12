#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q, k;cin >> n >> q >> k;
	vector<int> arr(n);
	vector<ll> cnt(n);
	vector<ll> pre(n + 1);
	for(int i = 0;i < n;i++)cin >> arr[i];
	for(int i = 0;i < n;i++){
		if(i == 0){
			int d = arr[i] - 1;
			int u = arr[i + 1] - arr[i] - 1;
			cnt[i] = d + u;
		}
		else if(i == n - 1){
			int d = arr[i] - arr[i - 1] - 1;
			int u = k - arr[i];
			cnt[i] = d + u;
		}
		else{
			int d = arr[i] - arr[i - 1] - 1;
			int u = arr[i + 1] - arr[i] - 1;
			cnt[i] = d + u;
		}
	}
	for(int i = 1;i <= n;i++){
		pre[i] = cnt[i - 1] + pre[i - 1];
	}
	for(int i = 0;i < q;i++){
		int l, r;cin >> l >> r;
		if(n == 1)cout << k - 1 << endl;
		else{
			ll bl = arr[l - 1] - 1;
			ll br = k - arr[r - 1];
			if(l > 1)bl -= arr[l - 1] - arr[l - 2] - 1;
			else if(l == 1)bl -= arr[l - 1] - 1;
			if(r < n)br -= arr[r] - arr[r - 1] - 1;
			else if(r == n)br -= k - arr[r - 1];
			cout << pre[r] - pre[l - 1] + bl + br << endl;
		}
	}
}
