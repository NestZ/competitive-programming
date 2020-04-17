#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	map<string, int> m;
	int mx = 0;
	for(int i = 0;i < n;i++){
		string s;cin >> s;
		m[s]++;
		mx = max(mx, m[s]);
	}
	for(pair<string,int> p : m){
		if(p.second == mx)cout << p.first;
	}
}
