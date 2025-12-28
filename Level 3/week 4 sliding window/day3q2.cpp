/* https://leetcode.com/problems/permutation-in-string/ */

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n= s1.length();
        map<char, int>a;
        for(auto i:s1) a[i]++;

        int i=0, j=0;
        map<char, int>b;
        while(j<s2.length()){
            char x= s2[i];
            char y= s2[j];
            
            if(a[y]<=0){  // the case when y is not present in s1
                j++;
                i=j;
                b.clear();
                continue;
            }

            b[y]++;
            if(b[y]>a[y]){  // y is coming more than y in s1
                while(s2[i]!=y){
                    b[s2[i]]--;
                    i++;
                }
                b[s2[i]]--;
                i++;
            }

            if(j-i+1 == n) return true;
            j++;
        }
        return false;
    }
};
