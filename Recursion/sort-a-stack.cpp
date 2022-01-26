// SORT A STACK USING RECURSION

#include<bits/stdc++.h>
using namespace std;

void insert(stack<int> &s, int temp) {

	if (s.size() == 0 || temp >= s.top()) {
		s.push(temp);
		return;
	}

	int x = s.top();
	s.pop();

	insert(s, temp);

	s.push(x);

}

void fun(stack<int> &s) {

	if (s.size() == 1) {
		return;
	}

	int x = s.top();
	s.pop();
	fun(s);

	insert(s, x);

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
