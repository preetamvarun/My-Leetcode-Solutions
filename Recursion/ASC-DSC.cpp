// SORT AN ARRAY IN ASCENDING & DESCENDING ORDER USING RECURSION

#include<bits/stdc++.h>
using namespace std;

void insertAsc(vector<int> &v, int temp) {

	if (v.size() == 0 || temp >= v[v.size() - 1]) {
		v.push_back(temp);
		return;
	}

	int x = v[v.size() - 1];
	v.pop_back();
	insertAsc(v, temp);

	v.push_back(x);
}

void sortAsc(vector<int> &v) {

	if (v.size() == 1) {
		return;
	}

	int temp = v[v.size() - 1]; // make i/p smaller
	v.pop_back();
	sortAsc(v);

	insertAsc(v, temp);
}

void insertDsc(vector<int> &v, int temp) {

	if (v.size() == 0 || temp >= v[0] ) {
		v.insert(v.begin(), temp);
		return;
	}

	int x = v[0];
	v.erase(v.begin());
	insertDsc(v, temp);

	v.insert(v.begin(), x);
}

void sortDsc(vector<int> &v) {

	if (v.size() == 1) {
		return;
	}

	int temp = v[0];
	v.erase(v.begin());
	sortDsc(v);

	insertDsc(v, temp);
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n; cin >> n; vector<int>v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sortAsc(v);


	for (int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}

	cout << endl;

	sortDsc(v);

	for (int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}

	return 0;

}
