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
		map<char, bool> m;
		for(int i = 'a';i <= 'z';i++)m[(char)i] = false;
		char lst = s[0];
		int cnt = 1;
		for(int i = 1;i < n;i++){
			if(s[i] == lst)cnt++;
			else{
				if(cnt & 1)m[lst] = true;
				lst = s[i];
				cnt = 1;
			}
		}
		if(cnt > 0)if(cnt & 1)m[lst] = true;
		for(pair<char, bool> p : m)if(p.second)cout << p.first;
		cout << endl;
	}
}
