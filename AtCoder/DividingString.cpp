#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;cin >> s;
	int n = s.length();
	string last = "";
	string cur = "";
	int ans = 0;
	for(int i = 0;i < n;i++){
		cur += s[i];
		if(cur != last){
			last = cur;
			cur = "";
			ans++;
		}
	}
	cout << ans << endl;
}
