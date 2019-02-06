void sort(int** points,int pointsRowSize, int pointsColSize ){
    for(int i=0;i<pointsRowSize;i++){
        for(int j=0;j<pointsRowSize-i-1;j++){
            if(points[j][1]>points[j+1][1]){
                int temp = points[j][0];
                points[j][0] = points[j+1][0];
                points[j+1][0] = temp;
                int temp2 = points[j][1];
                points[j][1] = points[j+1][1];
                points[j+1][1] = temp2;
            }
        }
    }
}
int findMinArrowShots(int** points, int pointsRowSize, int pointsColSize) {
    /*只要找出不相互重叠的区间数量就是所需弓箭的数量。*/
    int last;
    int count=0;
    sort(points,pointsRowSize,pointsColSize);
    if(pointsRowSize>0){
        last = points[0][1];
        count=1;
    } 
    for(int i=1;i<pointsRowSize;i++){
        if(points[i][0]>last){
            count++;
            last = points[i][1];
        }
    }
    
    return count;
}