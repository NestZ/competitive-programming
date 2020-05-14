#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		string s;cin >> s;
		string h;cin >> h;
		sort(s.begin(), s.end());
		int n = s.length();
		int m = h.length();
		bool flag = false;
		for(int i = 0;i < m - n + 1;i++){
			string k = h.substr(i, n);
			sort(k.begin(), k.end());
			if(k == s)flag = true;
		}
		if(flag)cout << "YES";
		else cout << "NO";
		cout << endl;
	}
}
