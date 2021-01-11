#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
int n, k, a, b;
vector<int> arr;

ll fuck(int mn, int mx){
	int pp_cnt = int(
								upper_bound(arr.begin(), arr.end(), mx)
								- lower_bound(arr.begin(), arr.end(), mn)
								);
	int l = mx - mn + 1;
	if(pp_cnt == 0)return (ll)a;
	ll des_cost = (ll)b * (ll)pp_cnt * (ll)l;
	if(l > 1){
		int fst = mn + (mx - mn) / 2;
		int snd = fst + 1;
		des_cost = min(des_cost, fuck(mn, fst) + fuck(snd, mx));
	}
	return des_cost;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k >> a >> b;
	for(int i = 0;i < k;i++){
		int t;cin >> t;
		arr.emplace_back(t);
	}
	sort(arr.begin(), arr.end());
	cout << fuck(1, pow(2, n)) << endl;
}
