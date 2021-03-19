#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;cin >> n >> m;
	int ans = 0;
	vector<set<int>> g(n + 1);
	vector<int> perm;
	for(int i = 2;i <= n;i++){
		perm.push_back(i);
	}
	for(int i = 0;i < m;i++){
		int a, b;cin >> a >> b;
		g[a].insert(b);
		g[b].insert(a);
	}
	do{
		int cur = 1;
		bool valid = true;
		for(int i : perm){
			if(g[cur].count(i) == 0){
				valid = false;
				break;
			}
			cur = i;
		}
		if(valid)ans++;
	}while(next_permutation(perm.begin(), perm.end()));
	cout << ans << endl;
}
