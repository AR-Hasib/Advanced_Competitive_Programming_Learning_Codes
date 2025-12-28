/* https://leetcode.com/problems/longest-word-in-dictionary/description/ */

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
    TrieNode(){
        isSpecial = false;
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
        }
        curr->isSpecial = true;
    }
    
    bool allPresent(string s){
        TrieNode *curr = root;
        for(auto ch:s){
            if(curr==root || curr->isSpecial) curr = curr->children[ch-'a'];
            else return false;
        }
        return true;
    }
};


class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie* t = new Trie();
        for(auto str:words) t->insert(str);

        string ans = "";
        for(auto str:words){
            if(t->allPresent(str) && ans.size()<=str.size()){
                ans = (ans.size()==str.size())? min(ans, str):str;
            }
        }
        return ans;
    }
};