#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	while(n--){
		int a, b;cin >> a >> b;
		if(a != b)return cout << "Happy Alex", 0;
	}
	cout << "Poor Alex";
}
