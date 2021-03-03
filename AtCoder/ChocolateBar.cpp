#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll h, w;cin >> h >> w;
	ll ans = INT64_MAX;
	for(ll i = 1;i < w;i++){
		ll l_area = i * h;
		ll cur_ans = INT64_MAX;
		{
			ll ru_area = (w - i) * (h / 2);
			ll rd_area = (w - i) * ((h + 1) / 2);
			cur_ans = max({l_area, ru_area, rd_area}) -
					min({l_area, ru_area, rd_area});
		}
		{
			ll rr_area = h * ((w - i) / 2);
			ll rl_area = h * ((w - i + 1) / 2);
			cur_ans = min(cur_ans, max({l_area, rr_area, rl_area}) -
					min({l_area, rr_area, rl_area}));
		}
		ans = min(ans, cur_ans);
	}
	for(ll i = 1;i < h;i++){
		ll u_area = i * w;
		ll cur_ans = INT64_MAX;
		{
			ll dl_area = (h - i) * (w / 2);
			ll dr_area = (h - i) * ((w + 1) / 2);
			cur_ans = max({u_area, dl_area, dr_area}) -
					min({u_area, dl_area, dr_area});
		}
		{
			ll du_area = w * ((h - i) / 2);
			ll dd_area = w * ((h - i + 1) / 2);
			cur_ans = min(cur_ans, max({u_area, du_area, dd_area}) -
					min({u_area, du_area, dd_area}));
		}
		ans = min(ans, cur_ans);
	}
	cout << ans << endl;
}
