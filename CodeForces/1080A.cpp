#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;cin >> n >> k;
	int r = n * 2;
	int g = n * 5;
	int b = n * 8;
	cout << (r + k - 1) / k + (g + k - 1) / k + (b + k - 1) / k;
}
