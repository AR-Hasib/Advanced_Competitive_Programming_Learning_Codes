/* https://www.geeksforgeeks.org/problems/sum-string3151/1 */

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string string_sum(string str1, string str2){
        if(str1.size() < str2.size()) swap(str1, str2);

        int m= str1.size();
        int n= str2.size();
        string ans= "";
        int carry= 0;

        // adding digits from right to left
        for(int i=0; i<n; i++){
            int ds= ((str1[m-1-i]-'0') + (str2[n-1-i]-'0') + carry)%10;
            carry = ((str1[m-1-i]-'0') + (str2[n-1-i]-'0') + carry)/10;
            ans = char(ds+'0') + ans;
        }

        // adding remaining digits from str1
        for(int i=n; i<m; i++){
            int ds = (str1[m-1-i]-'0' + carry)%10;
            carry = (str1[m-1-i]-'0' + carry)/10;
            ans = char(ds+'0')+ans;
        }

        // adding the final carry if present
        if(carry) ans=char(carry + '0') + ans;
        return ans;
    }

    bool check_Sum(string str, int beg, int len1, int len2){
        string s1= str.substr(beg, len1);
        string s2= str.substr(beg+len1, len2);
        string s3= string_sum(s1, s2);
        int s3_len= s3.size();

        if(s3_len > str.size()-len1-len2-beg) return false;

        if(s3==str.substr(beg+len1+len2, s3_len)){
            if(beg+len1+len2+s3_len == str.size()) return true;

            return check_Sum(str, beg+len1, len2, s3_len);
        }
        return false;
    }

    bool isSumStr(string str){
        int n= str.size();

        for(int i=1; i<n; i++){
            for(int j=1; i+j<n; j++){
                if(check_Sum(str, 0, i, j))
                    return true;
            }
        }

        return false;
    }

    int isSumString(string S){
        return isSumStr(S);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.isSumString(S) << endl;
    }
    return 0; 
} 