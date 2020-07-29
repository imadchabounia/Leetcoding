class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> cnt;
        for(char c : tasks) !cnt[c]++;
        deque<int> dq(n, -1);
        priority_queue<int> pq;
        for(pair<char, int> p : cnt) pq.push(p.second);
        int time = 0;
        int items = tasks.size();
        while(items>0){
            int top = -1;
            if(!pq.empty()){
                top = pq.top();
                pq.pop();
                top--;
                items--;
            }
            time++;
            dq.push_back(top);
            if(!dq.empty()){
                int front = dq.front();
                dq.pop_front();
                if(front>0) pq.push(front);
            }
        }
        return time;
    }
};
