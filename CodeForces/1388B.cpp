#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		int to0 = n / 4;
		int to8 = (n % 4 > 0 ? 1 : 0);
		for(int i = 0;i < n - to0 - to8;i++)cout << 9;
		for(int i = 0;i < to8;i++)cout << 8;
		for(int i = 0;i < to0;i++)cout << 8;
		cout << endl;
	}
}
