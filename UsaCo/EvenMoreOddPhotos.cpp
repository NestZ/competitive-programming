#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;cin >> n;
	int o = 0;
	int e = 0;
	for(int i = 0;i < n;i++){
		int t;cin >> t;
		if(t & 1)o++;
		else e++;
	}
	int mn = min(o, e);
	int ans = mn * 2;
	o -= mn;
	e -= mn;
	if(e > 0)ans++;
	else if(o > 0){
		ans += o / 3 * 2;
		if(o % 3 == 1)ans--;
		else if(o % 3 == 2)ans++;
	}
	cout << ans << endl;
}
