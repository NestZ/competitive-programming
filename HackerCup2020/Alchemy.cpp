#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("out.txt", "w", stdout);
	freopen("in.txt", "r", stdin);
	
	int t;cin >> t;
	for(int q = 0;q < t;q++){
		int n;cin >> n;
		int cnta = 0;
		int cntb = 0;
		for(int i = 0;i < n;i++){
			char c;cin >> c;
			if(c == 'A')cnta++;
			else cntb++;
		}
		cout << "Case #" << q + 1 << ": ";
		if(abs(cnta - cntb) > 1)cout << "N\n";
		else cout << "Y\n";
	}
}
