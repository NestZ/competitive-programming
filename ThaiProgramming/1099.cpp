#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int r, g;cin >> r >> g;
	set<tuple<int, int, int>> ans;
	int gcd = __gcd(r, g);
	for(int i = 1;i * i <= gcd;i++){
		if(gcd % i == 0){
			int friends = i;
			int num_r = r / i;
			int num_g = g / i;
			ans.insert(make_tuple(friends, num_r, num_g));
			int mir = gcd / i;
			friends = mir;
			num_r = r / mir;
			num_g = g / mir;
			ans.insert(make_tuple(friends, num_r, num_g));
		}
	}
	for(tuple<int, int, int> t : ans){
		cout << get<0>(t) << ' ' << get<1>(t) << ' ' << get<2>(t) << endl;
	}
}
