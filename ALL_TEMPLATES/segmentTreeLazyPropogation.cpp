#define ll long long
#define all(x) (x).begin(), (x).end()

template<typename Node, typename Update>
class SegTree {
public:
    vector<Node> tree;
    vector<ll> arr;
    vector<ll> lazy;
    int n;
    int s;

    SegTree(int a_len, vector<ll> &a) {
        arr = a;
        n = a_len;
        s = 1;
        while (s < 2 * n) {
            s = s << 1;
        }
        tree.resize(s); fill(all(tree), Node());
        lazy.resize(s); fill(all(lazy), 0);
        build(0, n - 1, 1);
    }

    void push(int start, int end, int index) {
        if (lazy[index]) {
            tree[index].val += (end - start + 1) * lazy[index];
            if (start != end) {
                lazy[2 * index] += lazy[index];
                lazy[2 * index + 1] += lazy[index];
            }
            lazy[index] = 0;
        }
    }

    void build(int start, int end, int index) {
        if (start == end) {
            tree[index] = Node(arr[start]);
            return;
        }
        int mid = (start + end) / 2;
        build(start, mid, 2 * index);
        build(mid + 1, end, 2 * index + 1);
        tree[index].merge(tree[2 * index], tree[2 * index + 1]);
    }

    void update(int start, int end, int index, int l, int r, Update &u) {
        push(start, end, index);
        if (start > r || end < l) return;
        if (start >= l && end <= r) {
            u.apply(lazy, index);
            push(start, end, index);
            return;
        }
        int mid = (start + end) / 2;
        update(start, mid, 2 * index, l, r, u);
        update(mid + 1, end, 2 * index + 1, l, r, u);
        tree[index].merge(tree[2 * index], tree[2 * index + 1]);
    }

    Node query(int start, int end, int index, int left, int right) {
        push(start, end, index);
        if (start > right || end < left) return Node();
        if (start >= left && end <= right) return tree[index];
        int mid = (start + end) / 2;
        Node l, r, ans;
        l = query(start, mid, 2 * index, left, right);
        r = query(mid + 1, end, 2 * index + 1, left, right);
        ans.merge(l, r);
        return ans;
    }

    void make_update(int l, int r, ll val) {
        Update new_update = Update(val);
        update(0, n - 1, 1, l, r, new_update);
    }

    Node make_query(int left, int right) {
        return query(0, n - 1, 1, left, right);
    }
};

class Node1 {
public:
    ll val;
    Node1() { val = 0; }
    Node1(ll p1) { val = p1; }
    void merge(Node1 &l, Node1 &r) { val = l.val + r.val; }
};

class Update1 {
public:
    ll val;
    Update1(ll p1) { val = p1; }
    void apply(vector<ll> &lazy, int index) { lazy[index] += val; }
};