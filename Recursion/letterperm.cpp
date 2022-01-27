#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

void solve(string ip, string op){

	if(ip.size() == 0){
		cout << op << endl;
		return;
	}

	else if((ip[0] >= 'a' && ip[0] <= 'z') || ip[0] >= 'A' && ip[0] <= 'Z'){
		string op1 = op, op2 = op;
		if(islower(ip[0])){
			op1.push_back(toupper(ip[0]));
		}
		else{
			op1.push_back(tolower(ip[0]));
		}
		op2.push_back(ip[0]);
		ip.erase(ip.begin());
		solve(ip,op1);
		solve(ip,op2);
	}

	else{
		op.push_back(ip[0]);
		ip.erase(ip.begin());
		solve(ip,op);
	}

}


int main(){
	string s, op = "";
	cin >> s;
	solve(s,op);
	return 0;	
}