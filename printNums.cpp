#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0)
#define endl "\n"

/* Print N to 1 */

void printNumsRev(vector<int>x, int n) {
	if (n == 0) {
		return;
	} else {
		cout << x[n - 1];
		printNumsRev(x, n - 1);
	}
}

/* Print 1 to N */

void printNums(vector<int>x, int n, int s) {
	if (s == n) {
		return;
	} else {
		cout << x[s];
		printNums(x, n, s + 1);
	}
}


int main() {

	fastio;

	int n; cin >> n;
	vector<int>v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	printNumsRev(v, n); cout << endl;

	int start = 0;
	printNums(v, n, start);

	return 0;
}