#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;cin >> n;
	int sx, sy, sz;cin >> sx >> sy >> sz;
	int m;cin >> m;
	int ans = INT_MAX;
	vector<tuple<int, int, int>> pos;
	vector<tuple<int, int, int>> cnt;
	vector<int> perm(m);
	for(int i = 0;i < m;i++)perm[i] = i;
	for(int i = 0;i < m;i++){
		int x, y, z;cin >> x >> y >> z;
		int ms, k, c;cin >> ms >> k >> c;
		pos.emplace_back(x, y, z);
		cnt.emplace_back(ms, k, c);
	}
	do{
		int wm = n;
		int wk = n;
		int wc = n;
		int lstx = sx;
		int lsty = sy;
		int lstz = sz;
		int cur_cost = 0;
		for(int i = 0;i < m;i++){
			int curx = get<0>(pos[perm[i]]);
			int cury = get<1>(pos[perm[i]]);
			int curz = get<2>(pos[perm[i]]);
			int fst = curx - lstx;
			int snd = cury - lsty;
			int trd = curz - lstz;
			cur_cost += fst * fst + snd * snd + trd * trd;
			wm -= min(wm, get<0>(cnt[perm[i]]));
			wk -= min(wk, get<1>(cnt[perm[i]]));
			wc -= min(wc, get<2>(cnt[perm[i]]));
			if(max({wm, wk, wc}) == 0)break;
			lstx = curx;
			lsty = cury;
			lstz = curz;
		}
		ans = min(ans, cur_cost);
	}while(next_permutation(perm.begin(), perm.end()));
	cout << ans << endl;
}
