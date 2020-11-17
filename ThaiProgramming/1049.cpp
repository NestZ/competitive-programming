#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;cin >> n >> m;
	int round = 0;
	vector<tuple<int, int, int>> mx(n + 10, make_tuple(0, 0, 0));
	vector<int> cnt(m + 10);
	for(int i = 0;i < n;i++){
		int num, l, s;cin >> num >> l >> s;
		int cur_slot_cnt = cnt[l];
		if(s > get<1>(mx[cur_slot_cnt]) ||
				(s == get<1>(mx[cur_slot_cnt]) &&
				l < get<2>(mx[cur_slot_cnt]))){
			mx[cur_slot_cnt] = make_tuple(num, s, l);
		}
		cnt[l]++;
		round = max(round, cnt[l]);
	}
	for(int i = 0;i < round;i++){
		cout << get<0>(mx[i]) << endl;
	}
}
