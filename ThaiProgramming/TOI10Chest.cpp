#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;
vector<int> cnt(10, 0);

void factor(int num, int sign){
	for(int i = 2;i * i <= num;i++){
		while(num % i == 0){
			cnt[i] += sign * 1;
			num /= i;
		}
	}
	if(num > 1)cnt[num] += sign * 1;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int m, n;cin >> m >> n;
	vector<pair<int, pair<int, int>>> arr;
	for(int i = 0;i < m;i++){
		int x, s, t;cin >> x >> s >> t;
		arr.push_back({s, {1, x}});
		arr.push_back({t + 1, {-1, x}});
	}
	sort(arr.begin(), arr.end());
	ll mx = 1, mx_cnt = max(0, arr[0].first - 1);
	int len = arr.size();
	for(int i = 0;i < len;i++){
		int num = arr[i].second.second;
		int sign = arr[i].second.first;
		factor(num, sign);
		ll cur_cnt = 1;
		for(int j = 0;j < 10;j++){
			cur_cnt *= cnt[j] + 1;
		}
		if(cur_cnt > mx){
			mx = cur_cnt;
			mx_cnt = arr[i + 1].first - arr[i].first;
		}
		else if(cur_cnt == mx){
			mx_cnt += arr[i + 1].first - arr[i].first;
		}
	}
	cout << mx << ' ' << mx_cnt << endl;
}
