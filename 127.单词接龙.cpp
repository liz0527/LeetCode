class Solution {
public:
    int compareCount(string a, string b){//返回两个等长字符串不一样的字符个数
        int count=0,len = a.length();
        for(int i=0;i<len;i++){
            if(a[i]!=b[i]) count++;
        }
        return count;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int len = wordList.size(),end=-1;
        int visited[len+1];
        //vector<int> row;
        //vector<vector<int>> map;
        for(int i=0;i<len;i++){//找endWord的位置 
            if(wordList[i]==endWord){
                end = i;
                break; 
            }
        }
        if(end == -1) return 0;
        /*for(int i=0;i<len;i++){//初始化邻接矩阵 
            for(int j=0;j<len;j++){
                if(compareCount(wordList[i],wordList[j])==1){
                    row.push_back(j);
                }
            }
            map.push_back(row);
            row.clear();
        }*/
        for(int k=0;k<len;k++){
            visited[k]=0;
        }
        queue<int> q;
        for(int i=0;i<len;i++){//找beginWord的邻接点
            if(beginWord==wordList[i]||compareCount(beginWord,wordList[i])==1){
                q.push(i);
                visited[i]=1;
                if(i==end){
                    return visited[i]+1;
                }
            }
        }
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            /*for(int i=0;i<map[temp].size();i++){
                if(visited[map[temp][i]]==0){//有边且没被访问过 
                    visited[map[temp][i]]=visited[temp]+1;
                    q.push(map[temp][i]);
                    if(map[temp][i]==end){
                        return visited[map[temp][i]]+1;
                    }
                }
            }*/
            for(int i=0;i<wordList.size();i++){
                if(visited[i]==0 && compareCount(wordList[temp],wordList[i])==1){
                    visited[i] = visited[temp]+1;
                    q.push(i);
                    if(i==end) return visited[i]+1;
                }
            }
        }
        return 0;
    }
};