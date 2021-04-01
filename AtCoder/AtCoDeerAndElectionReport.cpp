#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;cin >> n;
	vector<pair<ll, ll>> arr;
	for(int i = 0;i < n;i++){
		ll a, b;cin >> a >> b;
		arr.emplace_back(a, b);
	}
	ll t = arr[0].first;
	ll a = arr[0].second;
	for(int i = 1;i < n;i++){
		ll fst = arr[i].first;
		ll snd = arr[i].second;
		if(fst == snd){
			t = a = max(t, a);
		}
		else{
			ll l = 0, r = 1e18 / max(fst, snd);
			ll res = INT64_MAX;
			while(l <= r){
				ll mid = l + (r - l) / 2;
				if(fst * mid >= t && snd * mid >= a){
					res = min(res, mid);
					r = mid - 1;
				}
				else l = mid + 1;
			}
			t = fst * res;
			a = snd * res;
		}
	}
	cout << t + a << endl;
}
