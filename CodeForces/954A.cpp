#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	string s;cin >> s;
	int ans = 0;
	for(int i = 0;i < n;i++){
		if(s[i] != s[i + 1] && i + 1 < n){
			ans++;
			i++;
		}
		else ans++;
	}
	cout << ans;
}
