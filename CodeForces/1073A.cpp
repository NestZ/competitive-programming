#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	string s;cin >> s;
	for(int i = 0;i < n - 1;i++){
		if(s[i] != s[i + 1]){
			return cout << "YES" << endl << s[i] << s[i + 1], 0;
		}
	}
	cout << "NO";
}
