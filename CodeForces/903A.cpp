#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		bool flag = false;
		for(int i = 0;i <= n / 3;i++){
			for(int j = 0;j <= n / 7;j++){
				if(3 * i + 7 * j == n)flag = true;
			}
		}
		if(flag)cout << "YES";
		else cout << "NO";
		cout << endl;
	}
}
