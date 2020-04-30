#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;cin >> s;
	int n = s.length();
	for(int i = n - 1;i >= 0;i--){
		if(s[i] == '1'){
			s[i] = '0';
			break;
		}
	}
	int ans = 0;
	for(int i = n - 1;i >= 0;i -= 2){
		if(i == 0 && s[i] == '0')continue;
		ans++;
	}
	cout << ans;
}
