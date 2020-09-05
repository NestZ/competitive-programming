#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

const int MAX = 1e6 + 10;
vector<int> BIT(MAX);
vector<vector<pair<int, int>>> event(MAX, vector<pair<int, int>>());
vector<vector<pair<int, int>>> query(MAX, vector<pair<int, int>>());

void add(int idx, int n){
	for(int i = idx;i <= MAX;i += (i & -i))BIT[i] += n;
}

int get(int idx){
	int res = 0;
	for(int i = idx;i > 0;i -= (i & -i))res += BIT[i];
	return res;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;cin >> n >> m;
	ll ans = 1;
	vector<tuple<int, int, int>> h(n);
	vector<tuple<int, int, int>> v(m);
	for(int i = 0;i < n;i++){
		int y, l, r;cin >> y >> l >> r;
		h[i] = make_tuple(l, r, y);
	}
	for(int i = 0;i < m;i++){
		int x, l, r;cin >> x >> l >> r;
		v[i] = make_tuple(l, r, x);
	}
	sort(h.begin(), h.end());
	for(auto it : h){
		if(get<1>(it) - get<0>(it) == 1000000)ans++;
		event[get<0>(it)].push_back({1, get<2>(it)});
		event[get<1>(it)].push_back({0, get<2>(it)});
	}
	for(auto it : v){
		query[get<2>(it)].push_back({get<0>(it), get<1>(it)});
	}
	for(int i = 0;i <= 1000000;i++){
		for(auto it : event[i]){
			if(it.first == 1)add(it.second + 1, 1);
		}
		for(auto it : query[i]){
			if(it.second - it.first == 1000000)ans++;
			ans += get(it.second + 1) - get(it.first);
		}
		for(auto it : event[i]){
			if(it.first == 0)add(it.second + 1, -1);
		}
	}
	cout << ans;
}
