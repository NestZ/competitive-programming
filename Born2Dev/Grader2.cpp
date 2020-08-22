#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	double a, b, c, d, e;cin >> a >> b >> c >> d >> e;
	double sum = a + b + c + d + e;
	sum /= 5;
	printf("THAI = %.1lf\n", a);
	printf("MATH = %.1lf\n", b);
	printf("ENGLISH = %.1lf\n", c);
	printf("SCIENCE = %.1lf\n", d);
	printf("SPORT = %.1lf\n", e);
	printf("---\n");
	printf("GPA = %.1lf", sum);
}
