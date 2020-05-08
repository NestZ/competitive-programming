#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;cin >> n;
	int a = 0;
	int b = 0;
	for(int i = 0;i < n;i++){
		int t;cin >> t;
		if(t < 0)b += t;
		else a += t;
	}
	cout << abs(a - b);
}
