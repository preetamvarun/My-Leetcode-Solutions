
/*

IP -> abc

op :
a b c
ab c
a bc
abc

*/


#include<bits/stdc++.h>
using namespace std;

void solve(string ip, string op){

	if(ip.size() == 0){
		cout << op << endl;
		return;
	}

	if(op == ""){
		string x; 
		x.append(1,ip[0]);
		ip.erase(ip.begin());
		solve(ip,x);
	}

	else{
		string op1 = op + " " + ip[0];
		string op2 = op + ip[0];
		ip.erase(ip.begin());
		solve(ip,op1);
		solve(ip,op2);
	}
	
}

int main() {

	string s, op = "";

	cin >> s;

	solve(s,op);

return 0;
}


