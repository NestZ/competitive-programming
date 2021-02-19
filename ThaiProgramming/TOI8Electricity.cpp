#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

#define MAX 2000000 

vector<int> tree(MAX, INT_MAX);
vector<int> lazy(MAX, -1);
vector<int> arr(1000005);
int n, k;

void updateRangeUtil(int si, int ss, int se, int us, int ue, int diff) { 
	if (lazy[si] >= 0) { 
		tree[si] = min(tree[si], lazy[si]);
		if (ss != se) { 
			int left = lazy[si*2 + 1];
			int right = lazy[si*2 + 2];
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
			int left = lazy[si*2 + 1];
			int right = lazy[si*2 + 2];
			if(left != -1)lazy[si*2 + 1] = min(left, diff);
			else lazy[si*2 + 1] = diff;
			if(right != -1)lazy[si*2 + 2] = min(right, diff);
			else lazy[si*2 + 2] = diff;
		} 
		return; 
	} 
	int mid = (ss+se)/2; 
	updateRangeUtil(si*2+1, ss, mid, us, ue, diff); 
	updateRangeUtil(si*2+2, mid+1, se, us, ue, diff); 
	tree[si] = min(tree[si*2 + 1], tree[si*2 + 2]);
} 

void updateRange(int us, int ue, int diff) { 
	updateRangeUtil(0, 0, n-1, us, ue, diff); 
} 

int getMinUtil(int ss, int se, int qs, int qe, int si) { 
	if (lazy[si] >= 0) { 
		tree[si] = min(tree[si], lazy[si]);
		if (ss != se) { 
			int left = lazy[si*2 + 1];
			int right = lazy[si*2 + 2];
			if(left != -1)lazy[si*2 + 1] = min(left, lazy[si]);
			else lazy[si*2 + 1] = lazy[si];
			if(right != -1)lazy[si*2 + 2] = min(right, lazy[si]);
			else lazy[si*2 + 2] = lazy[si];
		}
		lazy[si] = -1;
	} 
	if (ss>se || ss>qe || se<qs)return INT_MAX; 
	if (ss>=qs && se<=qe)return tree[si]; 
	int mid = (ss + se)/2; 
	return min(getMinUtil(ss, mid, qs, qe, 2*si+1), getMinUtil(mid+1, se, qs, qe, 2*si+2)); 
} 

int getMin(int qs, int qe) { 
	return getMinUtil(0, n-1, qs, qe, 0); 
} 

void constructSTUtil(int ss, int se, int si) { 
	if (ss > se)return; 
	if (ss == se) { 
		tree[si] = arr[ss]; 
		return; 
	} 
	int mid = (ss + se)/2; 
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

	cin >> n >> k;
	for(int i = 0;i < n;i++)cin >> arr[i];
	updateRange(0, k, arr[0]);
	for(int i = 1;i < n - 1;i++){
		updateRange(i + 1, i + k, getMin(i, i) + arr[i]);
	}
	cout << getMin(n - 1, n - 1) + arr[n - 1] << endl;
} 
