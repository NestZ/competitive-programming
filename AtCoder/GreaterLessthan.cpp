#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;cin >> s;
	int n = s.length();
	vector<int> lt(n + 1);
	vector<int> gt(n + 1);
	for(int i = 1;i <= n;i++){
		if(s[i - 1] == '<')lt[i] += lt[i - 1] + 1;
	}
	for(int i = n - 1;i >= 0;i--){
		if(s[i] == '>')gt[i] += gt[i + 1] + 1;
	}
	ll ans = 0;
	for(int i = 0;i <= n;i++){
		ans += max(gt[i], lt[i]);
	}
	cout << ans << endl;
}
