#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	vector<int> pre(n);
	for(int i = 0;i < n;i++){
		int t;cin >> t;
		if(i == 0)pre[i] = t;
		else pre[i] = t + pre[i - 1];
	}
	int k;cin >> k;
	while(k--){
		int m;cin >> m;
		int b = 0;
		for(int i = n / 2;i > 0;i /= 2){
			while(i + b < n && m > pre[i + b])b += i;
		}
		if(m > pre[b])b++;
		cout << b + 1 << endl;
	}
}
