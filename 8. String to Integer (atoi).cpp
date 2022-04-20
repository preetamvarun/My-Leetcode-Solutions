class Solution {
public:
    int myAtoi(string s) {
        
        long ans = 0;
        
        long up = 1;
	
        string num = "";
        
        bool isNumHit = false;
        
        // FILTERING OUT THE USER GIVEN STRING 

        for(int i = 0; i < s.size(); i++){
            
            if(isalpha(s[i]) || s[i] == '.'){
                break;
            }
            
            else if(isdigit(s[i]) || s[i] == '+' || s[i] == '-'){
                
                // IT IS UNECCESSARY TO PLACE ZEROS ON THE LEFT MOST SIDE OF THE STRING
                
                if(s[i] == '0' && isNumHit){
                    num += s[i];
                }
                
                else if(isdigit(s[i]) && s[i] != '0'){
                    num += s[i];
                    isNumHit = true;
                }
                
                else if(num.size() == 0 && s[i] == '-'){
                    num += '-';
                }
                
                if(i != s.size() - 1){
                    if(s[i+1] == '+' || s[i+1] == '-' || s[i+1] == ' '){
                        break;
                    }
                }
            } 
        }
        
        
        // IF THERE IS ONLY + OR - IN THE STRING 
        
        if(num.size() == 1 && !isdigit(num[0])){
            return 0;
        }
        
        // IF THE NUMBER IS POSITIVE
        
        else if(num[0] != '-'){
            
            if(num.size() > 11){
                return INT_MAX;
            }
            
            for(int i = num.size()-1; i >= 0; i--){
                ans += (num[i] - '0') * up;
                if(ans > INT_MAX){
                    return INT_MAX;
                }
                up *= 10;
            }
        }
        
        // IF THE NUMBER IS NEGATIVE 
        
        else if(num[0] == '-'){
            
            if(num.size() > 11){
                return INT_MIN;
            }
            
            for(int i = num.size()-1; i > 0; i--){
                ans += 0 - (num[i] - '0') * up;
                if(ans < INT_MIN){
                    return INT_MIN;
                }
                up *= 10;
            }
        }
    
        
        return ans;
    }
};
