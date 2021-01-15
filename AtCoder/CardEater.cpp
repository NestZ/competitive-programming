#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;cin >> n;
	map<int, int> m;
	for(int i = 0;i < n;i++){
		int t;cin >> t;
		m[t]++;
	}
	int cnt = 0;
	for(auto p : m){
		if(p.second % 2 == 0)cnt++;
	}
	if(cnt % 2 == 0)cout << m.size();
	else cout << m.size() - 1;
	cout << endl;
}
