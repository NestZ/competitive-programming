#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;cin >> t;
	for(int q = 1;q <= t;q++){
		int n, c;cin >> n >> c;
		cout << "Case #" << q << ": ";
		if(c < n - 1 || c > n * (n + 1) / 2 - 1)
			cout << "IMPOSSIBLE" << endl;
		else{
			vector<int> ans(n);
			int l = 0;
			int r = n - 1;
			bool curl = true;
			for(int i = 0;i < n - 1;i++){
				int sw = n - i;
				int rem = n - 2 - i;
				if(c - sw >= rem){
					c -= sw;
					if(curl)ans[r--] = i + 1;
					else ans[l++] = i + 1;
					curl = !curl;
				}
				else{
					c--;
					if(curl)ans[l++] = i + 1;
					else ans[r--] = i + 1;
				}
			}
			if(curl)ans[l++] = n;
			else ans[r--] = n;
			for(int i : ans)cout << i << ' ';
			cout << endl;
		}
	}
}
