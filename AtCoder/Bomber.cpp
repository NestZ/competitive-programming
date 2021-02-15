#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, cnt;cin >> n >> m >> cnt;
	int mx_r = 0;
	int mx_c = 0;
	int cnt_mx_r = 0;
	int cnt_mx_c = 0;
	vector<int> cnt_r(n);
	vector<int> cnt_c(m);
	vector<pair<int, int>> p;
	for(int i = 0;i < cnt;i++){
		int h, w;cin >> h >> w;
		h--;w--;
		p.emplace_back(h, w);
		cnt_r[h]++;
		cnt_c[w]++;
		if(cnt_r[h] > mx_r){
			cnt_mx_r = 1;
			mx_r = cnt_r[h];
		}
		else if(cnt_r[h] == mx_r)cnt_mx_r++;
		if(cnt_c[w] > mx_c){
			cnt_mx_c = 1;
			mx_c = cnt_c[w];
		}
		else if(cnt_c[w] == mx_c)cnt_mx_c++;
	}
	int same = 0;
	for(int i = 0;i < cnt;i++){
		int h = p[i].first;
		int w = p[i].second;
		if(cnt_r[h] == mx_r && cnt_c[w] == mx_c)
			same++;
	}
	int ans = mx_r + mx_c;
	if(same == cnt_mx_r * cnt_mx_c)ans--;
	cout << ans << endl;
}
