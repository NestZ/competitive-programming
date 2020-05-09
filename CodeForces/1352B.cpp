#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int a, b;cin >> a >> b;
		if(b > a)cout << "NO" << endl;
		else if(a == b){
			cout << "YES" << endl;
			for(int i = 0;i < b;i++)cout << 1 << ' ';
			cout << endl;
		}
		else if(a >= b * 2 && a % 2 == 0){
			cout << "YES" << endl;
			for(int i = 0;i < b - 1;i++)cout << 2 << ' ';
			cout << a - (2 * (b - 1)) << endl;
		}
		else if((a - b + 1) % 2 != 0){
			cout << "YES" << endl;
			for(int i = 0;i < b - 1;i++)cout << 1 << ' ';
			cout << a - b + 1 << endl;
		}
		else cout << "NO" << endl;
	}
}
