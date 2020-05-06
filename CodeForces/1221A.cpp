#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		map<ll, ll> m;
		for(int i = 0;i < n;i++){
			ll k;cin >> k;
			m[k]++;
			bool flag = m[k] >= 2;
			while(flag && k != 2048LL){
				m[k] -= 2;
				m[k * 2]++;
				flag = m[k * 2] >= 2;
				k *= 2;
			}
		}
		if(m[2048] > 0)cout << "YES";
		else cout << "NO";
		cout << endl;
	}
}
