#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll gcd(ll a, ll b){
	return (b ? gcd(b, a % b) : a);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<ll> arr(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	ll mn = arr[0];
	for(int i = 1;i < n;i++){
		mn = gcd(mn, arr[i]);
	}
	int ans = 0;
	for(ll i = 1;i * i <= mn;i++){
		if(mn % i == 0){
			ans++;
			if(i != mn / i)ans++;
		}
	}
	cout << ans;
}
