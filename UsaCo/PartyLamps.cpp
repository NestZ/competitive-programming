/*
ID: nestz
LANG: C++14
TASK: lamps
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

void flip(char &c){
	if(c == '1')c = '0';
	else c = '1';
}

bool match(string s1, string s2){
	int n = s1.length();
	for(int i = 0;i < n;i++){
		if(s1[i] == '*' || s1[i] == s2[i]) {}
		else return false;
	}
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("lamps.out", "w", stdout);
	freopen("lamps.in", "r", stdin);

	int n, cnt;cin >> n >> cnt;
	string final_lamp = string(n, '*');
	vector<pair<string, int>> possible_lamp;
	{
		set<int> on_lamp;
		set<int> off_lamp;
		int on;cin >> on;
		while(on != -1){
			on_lamp.insert(on);
			cin >> on;
		}
		int off;cin >> off;
		while(off != -1){
			off_lamp.insert(off);
			cin >> off;
		}
		for(int i = 1;i <= n;i++){
			if(on_lamp.count(i) > 0){
				final_lamp[i - 1] = '1';
			}
			else if(off_lamp.count(i) > 0){
				final_lamp[i - 1] = '0';
			}
		}
	}
	for(int i = 0;i < (1 << 4);i++){
		string cur = string(n, '1');
		for(int j = 0;j < 4;j++){
			if(i & (1 << j)){
				if(j == 0){
					for(int k = 0;k < n;k++)flip(cur[k]);
				}
				else if(j == 1){
					for(int k = 0;k < n;k++){
						if((k + 1) % 2 == 1)flip(cur[k]);
					}
				}
				else if(j == 2){
					for(int k = 0;k < n;k++){
						if((k + 1) % 2 == 0)flip(cur[k]);
					}
				}
				else{
					for(int k = 0;k < n;k++){
						if((k + 1) % 3 == 1)flip(cur[k]);
					}
				}
			}
		}
		possible_lamp.push_back(make_pair(cur, __builtin_popcount(i)));
	}
	if(cnt == 0){
		if(match(final_lamp, string(n, '1'))){
			cout << string(n, '1') << endl;
		}
		else cout << "IMPOSSIBLE" << endl;
	}
	else{
		set<string> ans;
		for(pair<string, int> p : possible_lamp){
			if(p.second == 0){
				if(cnt % 2 == 0 && match(final_lamp, p.first))ans.insert(p.first);
			}
			else{
				if(match(final_lamp, p.first) && (cnt % p.second == 2 || cnt % p.second == 0))
					ans.insert(p.first);
			}
		}
		if(ans.size() == 0)cout << "IMPOSSIBLE\n";
		else{
			for(string s : ans)cout << s << endl;
		}
	}
}
