#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	map<int, int> m;
	for(int i = 0;i < n;i++){
		int t;cin >> t;
		for(int j = 0;j < t;j++){
			int k;cin >> k;
			m[k]++;
		}
	}
	for(pair<int, int> p : m){
		if(p.second == n)cout << p.first << ' ';
	}
}
