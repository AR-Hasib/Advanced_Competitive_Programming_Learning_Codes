/* https://leetcode.com/problems/map-sum-pairs/description/ */

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
    
    void insert(string word, int value){
        TrieNode *curr = root;
        for(auto ch:word){
            if(curr->children[ch-'a'] == NULL)
                curr->children[ch-'a'] = new TrieNode();
            curr = curr->children[ch-'a'];
            curr->sum += value;
        }
        curr->isSpecial = true;
    }
    
    int prefixSum(string word){
        TrieNode *curr = root;
        for(auto ch:word){
            if(curr->children[ch-'a']==NULL) return 0;
            curr = curr->children[ch-'a'];
        }
        return curr->sum;
    }
};

class MapSum {
public:
    Trie* t;
    unordered_map<string, int> m;

    MapSum() {
        t = new Trie();
    }
    
    void insert(string key, int val) {
        int value = val-m[key];
        t->insert(key, value);
        m[key] = val;
        return;
    }
    
    int sum(string prefix) {
        return t->prefixSum(prefix);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */