#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	string s;
	int mx = 0;
	while(cin >> s){
		int cnt = 0;
		for(char x : s){
			if(isupper(x))cnt++;
		}
		mx = max(mx, cnt);
	}
	cout << mx;
}
