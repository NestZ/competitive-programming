#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;cin >> t;
	for(int q = 1;q <= t;q++){
		int ans = 0;
		int n, k;cin >> n >> k;
		int same = 0;
		string s;cin >> s;
		for(int i = 0;i < n / 2;i++){
			if(s[i] == s[n - i - 1])same++;
		}
		same = (n / 2) - same;
		ans = abs(same - k);
		cout << "Case #" << q << ": " << ans << endl;
	}
}
