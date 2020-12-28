#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, m;cin >> n >> m;
	vector<ll> arr(n);
	vector<pair<ll, ll>> rep;
	for(int i = 0;i < n;i++)cin >> arr[i];
	for(int i = 0;i < m;i++){
		ll b, c;cin >> b >> c;
		rep.emplace_back(c, b);
	}
	sort(arr.begin(), arr.end());
	sort(rep.rbegin(), rep.rend());
	int rep_ptr = 0;
	for(int i = 0;i < n && rep_ptr < m;i++){
		if(arr[i] >= rep[rep_ptr].first)break;
		arr[i] = rep[rep_ptr].first;
		rep[rep_ptr].second--;
		if(rep[rep_ptr].second == 0)rep_ptr++;
	}
	ll ans = 0;
	for(int i : arr)ans += i;
	cout << ans << endl;
}
