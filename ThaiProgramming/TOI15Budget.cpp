#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;
vector<int> parent(3500, 0);
vector<int> rnk(3500, 0);

int find(int n){
	if(parent[n] != n)parent[n] = find(parent[n]);
	return parent[n];
}

void un(int x, int y){
	int xset = find(x);
	int yset = find(y);
	if(xset == yset)return;
	if(rnk[xset] < rnk[yset])parent[xset] = yset;
	else if(rnk[xset] > rnk[yset])parent[yset] = xset;
	else{
		parent[yset] = xset;
		rnk[xset] = rnk[xset] + 1;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int b, e;cin >> b >> e;
	vector<pair<int, int>> edge(e);
	vector<pair<int, int>> el(e);
	vector<pair<int, int>> cost(e);
	for(int i = 0;i < b;i++)parent[i] = i;
	for(int i = 0;i < e;i++){
		int s, t, len, isr;cin >> s >> t >> len >> isr;
		el[i] = make_pair(len, i);
		edge[i] = make_pair(s, t);
		if(isr == 1)cost[i] = make_pair(0, i);
		else cost[i] = make_pair(INT_MAX, i);
	}
	int p;cin >> p;
	vector<pair<int, int>> pack;
	for(int i = 0;i < p;i++){
		int d, c;cin >> d >> c;
		pack.emplace_back(d, c);
	}
	sort(pack.begin(), pack.end());
	vector<int> suf_min(p, INT_MAX);
	for(int i = p - 1;i >= 0;i--){
		suf_min[i] = min(suf_min[min(i + 1, p - 1)], pack[i].second);
	}
	for(int i = 0;i < e;i++){
		int curl = el[i].first;
		auto low = make_pair(curl, INT_MIN);
		auto ind = int(lower_bound(pack.begin(), pack.end(), low) - 
				pack.begin());
		cost[i].first = min(cost[i].first, suf_min[ind]);
	}
	sort(cost.begin(), cost.end());
	int ans = 0;
	for(int i = 0;i < e;i++){
		auto cur_cost = cost[i].first;
		auto cur_ind = cost[i].second;
		int fst = edge[cur_ind].first;
		int snd = edge[cur_ind].second;
		if(find(fst) != find(snd)){
			ans += cur_cost;
			un(fst, snd);
		}
	}
	cout << ans << endl;
}
