#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, d;cin >> n >> d;
	int ans = 0;
	int curr = 0;
	for(int i = 0;i < d;i++){
		string s;cin >> s;
		bool flag = true;
		for(int j = 0;j < n;j++){
			if(s[j] == '0')flag = false;
		}
		if(!flag){
			curr++;
			ans = max(ans, curr);
		}
		else curr = 0;
	}
	cout << ans;
}
