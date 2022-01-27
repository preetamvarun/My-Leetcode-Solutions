#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

void solve(string ip, string op){

	if(ip == ""){
		cout << op << endl;
		return;
	}

	// string op1 = op, op2 = op, temp1, temp2;

	// temp1 = temp1.append(1,toupper(ip[0]));
	// temp2 = temp2.append(1,ip[0]);

	// op1 = op1 + temp1;
	// op2 = op2 + temp2;

	string op1 = op, op2 = op;

	op1.push_back(toupper(ip[0]));
	op2.push_back(ip[0]);

	ip.erase(ip.begin());

	solve(ip,op1);
	solve(ip,op2);

}


int main(){
	string s, op = "";
	cin >> s;
	solve(s,op);
	return 0;
}

