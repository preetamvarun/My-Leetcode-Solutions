class Solution {

public:

bool isSafe(int row,int col, vector<vector<string>> &board, int n){

 // check for left horizontal direction

    

for(int i=0;i<col;i++){

if(board[row][i] == "Q") return false;

}

    

// check for top left diagnol

int duprow = row,dupcol = col;

while(duprow>=0 && dupcol>=0){

if(board[duprow][dupcol] == "Q") return false;

    duprow--;

    dupcol--;

}

// check for bottom left diagonal

    

while (row < n && col >= 0){

    if(board[row][col] == "Q"){

        return false;

    }

row++;

col--;

}

return true;

}

    

void f(vector<vector<string>> board,int &ans, int col,int n){

    

if(col == n){

    ans++;

}

        

 // Recursive calls for every row in the current column number

    

for(int row=0;row<n;row++){

if(isSafe(row,col,board,n)){

vector<vector<string>> b = board;

b[row][col] = "Q";

f(b,ans,col+1,n);

}

}

 

}

   

  

int totalNQueens(int n) {

       vector<vector<string>>board;

int ans = 0;

     

// Initialise the board with "."

        

for(int i = 0; i < n; i++){

vector<string>row(n,".");

board.push_back(row);

}

        

f(board,ans,0,n);

        

  

 return ans;

        

    }

};
