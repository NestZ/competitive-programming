#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string c;cin >> c;
	string w;cin >> w;
	int nc = c.length();
	int nw = w.length();
	map<char, int> m;
	for(int i = 0;i < nc;i++)m[c[i]] = i;
	int mx = -1;
	int ans = 1;
	for(int i = 0;i < nw;i++){
		if(m[w[i]] <= mx)ans++;
		mx = m[w[i]];
	}
	cout << ans << endl;
}
