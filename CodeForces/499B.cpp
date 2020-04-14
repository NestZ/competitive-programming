#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n, m;cin >> n >> m;
	map<string, string> ma;
	for(int i = 0;i < m;i++){
		string a, b;cin >> a >> b;
		ma[a] = b;
	}
	for(int i = 0;i < n;i++){
		string a;cin >> a;
		if(a.size() <= ma[a].size())cout << a;
		else cout << ma[a];
		cout << ' ';
	}
}
