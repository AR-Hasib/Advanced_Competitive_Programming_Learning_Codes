/* https://codeforces.com/problemset/problem/1234/d */

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
//using namespace __gnu_pbds;
using namespace std;
//template<typename T>
//using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define endl '\n'
#define ll long long
#define ld long double
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define precision fixed<<setprecision
#define toLDouble static_cast<long double>
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define setAll(x, y) memset(x, y, sizeof(x))
#define printVector(vctr) for(auto &vlu:vctr) cout<<vlu<<" "; cout<<endl;
#define VV(x) vector<vector<x>>

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

#define ll long long
#define all(x) (x).begin(), (x).end()



template<typename Node, typename Update>
class SegTree {
public:
    vector<Node> tree;
    vector<ll> arr; // type may change
    int n;
    int s;
    SegTree(int a_len, vector<ll> &a) { // change if type updated
        arr = a;
        n = a_len;
        s = 1;
        while (s < 2 * n) {
            s = s << 1;
        }
        tree.resize(s); fill(all(tree), Node());
        build(0, n - 1, 1);
    }

    void build(int start, int end, int index)  // Never change this
    {
        if (start == end) {
            tree[index] = Node(arr[start]);
            return;
        }
        int mid = (start + end) / 2;
        build(start, mid, 2 * index);
        build(mid + 1, end, 2 * index + 1);
        tree[index].merge(tree[2 * index], tree[2 * index + 1]);
    }

    void update(int start, int end, int index, int query_index, Update &u)  // Never Change this
    {
        if (start == end) {
            u.apply(tree[index]);
            return;
        }
        int mid = (start + end) / 2;
        if (mid >= query_index)
            update(start, mid, 2 * index, query_index, u);
        else
            update(mid + 1, end, 2 * index + 1, query_index, u);
        tree[index].merge(tree[2 * index], tree[2 * index + 1]);
    }

    Node query(int start, int end, int index, int left, int right) { // Never change this
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

    void make_update(int index, ll val) {  // pass in as many parameters as required
        Update new_update = Update(val); // may change
        update(0, n - 1, 1, index, new_update);
    }

    Node make_query(int left, int right) {
        return query(0, n - 1, 1, left, right);
    }
};

class Node1 {
public:
    vector<ll> v; // may change
    Node1() { // Identity element
        v.assign(26, 0); // may change
    }
    Node1(ll p1) {  // Actual Node
        v.assign(26, 0); // may change
        v[p1] = 1;
    }
    void merge(Node1 &l, Node1 &r) { // Merge two child nodes
        for(int i=0; i<26; i++){
            v[i] = l.v[i] + r.v[i];
        }
    }
};

class Update1 {
public:
    ll val; // may change
    Update1(ll p1) { // Actual Update
        val = p1; // may change
    }
    void apply(Node1 &a) { // apply update to given node
        for(int i=0; i<26; i++) a.v[i] = 0;
        a.v[val] = 1;
    }
};

void solve(){
    int n, q; string s;
    cin>>s>>q;
    n = s.size();
    vector<ll> a(n);
    for(int i=0; i<n; i++) a[i] = s[i]-'a';

    SegTree<Node1, Update1> seg(n, a);

    while(q--){
        int type; cin>>type;
        if(type == 1){
            int idx; char value;
            cin>>idx>>value;
            seg.make_update(idx-1, (value-'a'));
        }else{
            int l, r; cin>>l>>r;
            Node1 result = seg.make_query(l-1, r-1);
            int ans = 0;
            for(int i=0; i<26; i++){
                if(result.v[i] > 0) ans++;
            }
            cout<<ans<<endl;
        }
    }
    return;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc=1;
    while(tc--){
        solve();
    }
    return 0;
}