// TOWER OF HANOI USING RECURSION

#include<bits/stdc++.h>
using namespace std;

void solve(char s, char d, char h, int n) {

	if (n == 0) {
		return ; 
	}

	solve(s, h , d, n - 1); // move n - 1 plates from source to helper using destination

	cout << "move plate " << n << " from " << s << " to " << d << endl; // move the last plate from source to destination

	solve(h, d, s, n - 1) ;  // move n - 1 plates from helper to destination using source 
}


int main() {

	char srcPlate = 'S', helperPlate = 'H', destinationPlate = 'D';

	int noofPlates; cin >> noofPlates;

	solve(srcPlate, helperPlate, destinationPlate, noofPlates);

	return 0;


}