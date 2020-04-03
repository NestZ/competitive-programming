#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	double sum = 0;
	for(int i = 0;i < n;i++){
		double t;cin >> t;
		sum += t;
	}
	printf("%.10f", sum / double(n));
}
