class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        /*按体重从小到大排序*/
        sort(people.begin(), people.end());
        /*设置双指针*/
        int i = 0, j = people.size() - 1;
        int ans = 0;

        while (i <= j) {
            ans++;//申请一艘船
            if (people[i] + people[j] <= limit)//如果当前最重的人和最轻的人体重和小于载重量，就将最轻的人安排上
                i++;
            j--;//不论如何，最重的人一定会被安排上
        }

        return ans;
    }
};