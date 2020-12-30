#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
string st[] = {"dream", "dreamer", "erase", "eraser"};
string s;

bool dfs(int n){
	for(int i = 0;i < 4;i++){
		string cut = s.substr(n, s.length() - n);
		if(st[i] == cut)return true;
	}
	for(int i = 0;i < 4;i++){
		string cut = s.substr(n, st[i].length());
		if(st[i] == cut)
			if(dfs(n + cut.length()))
				return true;
	}
	return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> s;
	if(dfs(0))cout << "YES";
	else cout << "NO";
	cout << endl;
}
