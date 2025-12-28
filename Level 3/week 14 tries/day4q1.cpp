/* https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/description/ */

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
    TrieNode *children[2];
    TrieNode(){
        isSpecial = false;
        for(int i=0; i<2; i++)
            children[i]=NULL;
    }
};

class Trie{
public:
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }
    
    void insert(int num){
        TrieNode *curr = root;
        for(int bit=31; bit>=0; bit--){
            int bitValue = (((1<<bit)&num)==0)? 0:1;
            if(curr->children[bitValue]==NULL)
                curr->children[bitValue] = new TrieNode();
            curr = curr->children[bitValue];
        }
        curr->isSpecial=true;
    }
    
    int maxXor(int num){
        TrieNode *curr = root;
        int maxVal = 0;
        for(int bit=31; bit>=0; bit--){
            int bitValue = (((1<<bit)&num)==0)? 0:1;
            int oppBit = bitValue^1;

            if(curr->children[oppBit] != NULL){
                maxVal |= (1<<bit);
                curr = curr->children[oppBit];
            }else{
                curr = curr->children[bitValue];
            }
        }
        return maxVal;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* t = new Trie();
        for(auto x:nums) t->insert(x);
        int ans = 0;
        for(auto x:nums) ans = max(t->maxXor(x), ans);
        return ans;
    }
};