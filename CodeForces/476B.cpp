#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	string a;cin >> a;
	string b;cin >> b;
	int pa = 0;
	int pb = 0;
	int pe = 0;
	int n = a.length();
	for(int i = 0;i < n;i++){
		if(a[i] == '+')pa++;
		if(b[i] == '+')pb++;
		if(b[i] == '?')pe++;
	}
	int ans = 0;
	for(int i = 0;i < (1 << pe);i++){
		if(__builtin_popcount(i) + pb == pa)ans++;
	}
	printf("%.9f", (double)ans / (1 << pe));
}
