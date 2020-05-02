#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		ll n, m;cin >> n >> m;
		vector<ll> arr;
		ll curr = m;
		for(int i = 0;i < 10;i++){
			arr.push_back(curr % 10);
			curr = curr % 10 + m;
		}
		ll sum = 0;
		ll ans = 0;
		for(ll i : arr)sum += i;
		ll cnt = n / (m * 10);
		ans += sum * cnt;
		ll rem = n % (m * 10);
		ll temp = rem / m;
		for(ll i = 0;i < temp;i++){
			ans += arr[i];
		}
		cout << ans << endl;
	}
}
