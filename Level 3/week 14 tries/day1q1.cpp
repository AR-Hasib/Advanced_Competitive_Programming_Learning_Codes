/* https://leetcode.com/problems/implement-trie-prefix-tree/ */

#include <bits/stdc++.h>
//using namespace __gnu_pbds;
using namespace std;
/////////////////////////////////////////////////////////////////

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
    
    bool search(string word){
        TrieNode *curr = root;
        for(auto ch:word){
            if(curr->children[ch-'a']==NULL) return false;
            curr = curr->children[ch-'a'];
        }
        return curr->isSpecial;
    }
    
    bool startsWith(string prefix){
        TrieNode *curr = root;
        for(auto ch:prefix){
            if(curr->children[ch-'a']==NULL) return false;
            curr = curr->children[ch-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */