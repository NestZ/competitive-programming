#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int n, m;cin >> n >> m;
		bool nomn = false;
		for(int i = 0;i < n;i++){
			int a, b, c, d;cin >> a >> b >> c >> d;
			if(b == c)nomn = true;
		}
		if(m & 1)cout << "NO";
		else if(nomn)cout << "YES";
		else cout << "NO";
		cout << endl;
	}
}
