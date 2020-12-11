#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	ll cnt[] = {0, 0, 0, 0, 0};
	for(int i = 0;i < n;i++){
		string s;cin >> s;
		if(s[0] == 'M')cnt[0]++;
		else if(s[0] == 'A')cnt[1]++;
		else if(s[0] == 'R')cnt[2]++;
		else if(s[0] == 'C')cnt[3]++;
		else if(s[0] == 'H')cnt[4]++;
	}
	ll ans = 0;
	for(int i = 0;i <= 2;i++){
		for(int j = i + 1;j <= 3;j++){
			for(int k = j + 1;k <= 4;k++){
				ans += cnt[i] * cnt[j] * cnt[k];
			}
		}
	}
	cout << ans << endl;
}
