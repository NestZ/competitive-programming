#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		ll n, k;cin >> n >> k;
		vector<ll> arr(n);
		vector<ll> odd;
		for(ll i = 0;i < n;i++){
			cin >> arr[i];
			if(arr[i] & 1)odd.push_back(i);
		}
		if(((int)odd.size() < k) || (odd.size() - k) % 2 != 0)cout << "NO" << endl;
		else{
			cout << "YES" << endl;
			for(int i = 0;i < k - 1;i++)cout << odd[i] + 1 << ' ';
			cout << n;
			cout << endl;
		}
	}
}
