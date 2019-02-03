/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 * };
 */
/*贪心算法之会议安排问题的变形。贪心策略是寻找终点最早的区间，使互不重叠的区间尽量多。即剩下的需要移除的区间尽量少。*/
/*排序*/
void sort(struct Interval* intervals, int intervalsSize){
    for(int i=0;i<intervalsSize;i++){
        for(int j=0;j<intervalsSize-i-1;j++){
            if(intervals[j].end > intervals[j+1].end){
                struct Interval temp = intervals[j];
                intervals[j] = intervals[j+1];
                intervals[j+1]=temp;
            }
            else if(intervals[j].end == intervals[j+1].end)
                if(intervals[j].start < intervals[j+1].start){
                    struct Interval temp = intervals[j];
                    intervals[j] = intervals[j+1];
                    intervals[j+1]=temp;
                }
        }
    }
}
int eraseOverlapIntervals(struct Interval* intervals, int intervalsSize) {
    int n=0;//已不重叠的区间
    int last;//最后一个区间的终点
    sort(intervals,intervalsSize);
    last= intervals[0].start;
    for(int i=0;i<intervalsSize;i++){
        if(last <= intervals[i].start){
            n++;
            last = intervals[i].end;
        }
    }
    return (intervalsSize-n);
}