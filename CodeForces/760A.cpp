#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int M[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	int m, d;cin >> m >> d;
	int day = M[m];
	cout << (day - (7 - d + 1) + 6) / 7 + 1;
}
