#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;cin >> s;
	int n = s.length();
	set<char> all;
	for(int i = 0;i < n;i++)all.insert(s[i]);
	if(all.size() < 26){
		for(char c = 'a';c <= 'z';c++){
			if(all.count(c) == 0)
				return cout << (s += c) << endl, 0;
		}
	}
	else{
		set<char> cur;
		int fst = INT_MIN;
		char rep = '\0';
		for(int i = 0;i < n;i++){
			for(char c = char(s[i] + 1);c <= 'z';c++){
				if(cur.count(c) == 0){
					fst = max(fst, i);
					rep = c;
					break;
				}
			}
			cur.insert(s[i]);
		}
		if(fst == INT_MIN)cout << -1;
		else{
			s[fst] = rep;
			s = s.substr(0, fst + 1);
			cout << s;
		}
		cout << endl;
	}
}
