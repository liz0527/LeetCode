int candy(int* ratings, int ratingsSize) {
    int candy[ratingsSize];
    int count=0;
    /*初始每个孩子至少一个糖果*/
    for(int i=0;i<ratingsSize;i++){
        candy[i]=1;
    }
    if(ratingsSize==0||ratingsSize==1) return ratingsSize;
    /*正序遍历*/
    for(int i=1;i<ratingsSize;i++){
        if(ratings[i-1]<ratings[i] && candy[i-1]>=candy[i]){
            candy[i]=candy[i-1]+1;
        }
    }
    /*逆序遍历*/
    for(int i=ratingsSize-1;i>0;i--){
        if(ratings[i-1]>ratings[i]&& candy[i-1]<=candy[i]){
            candy[i-1]=candy[i]+1;
        }
    }
    /*求和*/
    for(int i=0;i<ratingsSize;i++){
        count+=candy[i];
    }
    return count;
}