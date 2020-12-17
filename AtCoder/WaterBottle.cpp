#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
const long double pi = 2 * acos(0.0);
const long double EPS = 0.0000000001;

long double area(long double a, long double b, long double theta){
	long double ans = 0;
	if(a * tan(theta) <= b)
		ans = a * a * b - a * a * a * tan(theta) / 2.0;
	else ans = b * b * tan(pi / 2.0 - theta) / 2.0 * a;
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b, x;cin >> a >> b >> x;
	long double r = pi / 2.0;
	long double l = 0.0;
	while(r - l >= EPS){
		long double mid = (r + l) / 2.0;
		if(area(a, b, mid) < x)r = mid;
		else l = mid;
	}
	cout << fixed << setprecision(10) << r / pi * 180 << endl;
}
