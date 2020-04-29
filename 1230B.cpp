#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;cin >> n >> k;
	string s;cin >> s;
	if(n == 1 && k > 0)return cout << 0, 0;
	if(s == "1" && k == 0)return cout << 1, 0;
	if(s == "0")return cout << 0, 0;
	for(int i = 0;i < n;i++){
		if(i == 0){
			if(s[i] != '1' && k > 0){
				k--;
				s[i] = '1';
			}
			continue;
		}
		if(s[i] != '0' && k > 0){
			k--;
			s[i] = '0';
		}
	}
	cout << s;
}
