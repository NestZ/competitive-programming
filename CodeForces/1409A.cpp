#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	for(int i = 0;i < n;i++){
		int a, b;cin >> a >> b;
		int diff = abs(a - b);
		cout << (diff + 9) / 10 << endl;
	}
}
