class Solution {
public:
    int countPrimes(int n) 
    {                                    
        int count=0;
        if(n==0 || n==1) return 0;
        vector<bool> vec(n+1, 1);                               
        for(int i=2; i<n; i++){
            if(vec[i]!=0){
                count++;
                for(int j=i*2; j<n; j+=i) vec[j]=0;             
            }
        }
    return count;
    }
};