#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	string a,b;cin >> a >> b;
	int n = a.size();
	string ans = "";
	for(int i = 0;i < n;i++){
		if(a[i] == b[i])ans += '0';
		else ans += '1';
	}
	cout << ans;
}
