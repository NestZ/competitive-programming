#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

bool valid(string &s, string &t, int ind){
	int tn = t.length();
	for(int i = ind;i < ind + tn;i++){
		if(s[i] == '?')continue;
		if(s[i] != t[i - ind])return false;
	}
	return true;
}

string build(string &s, string &t, int ind){
	string ans = s;
	int tn = t.length();
	int n = ans.length();
	for(int i = ind;i < ind + tn;i++){
		ans[i] = t[i - ind];
	}
	for(int i = 0;i < n;i++){
		if(ans[i] == '?')ans[i] = 'a';
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s, t;cin >> s >> t;
	int sn = s.length();
	int tn = t.length();
	set<string> ans;
	for(int i = 0;i < sn - tn + 1;i++){
		if(valid(s, t, i)){
			string v = build(s, t, i);
			ans.insert(v);
		}
	}
	if(ans.size())cout << *ans.begin() << endl;
	else cout << "UNRESTORABLE\n";
}
