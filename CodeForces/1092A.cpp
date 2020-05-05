#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int n, k;cin >> n >> k;
		string ans = "";
		string curr = "";
		for(int i = 0;i < k;i++)curr += 'a' + i;
		while(ans.length() < n)ans += curr;
		cout << ans.substr(0, n) << endl;
	}
}
