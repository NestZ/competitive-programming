#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	string s, t;cin >> s >> t;
	int mx = 0;
	for(int i = 1;i <= n;i++){
		string s1 = s.substr(n - i, i);
		string s2 = t.substr(0, i);
		if(s1 == s2)mx = i;
	}
	cout << n * 2 - mx << endl;
}
