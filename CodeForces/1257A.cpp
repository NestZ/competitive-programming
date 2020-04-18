#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int t;cin >> t;
	while(t--){
		int n, x, a, b;cin >> n >> x >> a >> b;
		cout << abs(a - b) + min(n - (abs(a - b) + 1), x) << endl;
	}
}
