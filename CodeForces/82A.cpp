#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	vector<string> arr({"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"});
	int c = 5;
	int i = 1;
	if(n <= 5)return cout << arr[n - 1], 0;
	while(c < n){
		n -= c;
		c <<= 1;
		i <<= 1;
	}
	cout << arr[n / i];
}
