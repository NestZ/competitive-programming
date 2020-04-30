#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;cin >> s;
	int n = s.length();
	int e = -1;
	for(int i = 0;i < n - 1;i++){
		if((s[i] - '0') & 1)continue;
		if(s[i] - '0' < s[n - 1] - '0'){
			e = i;
			break;
		}
		e = i;
	}
	if(e == -1)cout << -1;
	else{
		swap(s[n - 1], s[e]);
		cout << s;
	}
}
