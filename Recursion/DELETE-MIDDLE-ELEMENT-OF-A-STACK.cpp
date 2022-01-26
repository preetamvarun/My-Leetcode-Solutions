// DELETE MIDDLE ELEMENT OF A STACK

#include<bits/stdc++.h>
using namespace std;

void fun(stack<int> &s, int k) {
	if (k == 1) {
		s.pop();
		return;
	}
	int x = s.top();
	s.pop();
	k--;
	fun(s, k);
	s.push(x);
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, ele, me; cin >> n; stack<int>s;

	for (int i = 0; i < n; i++) {
		cin >> ele;
		s.push(ele);
	}

	me = n / 2 + 1;

	if (n != 0) fun(s, me);

	while (s.size() != 0) {
		cout << s.top() << endl;
		s.pop();
	}


	return 0;

}
