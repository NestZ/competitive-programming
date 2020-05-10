#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	map<char, int> m;
	for(int i = 0;i < n;i++){
		string s;cin >> s;
		m[s[0]]++;
	}
	int ans = 0;
	for(pair<char, int> p : m){
		int mid = p.second / 2;
		int mid2 = (p.second + 1) / 2;
		int a = mid * (mid - 1) / 2;
		int b = mid2 * (mid2 - 1) / 2;
		ans += a + b;
	}
	cout << ans;
}
