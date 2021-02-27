#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int h, w, d;cin >> h >> w >> d;
	vector<pair<int, int>> m(h * w + 1);
	vector<int> pre(h * w + 1, 0);
	for(int i = 0;i < h;i++){
		for(int j = 0;j < w;j++){
			int num;cin >> num;
			m[num] = make_pair(i, j);
		}
	}
	for(int i = 1;i <= h * w;i++){
		if(i - d <= 0)continue;
		auto cur = m[i];
		auto prev = m[i - d];
		pre[i] = pre[i - d];
		pre[i] += abs(cur.first - prev.first) + abs(cur.second - prev.second);
	}
	int q;cin >> q;
	for(int i = 0;i < q;i++){
		int l, r;cin >> l >> r;
		cout << pre[r] - pre[l] << endl;
	}
}
