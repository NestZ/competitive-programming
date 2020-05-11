#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		string s;cin >> s;
		int n = s.length();
		sort(s.begin(), s.end());
		bool flag = false;
		for(int i = 0;i < n / 2;i++){
			if(s[i] != s[n - i - 1])flag = true;
		}
		if(flag)cout << s;
		else cout << -1;
		cout << endl;
	}
}
