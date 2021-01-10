class Solution {
public:
    int totalMoney(int n) {
        int mon = 1;
        int sum = 0;
        for(int i = 0 ; i < n ; i++)
        {
            if(i% 7 == 0 && i != 0)
            {
                mon++;
                sum += mon;
            }
            else
            {
                sum += (mon + i % 7);
            }
        }     
        return sum; 
    }
};