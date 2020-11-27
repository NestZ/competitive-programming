#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b, ab;cin >> a >> b >> ab;
	int wanta, wantb;cin >> wanta >> wantb;
	int a1b2 = max(0, wanta - wantb) * a + 2 * wantb * ab;
	int a2b1 = 2 * wanta * ab + max(0, wantb - wanta) * b;
	int a1b1 = wanta * a + wantb * b;
	int a2b2 = 2 * max(wanta, wantb) * ab;
	cout << min({a1b1, a2b1, a1b2, a2b2}) << endl;
}
