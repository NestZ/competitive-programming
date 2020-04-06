#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int a, b;cin >> a >> b;
	cout << min(a, b) << ' ' << (max(a, b) - min(a, b)) / 2;
}
