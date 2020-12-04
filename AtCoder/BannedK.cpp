#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<ll> cnt(n + 1, 0);
	vector<ll> arr(n);
	ll all = 0;
	for(int i = 0;i < n;i++){
		cin >> arr[i];
		cnt[arr[i]]++;
	}
	for(int i = 0;i <= n;i++){
		all += cnt[i] * (cnt[i] - 1) / 2;	
	}
	for(int i = 0;i < n;i++){
		cout << all - cnt[arr[i]] + 1 << endl;
	}
}
