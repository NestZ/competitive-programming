#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;cin >> n >> m;
	set<int> s;
	for(int i = 0;i < n;i++){
		int k;cin >> k;
		for(int j = 0;j < k;j++){
			int t;cin >> t;
			s.insert(t);
		}
	}
	if(s.size() == m)cout << "YES";
	else cout << "NO";
}
