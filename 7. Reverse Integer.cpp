class Solution {
public:
    int reverse(int x) {
        long init = 0, rem = 0, temp = x;
        
            while(x != 0){
                rem = x % 10;
                init = init * 10 + rem;
                x /= 10;
            }
        
        
        if(temp > 0){
            if(init > INT_MAX){
                return 0;
            }
        }
        
        if(temp < 0){
            if(init < INT_MIN){
                return 0;
            }
        }
        
        return init;
    }
};
