class Solution {
public:
    bool isPalindrome(int x) 
    {
        long long int y=x;
        long long int rev=0;
        if(x<0) 
        {return false;}
        else
        {
            while(x>0)
            {
                rev=rev*10+x%10;
                x=x/10;
            }
        }
        if(y==rev)
            return true;
        else
            return false;
    }
};