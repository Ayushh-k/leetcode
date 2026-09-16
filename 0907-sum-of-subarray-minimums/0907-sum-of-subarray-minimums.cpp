class Solution {
public:

    vector<int> nextSmallestEle(vector<int> arr){
        stack<int> s;
        vector<int> ans(arr.size(), -1);

        for(int i = arr.size()-1; i>=0; i--){
            while(!s.empty() && arr[s.top()] >= arr[i]){
                s.pop();
            }

            if(!s.empty()){
                ans[i] = s.top();
            }

            s.push(i);
        }
        return ans;
    }

    vector<int> prevSmallestEle(vector<int> arr){
        stack<int> s;
        vector<int> ans(arr.size(), -1);

        for(int i = 0;i <arr.size(); i++){
            while(!s.empty() && arr[s.top()]>arr[i]){
                s.pop();
            }

            if(!s.empty()){
                ans[i] = s.top();
            }

            s.push(i);
        }

        return ans;
    }

    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = nextSmallestEle(arr);
        vector<int> pse = prevSmallestEle(arr);

        long long total = 0;
        int mod = 1e9 + 7;

        for(int i = 0; i<arr.size(); i++){
            long long left = i - pse[i];
            long long right = (nse[i] == -1)? arr.size()-i: nse[i] - i;

            total = (total + left * right * arr[i])%mod;
        }
        return total;
    }
};