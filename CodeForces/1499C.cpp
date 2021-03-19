#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;cin >> t;
	while(t--){
		ll n;cin >> n;
		vector<ll> arr(n);
		for(int i = 0;i < n;i++)cin >> arr[i];
		ll cnto = 1;
		ll cnte = 1;
		ll mno = arr[1];
		ll mne = arr[0];
		ll sumo = arr[1];
		ll sume = arr[0];
		ll ans = arr[1] * n + arr[0] * n;
		for(int i = 2;i < n;i++){
			ll cur_ans = 0;
			if(i & 1){
				cnto++;
				sumo += arr[i];
				mno = min(mno, arr[i]);
			}
			else{
				cnte++;
				sume += arr[i];
				mne = min(mne, arr[i]);
			}
			cur_ans = mne * (n - (cnte - 1)) + (sume - mne);
			cur_ans += mno * (n - (cnto - 1)) + (sumo - mno);
			ans = min(ans, cur_ans);
		}
		cout << ans << endl;
	}
}
