#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;cin >> s;
	char mx = 'a';
	int n = s.length();
	int cnt = 0;
	for(int i = 0;i < n;i++){
		if(s[i] > mx){
			mx = s[i];
			cnt = 0;
		}
		if(s[i] == mx)cnt++;
	}
	cout << string(cnt, mx);
}
