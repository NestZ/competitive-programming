#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		ll def = 1;
		bool z = false;
		vector<ll> p;
		vector<ll> ne;
		for(int i = 0;i < n;i++){
			ll temp;cin >> temp;
			if(temp > 0)p.push_back(temp);
			else if(temp < 0)ne.push_back(temp);
			else z = true;
			def *= temp;
		}
		sort(p.rbegin(), p.rend());
		sort(ne.begin(), ne.end());
		ll ans = INT64_MIN;
		if(n == 5){
			ans = def;
		}
		if(ne.size() >= 5){
			ll temp = 1;
			for(int i = int(ne.size()) - 1;i > int(ne.size()) - 6;i--)temp *= ne[i];
			ans = max(ans, temp);
		}
		for(int i = 0;i <= 4;i+=2){
			ll temp = 1;
			if(int(ne.size()) < i || int(p.size()) < 5 - i)continue;
			for(int j = 0;j < i;j++){
				temp *= ne[j];	
			}
			for(int j = 0;j < 5 - i;j++){
				temp *= p[j];
			}
			ans = max(ans, temp);
		}
		if(z)ans = max(0ll, ans);
		cout << ans << endl;
	}
}
