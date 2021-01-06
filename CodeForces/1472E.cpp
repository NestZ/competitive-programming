#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

bool bigger(int h1, int w1, int h2, int w2){
	if(h1 > h2 && w1 > w2)return true;
	return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		vector<pair<int, int>> arr;
		vector<tuple<int, int, int>> p;
		vector<int> ans(n, -1);
		vector<int> pre_mn(n);
		for(int i = 0;i < n;i++){
			int h, w;cin >> h >> w;
			if(w < h)swap(w, h);
			arr.emplace_back(h, w);
			p.emplace_back(h, w, i + 1);
		}
		sort(p.begin(), p.end());
		int cur_mn = INT_MAX;
		for(int i = 0;i < n;i++){
			if(get<1>(p[i]) < cur_mn){
				cur_mn = get<1>(p[i]);
				pre_mn[i] = i;
			}
			else pre_mn[i] = pre_mn[i - 1];
		}
		for(int i = 0;i < n;i++){
			auto cur = arr[i];
			int l = 0;
			int r = n - 1;
			int mid = 0;
			int mx = INT_MIN;
			while(l <= r){
				mid = l + (r - l) / 2;
				if(cur.first > get<0>(p[mid])){
					l = mid + 1;
					mx = max(mx, mid);
				}
				else r = mid - 1;
			}
			if(mx != INT_MIN){
				if(bigger(cur.first, cur.second, 
						get<0>(p[pre_mn[mx]]), get<1>(p[pre_mn[mx]])))
					ans[i] = get<2>(p[pre_mn[mx]]);
			}
		}
		for(int i : ans)cout << i << ' ';
		cout << endl;
	}
}
