#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

void cal(int &a, int &b, int &c, int &d, int &e, int num){
	int h = num / 100;
	int t = num / 10 % 10;
	int s = num % 10;
	e += h;
	if(t == 4){
		c++;
		d++;
	}
	else if(t == 9){
		c++;
		e++;
	}
	else if(t != 0){
		if(t < 4)c += t;
		else{
			d++;
			c += t - 5;
		}
	}
	if(s == 4){
		a++;
		b++;
	}
	else if(s == 9){
		a++;
		c++;
	}
	else if(s != 0){
		if(s < 4)a += s;
		else{
			b++;
			a += s - 5;
		}
	}
}

int main(){
	int n;cin >> n;
	int a = 0, b = 0, c = 0, d = 0, e = 0;
	for(int i = 1;i <= n;i++)cal(a, b, c, d, e, i);
	cout << a << " " << b << " " << c << " " << d << " " << e;
}
