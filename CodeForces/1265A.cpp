#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		string s;cin >> s;
		string ss = "abc";
		bool flag = true;
		int n = s.length();
		for(int i = 0;i < n;i++){
			if(s[i] == '?'){
				for(int j = 0;j < 3;j++){
					bool temp = true;
					if(i > 0 && s[i - 1] == ss[j])temp = false;
					if(i < n - 1 && s[i + 1] == ss[j])temp = false;
					if(temp){
						s[i] = ss[j];
						break;
					}
				}
				if(s[i] == '?')flag = false;
			}
			if(i > 0 && s[i] == s[i - 1])flag = false;
		}
		if(flag)cout << s;
		else cout << -1;
		cout << endl;
	}
}
