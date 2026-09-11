class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto ch : s){
            if(ch == '[' || ch == '{' || ch == '('){
                st.push(ch);
            }else{
                if(st.empty()) return false;

                char top = st.top();
                st.pop();

                if(top == '(' && ch!=')') return false;
                if(top == '{' && ch!='}') return false;
                if(top == '[' && ch!=']') return false;
            }
        }

        return st.empty();
    }
};