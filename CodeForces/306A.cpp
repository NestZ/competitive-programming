#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;cin >> n >> m;
	int f = (n + (m - 1)) / m * m - n;
	for(int i = 0;i < f;i++)cout << n / m << ' ';
	for(int i = 0;i < m - f;i++)cout << (n + (m - 1)) / m << ' ';
}
