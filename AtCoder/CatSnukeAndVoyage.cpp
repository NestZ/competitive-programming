#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m;cin >> n >> m;
	set<int> adj1;
	vector<pair<int, int>> arr;
	for(int i = 0;i < m;i++){
		int a, b;cin >> a >> b;
		arr.emplace_back(a, b);
		if(a == 1)adj1.insert(b);
	}
	bool ans = false;
	for(int i = 0;i < m;i++){
		if(arr[i].second == n && adj1.count(arr[i].first) > 0)
			ans = true;
	}
	if(ans)cout << "POSSIBLE";
	else cout << "IMPOSSIBLE";
	cout << endl;
}
