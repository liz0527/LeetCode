class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int int_max = 1000001;
        int sum[coins.size()+1][amount+1];
        for(int i=0;i<=coins.size();i++)
            sum[i][0]=0;
        for(int j=1;j<=amount;j++)
            sum[0][j]=int_max;
        for(int j=1;j<=amount;j++){
            for(int i=1;i<=coins.size();i++){
                if(j<coins[i-1]){
                    sum[i][j] = sum[i-1][j];
                }
                else if(j>=coins[i-1]){
                    if(sum[i-1][j]>sum[i][j-coins[i-1]]+1){
                        sum[i][j] = sum[i][j-coins[i-1]]+1;
                    }
                    else sum[i][j] = sum[i-1][j];
                }
            }
        }
        int min = int_max;
        for(int i=1;i<=coins.size();i++){
            if(min > sum[i][amount]) min = sum[i][amount];
        }
        if(min>=int_max) return -1;
        else return min;
    }
};