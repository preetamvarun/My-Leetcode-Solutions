// FACTORIAL OF A NUMBER USING RECURSION

#include<bits/stdc++.h>
using namespace std;


int fun(int n) {

	if (n == 1) {
		return 1;
	}

	return n * fun(n - 1);
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n; cin >> n;

	cout << fun(n);

	return 0;

}
