#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		int a = 1;
		int b = 1;
		for(int i = 2;i * i <= n;i++){
			if(n % i == 0){
				a = i;
				n /= i;
				break;
			}
		}
		for(int i = a + 1;i * i <= n;i++){
			if(n % i == 0){
				b = i;
				n /= i;
				break;
			}
		}
		if(n == a || n == b || a < 2 || b < 2 || n < 2)cout << "NO" << endl;
		else{
			cout << "YES" << endl << a << ' ' << b << ' ' << n << endl;
		}
	}
}
