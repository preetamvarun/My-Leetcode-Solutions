// KTH SYMBOL IN  GRAMMAR

#include<bits/stdc++.h>
using namespace std;

int solve(int n, int k) {

	if (n == 1 && k == 1) {
		return 0;
	}

	// Make the input smaller
	int mid = pow(2, n - 1) / 2;

	if (mid >= k) {
		return solve(n - 1, k);
	}

	else {
		return !solve(n - 1, k - mid);
	}

}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, k; cin >> n >> k;


	cout << solve(n, k);

	return 0;

}
