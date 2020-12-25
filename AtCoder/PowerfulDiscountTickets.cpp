#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, m;cin >> n >> m;
	priority_queue<ll> q;
	for(int i = 0;i < n;i++){
		ll num;cin >> num;
		q.push(num);
	}
	ll ans = 0;
	for(int i = 0;i < m;i++){
		ll fst = q.top();
		q.pop();
		fst >>= 1;
		q.push(fst);
	}
	while(!q.empty()){
		ans += q.top();
		q.pop();
	}
	cout << ans << endl;
}
