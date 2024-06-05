#include <bits/stdc++.h>
#define int long long 
#define ll long long 
using namespace std;



//.............................................................................................



struct Node {
    Node* links[26];
    bool f = false;

    bool conKey(char c) {
        return links[c - 'a'] != nullptr;
    }

    void put(char c, Node* node) {
        links[c - 'a'] = node;
    }

    Node* get(char c) {
        return links[c - 'a'];
    }

    void setEnd() {
        f = true;
    }

    bool isEnd() {
        return f == true;
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(std::string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->conKey(word[i]))
                node->put(word[i], new Node());
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool search(std::string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->conKey(word[i]))
                return false;
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    bool startsWith(std::string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->conKey(word[i]))
                return false;
            node = node->get(word[i]);
        }
        return true;
    }
};




//.............................................................................................
// Disjoint Set ...
class disjointSet {

    vector<int> rank;
    vector<int> parent;
    vector<int> size;

public:

    disjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1, 0);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int find(int node) {
        if (parent[node] == node) return node;
        return parent[node] = find(parent[node]);
    }

    void unionR(int u, int v) {
        int pu = find(u), pv = find(v);

        if (pu == pv) return; 
        if (rank[pu] > rank[pv])
            parent[pv] = pu;
        else if (rank[pu] < rank[pv])
            parent[pu] = pv;
        else {
            parent[pv] = pu;
            rank[pu]++;    
        }
    }

    void unionS(int u, int v) {
        int pu = find(u), pv = find(v);

        if (pu == pv) return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};
//.............................................................................................

 int mod1 = 1e9 + 7;


int small_exp(int a, int b) {
    if (b == 0)
        return 1;

    int res = small_exp(a, b / 2);

    if (b & 1)
        return (a * ((res * res) % mod1)) % mod1;
    else
        return ((res * res) % mod1) % mod1;
}



// Exponentiation for large a and mod...
// a <= 1e18 + 7 || mod <= 1e18 + 7
int mod2 = 1e18 + 7;
ll Binary_Multiply ( ll a, ll b ) {
    ll mod = 1e18 + 7;
    ll ans = 0;

    while (b > 0) {
        if (b & 1) ans = (ans + a) % mod;
        a = (a + a) % mod;
        b >>= 1;
    }
    return ans;
}



ll large_exp( ll a, ll b) {
    ll ans = 1;

    while (b > 0) {
        if (b & 1) ans = Binary_Multiply(a, b);
        a = Binary_Multiply(a, a);
        b >>= 1;
    }
    return ans;
}

//................................................................................................






int32_t main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;

    while (t--) 
{
        string s;
        cin>>s;
}
    return 0;
}