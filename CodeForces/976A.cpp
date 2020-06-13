#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	string s;cin >> s;
	int cnt = 0;
	if(s == "0")return cout << 0, 0;
	for(int i = 0;i < n;i++){
		if(s[i] == '0')cnt++;
	}
	cout << 1;
	for(int i = 0;i < cnt;i++)cout << 0;
}
