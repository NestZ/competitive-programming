#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;cin >> n >> k;
	string s;cin >> s;
	int d = 0;
	int a = 0;
	int b = 0;
	int ans = 0;
	for(int i = 0;i < n;i++){
		if(s[i] == 'a')a++;
		else b++;
		if(min(a, b) <= k)ans = max(ans, a + b);
		else{
			if(s[d++] == 'a')a--;
			else b--;
		}
	}
	cout << ans;
}
