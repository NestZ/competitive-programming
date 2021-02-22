#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int tx, ty;cin >> tx >> ty;
	int n;cin >> n;
	vector<pair<int, int>> a;
	vector<pair<int, int>> b;
	vector<pair<int, int>> c;
	vector<pair<int, int>> d;
	for(int i = 0;i < n;i++){
		int x, y;cin >> x >> y;
		a.emplace_back(x, y);
	}
	for(int i = 0;i < n;i++){
		int x, y;cin >> x >> y;
		b.emplace_back(x, y);
	}
	for(int i = 0;i < n;i++){
		int x, y;cin >> x >> y;
		c.emplace_back(x, y);
	}
	for(int i = 0;i < n;i++){
		int x, y;cin >> x >> y;
		d.emplace_back(x, y);
	}
	vector<pair<pair<int, int>, pair<int, int>>> lower;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			auto fst = make_pair(c[i].first + d[j].first, c[i].second + d[j].second);
			auto snd = make_pair(i, j);
			lower.emplace_back(fst, snd);	
		}
	}
	sort(lower.begin(), lower.end());
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			int curx = a[i].first + b[j].first;
			int cury = a[i].second + b[j].second;
			int wx = tx - curx;
			int wy = ty - cury;
			auto want = make_pair(wx, wy);
			auto ind = make_pair(INT_MIN, INT_MIN);
			auto temp = make_pair(want, ind);
			auto fp = *lower_bound(lower.begin(), lower.end(), temp);
			int findi = fp.second.first;
			int findj = fp.second.second;
			if(fp.first.first == wx && fp.first.second == wy){
				cout << a[i].first << ' ' << a[i].second << endl;
				cout << b[j].first << ' ' << b[j].second << endl;
				cout << c[findi].first << ' ' << c[findi].second << endl;
				cout << d[findj].first << ' ' << d[findj].second << endl;
				return 0;
			}
		}
	}
}
