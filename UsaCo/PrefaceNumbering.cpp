/*
ID: nestz
LANG: C++14
TASK: preface
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

char page[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
map<char, int> ans;

void cnt(int n){
	//count thousand
	if(n >= 1000){
		ans['M'] += n / 1000;
	}
	n %= 1000;
	//count hundred
	if(n / 100 == 9){
		//100
		ans['C']++;
		//1000
		ans['M']++;
	}
	else if(n / 100 == 4){
		//500
		ans['D']++;
		//100
		ans['C']++;
	}
	else{
		//500
		ans['D'] += n / 500;
		//100
		ans['C'] += (n % 500) / 100;
	}
	n %= 100;
	//count ten
	if(n / 10 == 9){
		//10
		ans['X']++;
		//100
		ans['C']++;
	}
	else if(n / 10 == 4){
		//10
		ans['X']++;
		//50
		ans['L']++;
	}
	else{
		//50
		ans['L'] += n / 50;
		//10
		ans['X'] += (n % 50) / 10;
	}
	n %= 10;
	//count unit
	if(n == 9){
		//1
		ans['I']++;
		//10
		ans['X']++;
	}
	else if(n == 4){
		//1
		ans['I']++;
		//5
		ans['V']++;
	}
	else{
		//5
		ans['V'] += n / 5;
		//1
		ans['I'] += (n % 5);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("preface.out", "w", stdout);
	freopen("preface.in", "r", stdin);
	
	int n;cin >> n;
	for(int i = 1;i <= n;i++)cnt(i);
	for(char c : page){
		if(ans[c] != 0)
			cout << c << ' ' << ans[c] << endl;
	}
}
