#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()

template<typename Node, typename Update>
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
            tree[index].val += (end - start + 1) * lazy[index];

            if(start != end){
                lazy[2 * index ] += lazy[index];
                lazy[2 * index + 1] += lazy[index];
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
	void update(int start, int end, int index, int l, int r, Update &u)  // no need of change
	{
        push(start, end, index);
        if(start > r || end < l) return;
		if (start >= l && end <=r) {
			u.apply(lazy, index);
            push(start, end, index);
			return;
		}
		int mid = (start + end) / 2;
		update(start, mid, 2 * index, l, r, u);
		update(mid + 1, end, 2 * index + 1, l ,r, u);
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
	void make_update(int l, int r, ll val) {  // pass in as many parameters as required
		Update new_update = Update(val); // may change
		update(0, n - 1, 1, l, r, new_update);
	}
	Node make_query(int left, int right) {
		return query(0, n - 1, 1, left, right);
	}
};

class Node1 {
public:
	ll val; // may change
	Node1() { // Identity element
		val = 0;	// may change
	}
	Node1(ll p1) {  // Actual Node
		val = p1; // may change
	}
	void merge(Node1 &l, Node1 &r) { // Merge two child nodes
		val = l.val + r.val;  // may change
	}
};

class Update1 {
public:
	ll val; // may change
	Update1(ll p1) { // Actual Update
		val = p1; // may change
	}
	void apply(vector<ll> &lazy, int index) { // apply update to given node
		lazy[index] += val; // may change
	}
};


// example usage
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Example usage:
    int n = 5;
    vector<ll> data = {1, 3, 5, 7, 9};

    // Create the segment tree
    SegTree<Node1, Update1> seg(n, data);

    // Query sum from index 1 to 3 (0-based)
    Node1 result = seg.make_query(1, 3);
    cout << "sum from index 1 to 3: " << result.val << '\n'; 

    // add something from index 2 to 3 with value 4
    seg.make_update(2, 3, 4);

    // Query again after update
    result = seg.make_query(1, 3);
    cout << "After update, sum from index 1 to 3: " << result.val << '\n';  

    return 0;
}
