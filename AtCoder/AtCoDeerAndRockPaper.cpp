#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;cin >> s;
	int n = s.length();
	int sr = 0;
	int sp = 0;
	int ans = 0;
	for(int i = 0;i < n;i++){
		if(s[i] == 'g')sr++;
		else sp++;
	}
	for(int i = n - 1;i >= 0;i--){
		if(s[i] == 'g'){
			if(sr - 1 >= sp + 1){
				sr--;sp++;
				ans++;
			}
		}
	}
	cout << ans << endl;
}
