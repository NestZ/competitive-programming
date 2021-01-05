#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;cin >> t;
	while(t--){
		ll n, x;cin >> n >> x;
		ll ans = 0;
		ll mn = INT64_MAX;
		ll mni = -1;
		vector<ll> arr(n);
		vector<ll> cnt(n);
		for(int i = 0;i < n;i++){
			cin >> arr[i];
			ans += arr[i];
		}
		for(int i = 0;i < n;i++){
			ll temp = arr[i];
			while(temp % x == 0){
				cnt[i]++;
				temp /= x;
			}
			if(cnt[i] < mn){
				mn = cnt[i];
				mni = i;
			}
		}
		for(int i = mni + 1;i < n;i++){
			cnt[i] = min(cnt[i], mn);
		}
		for(int i = 0;i < mni;i++){
			cnt[i] = min(cnt[i], mn + 1);
		}
		for(int i = 0;i < n;i++){
			ans += cnt[i] * arr[i];
		}
		cout << ans << endl;
	}
}
