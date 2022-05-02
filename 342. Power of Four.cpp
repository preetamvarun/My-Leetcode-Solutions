class Solution {
public:
    bool isPowerOfFour(int n) {
         if(n <= 0){
            return false;
        }
        
         if( log10(n)/log10(4) - int(log10(n)/log10(4)) == 0){
             
            return true;
             
        } 
        
        return false;
    }
};
