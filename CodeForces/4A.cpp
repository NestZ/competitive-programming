#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	cout << (!(n & 1) && (n > 2) ? "YES" : "NO");
}
