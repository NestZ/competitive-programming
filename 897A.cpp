#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;cin >> n >> m;
	string s;cin >> s;
	for(int i = 0;i < m;i++){
		int f, t;cin >> f >> t;
		f--; t--;
		char from, to;cin >> from >> to;
		for(int j = f;j <= t;j++){
			if(s[j] == from)s[j] = to;
		}
	}
	cout << s;
}
