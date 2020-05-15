#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	string num[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
	string e[] = {"eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty"};
	string t[] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
	if(n <= 10)cout << num[n];
	else if(n <= 20)cout << e[n - 11];
	else{
		cout << t[n / 10 - 2];
		if(n % 10 != 0)cout << '-' << num[n % 10];
	}
}
