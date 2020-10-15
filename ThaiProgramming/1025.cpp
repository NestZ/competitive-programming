#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

vector<ll> arr(100005, 0);

void fac(ll num){
	map<ll, ll> f;
	for(ll i = 2;i * i <= num;i++){
		while(num % i == 0ll){
			f[i]++;
			num /= i;
		}
	}
	if(num > 1ll)f[num]++;
	for(pair<ll, ll> p : f){
		arr[p.first] = max(arr[p.first], p.second);
	}
}

int main(){
	int n;cin >> n;
	vector<ll> temp;
	for(int i = 0;i < n;i++){
		ll t;cin >> t;
		temp.push_back(t);
		if(t > 1ll)fac(t);
	}
	ll ans = 1;
	for(ll i = 1;i < 100001ll;i++){
		if(arr[i] > 0ll)ans *= pow(i, arr[i]);
	}
	cout << ans;
}
