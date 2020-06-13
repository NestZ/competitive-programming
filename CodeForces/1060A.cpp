#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	string s;cin >> s;
	int e = 0;
	for(int i = 0;i < n;i++){
		if(s[i] == '8')e++;
	}
	cout << min(e, n / 11);
}
