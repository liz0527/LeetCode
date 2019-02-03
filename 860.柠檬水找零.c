bool lemonadeChange(int* bills, int billsSize) {
    /*贪心策略是使手中剩下尽量多的五美元钞票*/
    int five=0,ten=0;//存放现有钞票
    bool check=true;//是否能正确找零
    for(int i=0;i<billsSize;i++){
        if(bills[i]==5){
            five++;
        }
        else if(bills[i]==10 && five){
            five--;
            ten++;
        }
        else if(bills[i]==20&&five>=1&&ten>=1){
            five--;
            ten--;
        }
        else if(bills[i]==20&&five>=3){
            five-=3;
        }
        else check=false;
    }
    return check;
}