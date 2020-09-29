#include<bits/stdc++.h>

using namespace std;
#define ll long long

int main(){
	int n;cin >> n;
	vector<ll> arr(n);
	vector<ll> pre(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	unordered_set<ll> s;
	ll ans = 0;
	for(int i = 0;i < n;i++){
		if(i > 0)pre[i] = arr[i] + pre[i - 1];
		else pre[i] = arr[i];
		if(pre[i] == 0 || s.count(pre[i]) > 0){
			ans++;
			s.clear();
			pre[i] = arr[i];
		}
		s.insert(pre[i]);
	}
	cout << ans;
}
