#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;cin >> s;
	string t;cin >> t;
	string ty;cin >> ty;
	int n = s.length();
	map<char, int> m;
	for(int i = 0;i < n;i++)m[s[i]] = i;
	int len = ty.length();
	vector<char> ans;
	for(int i = 0;i < len;i++){
		if(tolower(ty[i]) > 'z' || tolower(ty[i]) < 'a')ans.push_back(ty[i]);
		else{
			int pos = m[tolower(ty[i])];
			if(islower(ty[i]))ans.push_back(t[pos]);
			else ans.push_back(toupper(t[pos]));
		}
	}
	for(char c : ans)cout << c;
}
