#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	string s;cin >> s;
	set<char> sc;
	for(int i = 0;i < n;i++)sc.insert(s[i]);
	int ans = n - sc.size();
	if(ans + sc.size() > 26)cout << -1;
	else cout << ans;
}
