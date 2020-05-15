#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n;cin >> n;
	vector<ll> a(n);
	vector<ll> b(n);
	ll sum = 0;
	for(int i = 0;i < n;i++){
		cin >> a[i];
		sum += a[i];
	}
	for(int i = 0;i < n;i++)cin >> b[i];
	sort(b.rbegin(), b.rend());
	if(b[0] + b[1] < sum)cout << "NO";
	else cout << "YES";
}
