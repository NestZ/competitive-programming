#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	map<string, int> m;
	string s;cin >> s;
	int mx = 0;
	for(int i = 0;i < n - 1;i++){
		string t = s.substr(i, 2);
		m[t]++;
		mx = max(mx, m[t]);
	}
	for(pair<string,int> p : m){
		if(p.second == mx){
			cout << p.first;
			break;
		}
	}
}
