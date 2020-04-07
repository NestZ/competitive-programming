#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n, m, a, b;cin >> n >> m >> a >> b;
	cout << min(min(n * a, (n + m - 1) / m * b), n / m * b + n % m * a);
}
