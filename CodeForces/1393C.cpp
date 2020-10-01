#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		ll n;cin >> n;
		ll mxcnt = 0;
		vector<ll> cnt(100005, 0);
		for(int i = 0;i < n;i++){
			ll num;cin >> num;
			cnt[num]++;
			mxcnt = max(mxcnt, cnt[num]);
		}
		ll same = 0;
		ll ns = 0;
		for(int i = 0;i < 100005;i++){
			if(cnt[i] > 0){
				if(cnt[i] == mxcnt)same++;
				else ns += cnt[i];
			}
		}
		cout << (same - 1) + (ns / (mxcnt - 1)) << endl;
	}
}
