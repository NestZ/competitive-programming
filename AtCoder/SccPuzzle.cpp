#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll s, c;cin >> s >> c;
	if(c < s * 2)cout << c / 2 << endl;
	else{
		ll l = 0;
		ll h = c / 2;
		ll mx_s = 0;
		while(l <= h){
			ll mid = l + (h - l) / 2;
			ll rem_c = c - mid * 2;
			ll cur_s = s + mid;
			if(cur_s * 2 == rem_c){
				mx_s = cur_s;
				break;
			}
			else if(cur_s * 2 < rem_c){
				l = mid + 1;
				mx_s = max(mx_s, cur_s);
			}
			else h = mid - 1;
		}
		cout << mx_s << endl;
	}
}
