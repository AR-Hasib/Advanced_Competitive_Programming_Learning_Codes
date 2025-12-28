#include <bits/stdc++.h>
using namespace std;

/* this segment is built to calculate the sum from L to R. everything is in 0 base indexing.
 this is to understand the basic of sgt. There is a template.*/

class SegmentTree {
private:
    vector<int> arr, sgt;

    // child index calculations (0-based)
    int leftChild(int index) { return 2 * index + 1; }
    int rightChild(int index) { return 2 * index + 2; }

public:
    SegmentTree(int n, const vector<int>& a) {
        sgt.assign(4 * n, 0);
        arr = a;
    }

    void build(int s, int e, int index) {
        // leaf node
        if (s == e) {
            sgt[index] = arr[s];
            return;
        }

        int mid = (s + e) / 2;
        // building left and right child
        build(s, mid, leftChild(index));
        build(mid + 1, e, rightChild(index));

        // --------->> update area <<---------
        sgt[index] = sgt[leftChild(index)] + sgt[rightChild(index)];
    }

    void update(int s, int e, int index, int up_index, int up_value) {
        if (s == e) {
            sgt[index] = up_value;
            return;
        }

        int mid = (s + e) / 2;
        // finding the node
        if (mid >= up_index) {
            update(s, mid, leftChild(index), up_index, up_value);
        } else {
            update(mid + 1, e, rightChild(index), up_index, up_value);
        }

        // --------->> update area <<---------
        sgt[index] = sgt[leftChild(index)] + sgt[rightChild(index)];
    }

    int query(int s, int e, int index, int l, int r) {
        // no overlap
        if (e < l || r < s) return 0;

        // full overlap
        if (s >= l && e <= r) return sgt[index];

        // partial overlap
        int mid = (s + e) / 2;
        int leftContribution = query(s, mid, leftChild(index), l, r);
        int rightContribution = query(mid + 1, e, rightChild(index), l, r);
        // --------->> update area <<---------
        return leftContribution + rightContribution;
    }
};


// SegmentTree sg(n, a)