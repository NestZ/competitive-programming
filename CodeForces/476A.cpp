#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n,m;cin >> n >> m;
	if(n < m)return cout << -1, 0;
	int curr = m;
	while(curr * 2 < n){
		curr += m;
	}
	cout << curr;
}
