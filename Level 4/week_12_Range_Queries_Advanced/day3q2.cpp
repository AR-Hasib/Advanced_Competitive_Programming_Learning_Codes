/* https://codeforces.com/edu/course/2/lesson/5/2/practice/contest/279653/problem/C */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()

template<typename Node>
class SegTree {
public:
	vector<Node> tree;
	vector<ll> arr; // type may change
	vector<ll> lazy; // type may change
	int n;
	int s;
	SegTree(int a_len, vector<ll> &a) { // change if type updated
		arr = a;
		n = a_len;
		s = 1;
		while(s < 2 * n){
			s = s << 1;
		}
		tree.resize(s); fill(all(tree), Node());
        lazy.resize(s); fill(all(lazy), 0);
		build(0, n - 1, 1);
	}
    void push(int start, int end, int index){ // may change
        if(lazy[index]){
            tree[index].val |= lazy[index];

            if(start != end){
                lazy[2 * index] |= lazy[index];
                lazy[2 * index+1] |= lazy[index];
            }
            lazy[index] = 0;
        }
    }
	void build(int start, int end, int index)  // Never change this
	{
		if (start == end)	{
			tree[index] = Node(arr[start]);
			return;
		}
		int mid = (start + end) / 2;
		build(start, mid, 2 * index);
		build(mid + 1, end, 2 * index + 1);
		tree[index].merge(tree[2 * index], tree[2 * index + 1]);
	}
	void update(int start, int end, int index, int l, int r, int val)  // no need of change
	{
        push(start, end, index);
        if(start > r || end < l) return;
		if (start >= l && end <=r) {
            lazy[index] |= val;
            push(start, end, index);
			return;
		}
		int mid = (start + end) / 2;
		update(start, mid, 2 * index, l, r, val);
		update(mid + 1, end, 2 * index + 1, l ,r, val);
		tree[index].merge(tree[2 * index], tree[2 * index + 1]);
	}
	Node query(int start, int end, int index, int left, int right) { // Never change this
		push(start, end, index);
        if (start > right || end < left)
			return Node();
		if (start >= left && end <= right)
			return tree[index];
		int mid = (start + end) / 2;
		Node l, r, ans;
		l = query(start, mid, 2 * index, left, right);
		r = query(mid + 1, end, 2 * index + 1, left, right);
		ans.merge(l, r);
		return ans;
	}
	void make_update(int l, int r, int val) {  // pass in as many parameters as required
		update(0, n - 1, 1, l, r, val);
	}
	Node make_query(int left, int right) {
		return query(0, n - 1, 1, left, right);
	}
};

class Node1 {
public:
	ll val; // may change
	Node1() { // Identity element
		val = (1LL << 32) - 1;
		// val = 0;	// wrong
	}
	Node1(ll p1) {  // Actual Node
		val = p1; // may change
	}
	void merge(Node1 &l, Node1 &r) { // Merge two child nodes
		val = l.val & r.val;  // may change
	}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin>>n>>q;
    vector<ll> data(n); fill(all(data), 0);

    SegTree<Node1> seg(n, data);

    while(q--){
        int type; cin>>type;
        if(type == 1){
            int a, b, val; cin>>a>>b>>val;
            seg.make_update(a, b-1, val);
        }else{
            int a, b; cin>>a>>b;
            Node1 ans = seg.make_query(a, b-1);
            cout<<ans.val<<endl;
        }
    }

    return 0;
}
