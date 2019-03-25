class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int len = wordList.size();
        unordered_map<string,int> m;//记录是否被访问过以及其步数
        for(int i=0;i<len;i++){
            m[wordList[i]] = 0;
        }
        queue<string> q;
        q.push(beginWord);
        m[beginWord] = 1;
        while(!q.empty()){
            string temp = q.front();
            q.pop();
            for(int i=0;i<temp.length();i++){
                string str = temp;
                for(char c='a';c<='z';c++){
                    str[i] = c;
                    if(m.find(str)!=m.end() && m[str]==0){
                        q.push(str);
                        m[str] = m[temp]+1;
                        if(endWord==str) return m[str];
                    }
                }
            }
        }
        return 0;
    }
};