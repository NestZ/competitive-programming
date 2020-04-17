#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n, a, b;cin >> n >> a >> b;
	int f = a + 1;
	cout << min(b + 1, n - f + 1);
}
