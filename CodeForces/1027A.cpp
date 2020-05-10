#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		string s;cin >> s;
		bool flag = true;
		for(int i = 0;i < n / 2;i++){
			int diff = abs(s[i] - s[n - i - 1]);
			if(diff != 2 && diff != 0)flag = false;
		}
		if(flag)cout << "YES";
		else cout << "NO";
		cout << endl;
	}
}
