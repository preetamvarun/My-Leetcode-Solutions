class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        
        int i = 0, j = 0, N = answerKey.size();
        
        int c1 = k, ans1 = 0, c2 = k, ans2 = 0, count = 0;
        
        // Change false to true and see max no of consecutive trues that you can get
        while(j < N){
            if(answerKey[j] != 'T'){
                c1--;
                while(c1 < 0){
                    if(answerKey[i] == 'F') c1++;
                    count--;
                    i++;
                } 
            } 
            count++;
            ans1 = max(ans1,count);
            j++;
        }
        
        i = 0; count = 0; j = 0; 
        
        // Change true to false and see max no of consecutive falses that you can get
         while(j < N){
            if(answerKey[j] != 'F'){
                c2--;
                while(c2 < 0){
                    if(answerKey[i] == 'T') c2++;
                    count--;
                    i++;
                }
            } 
            count++;
            ans2 = max(ans2,count);
            j++;
        }
        
        // return max(consecutive trues, consecutive falses)
        return max(ans2,ans1);
    }
};
