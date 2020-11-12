#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<pair<int, int>> domino;
	for(int i = 0;i < n;i++){
		ll x, h;cin >> x >> h;
		domino.push_back(make_pair(x, h));
	}
	//0 = L, 1 = R
	int mx_cnt = 1;
	int ans_dir = 0;
	int ans_index = 0;
	int cur_index = n - 1;
	int cur_pos = domino[n - 1].first - domino[n - 1].second;
	int cur_cnt = 1;
	for(int i = n - 2;i >= 0;i--){
		int cur_x = domino[i].first;
		int cur_h = domino[i].second;
		if(cur_x > cur_pos){
			cur_cnt++;
			cur_pos = min(cur_pos, cur_x - cur_h);
			if(cur_cnt >= mx_cnt){
				mx_cnt = cur_cnt;
				ans_index = cur_index;
			}
		}
		else{
			cur_cnt = 1;
			cur_pos = cur_x - cur_h;
			cur_index = i;
		}
	}
	cur_cnt = 1;
	cur_pos = domino[0].first + domino[0].second;
	cur_index = 0;
	for(int i = 1;i < n;i++){
		int cur_x = domino[i].first;
		int cur_h = domino[i].second;
		if(cur_x < cur_pos){
			cur_cnt++;
			cur_pos = max(cur_pos, cur_x + cur_h);
			if(cur_cnt >= mx_cnt){
				if(cur_cnt == mx_cnt && cur_index >= ans_index)continue;
				mx_cnt = cur_cnt;
				ans_index = cur_index;
				ans_dir = 1;
			}
		}
		else{
			cur_cnt = 1;
			cur_pos = cur_x + cur_h;
			cur_index = i;
		}
	}
	cout << ans_index + 1 << ' ' << (ans_dir == 0 ? 'L' : 'R') << endl;
}
