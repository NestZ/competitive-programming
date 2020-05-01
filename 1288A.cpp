#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int n, d;cin >> n >> d;
		bool flag = false;
		if(d <= n)flag = true;
		else{
			for(int i = 1;i * i <= d;i++){
				int curr = i + (d + i) / (i + 1);
				if(curr <= n)flag = true;
			}
		}
		if(flag)cout << "YES";
		else cout << "NO";
		cout << endl;
	}
}
