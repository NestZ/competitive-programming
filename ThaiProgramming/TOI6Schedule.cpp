#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k, m;cin >> n >> k >> m;
	vector<bool> ac(n, true);
	vector<int> start(500002, -1);
	vector<vector<int>> end(500002);
	int sz = 0;
	for(int i = 0;i < n;i++){
		int s, e;cin >> s >> e;
		start[s] = i;
		end[e + 1].push_back(i);
	}
	for(int i = 1;i < 500001;i++){
		for(auto e : end[i]){
			if(ac[e])sz--;
		}
		if(start[i] != -1){
			if(sz < k)sz++;
			else ac[start[i]] = false;
		}
	}
	for(int i = 0;i < m;i++){
		int q;cin >> q;
		q--;
		if(!ac[q])cout << "N ";
		else cout << "Y ";
	}
	cout << endl;
}
