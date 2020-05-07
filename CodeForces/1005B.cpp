#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string a, b;cin >> a >> b;
	int pa = a.length() - 1;
	int pb = b.length() - 1;
	while(a[pa] == b[pb]){
		pa--;
		pb--;
		if(pa < 0)return cout << pb + 1, 0;
		if(pb < 0)return cout << pa + 1, 0;
	}
	cout << pa + pb + 2;
}
