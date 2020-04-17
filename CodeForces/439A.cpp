#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n, d;cin >> n >> d;
	int sum = 0;
	for(int i = 0;i < n;i++){
		int t;cin >> t;
		sum += t;
	}
	int all = sum + 10 * (n - 1);
	if(d < all)return cout << -1, 0;
	int rem = d - all;
	cout << 2 * (n - 1) + rem / 5;
}
