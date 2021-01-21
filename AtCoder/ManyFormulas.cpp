#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;cin >> s;
	int n = s.length();
	ll ans = 0;
	for(int i = 0;i < (1 << (n - 1));i++){
		ll cur = 0;
		string cur_s = "";
		for(int j = 0;j < n - 1;j++){
			cur_s += s[j];
			if((1 << j) & i){
				cur += stoi(cur_s);
				cur_s = "";
			}
		}
		cur_s += s[n - 1];
		cur += stoll(cur_s);
		ans += cur;
	}
	cout << ans << endl;
}
