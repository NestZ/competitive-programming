#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	map<int, int> m;
	int mx = 0;
	for(int i = 0;i < n;i++){
		int t;cin >> t;
		m[t]++;
		mx = max(mx, m[t]);
	}
	cout << mx;
}
