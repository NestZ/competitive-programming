#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int d;cin >> d;
	string q;cin >> q;
	string s;cin >> s;
	if(s[0] == 'w'){
		int curr = 5;
		int ans = 0;
		for(int i = 0;i < 366;i++){
			if(curr == d)ans++;
			curr++;
			if(curr > 7)curr = 1;
		}
		cout << ans;
		return 0;
	}
	int ans = 0;
	for(int i = 0;i < 12;i++)
		if(d <= t[i])ans++;
	cout << ans;
}
