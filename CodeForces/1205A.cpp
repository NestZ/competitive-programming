#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	if(n & 1){
		cout << "YES" << endl;
		for(int i = 0;i < n;i++)cout << 2 * i + 1 + (i & 1) << ' ';
		for(int i = 0;i < n;i++)cout << 2 * i + 2 - (i & 1) << ' ';
	}
	else cout << "NO";
}
