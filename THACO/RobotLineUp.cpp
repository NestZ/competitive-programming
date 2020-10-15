#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll _mergeSort(ll arr[], ll temp[], ll left, ll right); 
ll merge(ll arr[], ll temp[], ll left, ll mid, ll right);

ll mergeSort(ll arr[], ll array_size) 
{ 
    ll temp[array_size]; 
    return _mergeSort(arr, temp, 0, array_size - 1); 
} 
  
ll _mergeSort(ll arr[], ll temp[], ll left, ll right) 
{ 
    ll mid, inv_count = 0; 
    if (right > left) { 
        mid = (right + left) / 2; 
        inv_count += _mergeSort(arr, temp, left, mid); 
        inv_count += _mergeSort(arr, temp, mid + 1, right); 
        inv_count += merge(arr, temp, left, mid + 1, right); 
    } 
    return inv_count; 
} 
  
ll merge(ll arr[], ll temp[], ll left, 
          ll mid, ll right) 
{ 
    ll i, j, k; 
    ll inv_count = 0; 
    i = left; /* i is index for left subarray*/
    j = mid; /* j is index for right subarray*/
    k = left; /* k is index for resultant merged subarray*/
    while ((i <= mid - 1) && (j <= right)) { 
        if (arr[i] <= arr[j]) { 
            temp[k++] = arr[i++]; 
        } 
        else { 
            temp[k++] = arr[j++]; 
            inv_count = inv_count + (mid - i); 
        } 
    } 
    while (i <= mid - 1) 
        temp[k++] = arr[i++]; 
    while (j <= right) 
        temp[k++] = arr[j++]; 
    for (i = left; i <= right; i++) 
        arr[i] = temp[i]; 
    return inv_count; 
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, m;cin >> n >> m;
	vector<ll> a(n);
	vector<ll> b(m);
	vector<ll> arr(n);
	for(int i = 0;i < n;i++){
		cin >> a[i];
		arr[n - i - 1] = a[i];
	}
	for(int i = 0;i < m;i++)cin >> b[i];
	sort(b.begin(), b.end());
	vector<ll> ans;
	ll curr = 0;
	ll cntless = upper_bound(arr.begin(), arr.end(), b[curr]) - arr.begin();
	while(cntless <= n / 2){
		ans.push_back(b[curr]);
		curr++;
		if(curr == m)break;
		cntless = upper_bound(arr.begin(), arr.end(), b[curr]) - arr.begin();
	}
	for(ll i : a)ans.push_back(i);
	for(int i = curr;i < m;i++)ans.push_back(b[i]);
	ll len = ans.size();
	ll merg[len];
	for(int i = 0;i < len;i++)merg[i] = ans[i];
	cout << len * (len - 1) / 2 - mergeSort(merg, len);
}
