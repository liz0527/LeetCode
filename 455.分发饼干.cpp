class Solution {
	/*贪心策略是尽量用最小的饼干，满足最小的胃口的孩子。*/
	public int findContentChildren(vector<int>& g, vector<int>& s) {
		int child = 0;
        int cookie = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        while(child<g.size() && cookie < s.size()){ //当其中一个遍历完就结束
            if(g[child]<=s[cookie]){//当用当前饼干可以满足当前孩子的需求，可以满足的孩子数量+1
                child++;
            }
            cookie++;//饼干只可以用一次，因为饼干如果小的话，就是无法满足被抛弃，满足的话就是被用了
        }
        return child;
	}
}