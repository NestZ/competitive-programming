#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	while(n--){
		int t;cin >> t;
		long double l = 1.0;
		while(t--)l *= 2.0;
		printf("%.0Lf\n", l);
	}
}
