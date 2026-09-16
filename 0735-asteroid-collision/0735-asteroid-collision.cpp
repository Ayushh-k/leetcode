class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;

        for(auto as : asteroids){
            if(as > 0) {
                 s.push(as);
            }else{
                while(!s.empty() && as < 0 && s.top() < -as && s.top()> 0){
                    s.pop();
                }


                if(!s.empty() && s.top() == -as){
                    s.pop();
                }else if(s.empty() || s.top() < 0){
                    s.push(as);
                }
            }
        }

        vector<int> ans(s.size());
        for(int i=s.size()-1;i>=0; i--){
            ans[i] = s.top();
            s.pop();
        }
        return ans;
    }
};