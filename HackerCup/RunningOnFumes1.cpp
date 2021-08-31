#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

#define MAX 3000000 

vector<ll> tree(MAX, INT64_MAX);
vector<ll> lazy(MAX, -1);
vector<ll> arr(1000005);
ll n;

void updateRangeUtil(ll si, ll ss, ll se, ll us, ll ue, ll diff) { 
	if (lazy[si] >= 0) { 
		tree[si] = min(tree[si], lazy[si]);
		if (ss != se) { 
			ll left = lazy[si*2 + 1];
			ll right = lazy[si*2 + 2];
			if(left != -1)lazy[si*2 + 1] = min(left, lazy[si]);
			else lazy[si*2 + 1] = lazy[si];
			if(right != -1)lazy[si*2 + 2] = min(right, lazy[si]);
			else lazy[si*2 + 2] = lazy[si];
		} 
		lazy[si] = -1; 
	} 
	if (ss>se || ss>ue || se<us)return; 
	if (ss>=us && se<=ue) { 
		tree[si] = min(diff, tree[si]);
		if (ss != se) { 
			ll left = lazy[si*2 + 1];
			ll right = lazy[si*2 + 2];
			if(left != -1)lazy[si*2 + 1] = min(left, diff);
			else lazy[si*2 + 1] = diff;
			if(right != -1)lazy[si*2 + 2] = min(right, diff);
			else lazy[si*2 + 2] = diff;
		} 
		return; 
	} 
	ll mid = (ss+se)/2; 
	updateRangeUtil(si*2+1, ss, mid, us, ue, diff); 
	updateRangeUtil(si*2+2, mid+1, se, us, ue, diff); 
	tree[si] = min(tree[si*2 + 1], tree[si*2 + 2]);
} 

void updateRange(ll us, ll ue, ll diff) { 
	updateRangeUtil(0, 0, n-1, us, ue, diff); 
} 

ll getMinUtil(ll ss, ll se, ll qs, ll qe, ll si) { 
	if (lazy[si] >= 0) { 
		tree[si] = min(tree[si], lazy[si]);
		if (ss != se) { 
			ll left = lazy[si*2 + 1];
			ll right = lazy[si*2 + 2];
			if(left != -1)lazy[si*2 + 1] = min(left, lazy[si]);
			else lazy[si*2 + 1] = lazy[si];
			if(right != -1)lazy[si*2 + 2] = min(right, lazy[si]);
			else lazy[si*2 + 2] = lazy[si];
		}
		lazy[si] = -1;
	} 
	if (ss>se || ss>qe || se<qs)return INT64_MAX; 
	if (ss>=qs && se<=qe)return tree[si]; 
	ll mid = (ss + se)/2; 
	return min(getMinUtil(ss, mid, qs, qe, 2*si+1), getMinUtil(mid+1, se, qs, qe, 2*si+2)); 
} 

ll getMin(ll qs, ll qe) { 
	return getMinUtil(0, n-1, qs, qe, 0); 
} 

void constructSTUtil(ll ss, ll se, ll si) { 
	if (ss > se)return; 
	if (ss == se) { 
		tree[si] = arr[ss]; 
		return; 
	} 
	ll mid = (ss + se)/2; 
	constructSTUtil(ss, mid, si*2+1); 
	constructSTUtil(mid+1, se, si*2+2); 
	tree[si] = min(tree[si*2 + 1], tree[si*2 + 2]);
} 

void constructST() { 
	constructSTUtil(0, n-1, 0); 
} 

int main() { 
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll t;cin >> t;
	for(ll q = 0;q < t;q++){
		ll m;cin >> n >> m;
		bool flag = true;
		fill(arr.begin(), arr.end(), INT64_MAX);
		fill(tree.begin(), tree.end(), INT64_MAX);
		fill(lazy.begin(), lazy.end(), -1);
		updateRange(0, m, 0);
		for(int i = 0;i < n;i++){
			ll c;cin >> c;
			if(getMin(i, i) == INT64_MAX)flag = false;
			if(i == 0 || c == 0)continue;
			updateRange(i + 1, i + m, getMin(i ,i) + c);
		}
		ll ans = getMin(n - 1, n - 1);
		if(ans == INT64_MAX)ans = -1;
		cout << "Case #" << q + 1 << ": " << (flag ? ans: -1) << endl;
	}
	return 0; 
} 
