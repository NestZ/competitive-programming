#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n;cin >> n;
	cout << n << ' ';
	while(n != 1){
		if(n & 1){
			n = n * 3 + 1;
		}
		else{
			n /= 2;
		}
		cout << n << ' ';
	}
	cout << endl;
}
