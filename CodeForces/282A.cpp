#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	int ans = 0;
	while(n--){
		string s;cin >> s;
		if(s.find('-') != string::npos)ans--;
		else ans++;
	}
	cout << ans;
}
