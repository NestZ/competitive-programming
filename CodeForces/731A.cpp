#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	string s;cin >> s;
	int n = s.size();
	int curr = 0;
	int ans = 0;
	for(int i = 0;i < n;i++){
		int t = s[i] - 'a';
		if(t > curr)ans += min(t - curr, curr + 26 - t);
		else ans += min(curr - t, t + 26 - curr);
		curr = t;
	}
	cout << ans;
}
