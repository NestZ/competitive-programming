#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;cin >> n >> k;
	string s;cin >> s;
	char last = s[0];
	int cnt = 1;
	int ans = 0;
	for(int i = 1;i < n;i++){
		if(last != s[i])cnt++;
		if(s[i] == s[i - 1])ans++;
		last = s[i];
	}
	if(k >= cnt / 2)cout << n - 1;
	else cout << ans + k * 2;
	cout << endl;
}
