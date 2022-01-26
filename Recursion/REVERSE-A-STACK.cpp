#include<bits/stdc++.h>
using namespace std;

void reverse(stack<int> &s, int ele) {

	if (s.size() == 0) {
		s.push(ele);
		return;
	}

	int x = s.top();
	s.pop();
	reverse(s, ele);
	s.push(x);
}

void fun(stack<int> &s) {

	if (s.size() == 1) {
		return;
	}

	int x = s.top();
	s.pop();
	fun(s);

	reverse(s, x);
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, ele; cin >> n; stack<int>s;

	for (int i = 0; i < n; i++) {
		cin >> ele;
		s.push(ele);
	}

	fun(s);

	while (s.size() != 0) {
		cout << s.top() << endl;
		s.pop();
	}

	return 0;

}
