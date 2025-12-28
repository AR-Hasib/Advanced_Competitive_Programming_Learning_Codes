/* https://leetcode.com/problems/sum-of-prefix-scores-of-strings/description/ */

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
//using namespace __gnu_pbds;
using namespace std;
///////////////////////////////////////////////////////////

class TrieNode{
public:
    // this is the main data structure
    bool isSpecial;
    TrieNode *children[26];
    int sum;
    TrieNode(){
        isSpecial = false;
        sum = 0;
        for(int i=0; i<26; i++)
            children[i]=NULL;
    }
};

class Trie{
public:
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }
    
    void insert(string word){
        TrieNode *curr = root;
        for(auto ch:word){
            if(curr->children[ch-'a'] == NULL)
                curr->children[ch-'a'] = new TrieNode();
            curr = curr->children[ch-'a'];
            curr->sum++;
        }
        curr->isSpecial = true;
    }
    
    int prefixSum(string s){
        TrieNode *curr = root;
        int total = 0;
        for(auto ch:s){
            if(curr->children[ch-'a']==NULL) return total;
            curr = curr->children[ch-'a'];
            total += curr->sum;
        }
        return total;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie* t = new Trie();
        for(auto str:words) t->insert(str);

        vector<int> ans;
        for(auto str:words){
            int x = t->prefixSum(str);
            ans.push_back(x);
        }
        return ans;
    }
};