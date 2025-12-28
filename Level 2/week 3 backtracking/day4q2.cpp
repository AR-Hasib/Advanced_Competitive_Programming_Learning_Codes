/* https://leetcode.com/problems/restore-ip-addresses/description/ */

class Solution {
public:
    vector<string>ans;

    bool check(string s){
        int num= stoi(s);
        string newStr= to_string(num);
        return (s == newStr && num<256);
    }

    void solve(int idx, int part, string &s, string curr){
        if(idx==s.size()){
            if(part==4){
                curr.pop_back();
                ans.push_back(curr);
            }
            return;
        }

        for(int i=1; i<=3; i++){
            if(idx+i<=s.size() && check(s.substr(idx, i))){
                solve(idx+i, part+1, s, curr+s.substr(idx, i)+".");
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        solve(0, 0, s, "");
        return ans;
    }
};