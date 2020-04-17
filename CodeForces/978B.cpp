#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	string s;cin >> s;
	int ans = 0;
	int curr = 0;
	for(int i = 0;i < n;i++){
		if(s[i] == 'x')curr++;
		else{
			ans += max(0, curr - 2);
			curr = 0;
		}
	}
	ans += max(0, curr - 2);
	cout << ans;
}
