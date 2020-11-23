#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	for(int i = 0;i <= n;i++){
		if(int(i * 1.08) == n)return cout << i << endl, 0;
	}
	cout << ":(" << endl;
}
