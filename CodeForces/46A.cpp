#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	int curr = 1;
	int p = 1;
	for(int i = 0;i < n - 1;i++){
		curr += p;
		curr %= n;
		if(curr == 0)curr = n;
		cout << curr << ' ';
		p++;
	}
}
