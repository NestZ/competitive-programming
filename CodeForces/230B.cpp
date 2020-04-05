#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll N = 1000005;
vector<bool> pr(N + 1, true);
set<ll> s;
void pre(){
	for(ll i = 2;i < N;i++){
		if(pr[i]){
			s.insert(i * i);
			for(ll j = i * i;j <= N;j += i)pr[j] = false;
		}
	}
}

int main(){
	pre();
	ll n;cin >> n;
	while(n--){
		ll t;cin >> t;
		if(s.count(t) > 0)cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
