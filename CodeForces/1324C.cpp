#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	for(int i = 0;i < n;i++){
		string s;cin >> s;
		int k = s.length();
		int cnt = 0;
		int ans = 0;
		for(int j = 0;j < k;j++){
			if(s[j] == 'L'){
				cnt++;
				ans = max(ans, cnt);
			}
			else cnt = 0;
		}
		cout << ans + 1 << endl;
	}
}
