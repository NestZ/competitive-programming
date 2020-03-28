#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int k, n, w;cin >> k >> n >> w;
	int sum = k;
	for(int i = 2;i <= w;i++){
		sum += i * k;
	}
	cout << max(0, sum - n);
}
