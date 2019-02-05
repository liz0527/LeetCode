int maxProfit(int* prices, int pricesSize) {
    /*贪心策略是向后找当前递增顺序上的终点*/
    int max=0;//记录递增顺序的标志
    int price=0;//利润和
    int i;
    for(i=0;i<pricesSize;i++){
        int j;
        for(j=i+1;j<pricesSize;j++){//从当前向后遍历
            if(prices[j]>=prices[j-1]){
                if(j!=pricesSize-1){//如果递增且没到数组最后一个，标志设为1
                    max++;
                }
                else{//如果递增且到了数组最后一个，直接卖出，跳出循环
                    price += prices[j]-prices[i];
                    i=j;
                }
                
            }
            else if(prices[j]<prices[j-1]){
                if(max){//如果上一个仍递增，当前开始不递增了，就在上一天卖出，且从这一天重新开始遍历
                    price += prices[j-1] - prices[i];
                    i=j-1;
                }
                max=0;
                break;
            }
        }
    }
    return price;
}