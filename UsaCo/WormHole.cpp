/*
ID: nestz
LANG: C++14
TASK: wormhole
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int N = 12;
int n;
vector<pair<int, int>> pos(N + 1);
vector<int> partner(N + 1, 0);
vector<int> next_r(N + 1, 0);

bool is_cycle(){
	for(int start = 1;start <= n;start++){
		int cur = start;
		for(int cnt = 0;cnt < n;cnt++){
			cur = next_r[partner[cur]];
		}
		if(cur != 0)return true;
	}
	return false;
}

int solve(){
	int ans = 0;
	int i;
	for(i = 1;i <= n;i++)
		if(partner[i] == 0)break;

	if(i > n){
		if(is_cycle())return 1;
		else return 0;
	};

	for(int j = i + 1;j <= n;j++){
		if(partner[j] == 0){
			partner[j] = i;
			partner[i] = j;
			ans += solve();
			partner[i] = partner[j] = 0;
		}
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("wormhole.out", "w", stdout);
	freopen("wormhole.in", "r", stdin);
	
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> pos[i].first >> pos[i].second;
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(pos[j].first > pos[i].first && pos[i].second == pos[j].second){
				if(next_r[i] == 0 || pos[j].first - pos[i].first < pos[next_r[i]].first - pos[i].first)
					next_r[i] = j;
			}
		}
	}
	cout << solve() << endl;
}
