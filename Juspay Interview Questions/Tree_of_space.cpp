/*
You are given a complete, balanced M-Ary Tree and must support Q queries. There are 3 kinds of queries. Return true or false depending on whether the query was successful.

Lock(v, id) - Lock vertex v for user - id
Unlock(v, id) - If vertex v is locked by the same id, unlock it.
Upgrade(v, id) - If v is unlocked and has at least one locked vertex in it's subtree and every locked vertex in the subtree of v is locked by id, unlock them and lock v instead.
Further, here are some additional constraints

A vertex cannot be locked if it has any locked ancestors or descendants, by any ID.
When a vertex is upgraded, it's locked descendants are automatically unlocked.
An upgrade operation is not possible if the vertex is already locked or has any locked ancestors
An unlock operation is only possible if the vertex is already locked and locked by the same id
P.S. - The question was very badly stated and not a single constraint was mentioned openly on the problem statement. A lot of these constraints had to be deduced by supplying custom input and observing the expected output. There were no constraints on the size of the variables.
*/

#include <bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
        TreeNode* parent;
        string name;
        int uid;
        bool isLocked;
        bool isLockable;
        vector<TreeNode*> children;
        unordered_set<TreeNode*> locks;
        
        TreeNode() {
            parent = NULL;
            name = "";
            uid = -1;
            isLocked = false;
            isLockable = true;
            children = {};
            locks = {};
        }

        TreeNode(string n) {
            parent = NULL;
            name = n;
            uid =- 1;
            isLocked = false;
            isLockable = true;
            children = {};
            locks = {};
        }

        TreeNode(TreeNode* p, string n) {
            parent = p;
            name = n;
            uid = -1;
            isLocked = false;
            isLockable = true;
            children = {};
            locks = {};
        }
};

unordered_map<string, TreeNode*> mp;

bool Lock(TreeNode* node, int uid) {
    /*
    Optimised method is to check if any parent is locked instead of checking the desscendants.
    */

    /*
    Time complexity:
    Space complexity:
    */

    cout<<node->isLockable<<", "<<node->isLocked<<", "<<node->uid<<", "<<node->locks.size()<<"\n";

    if ((node->isLocked) || (node->isLockable = false)) return false;

    TreeNode* parent = node->parent;

    while (parent) {
        if (parent->isLocked) return false;
        parent = parent->parent;
    }

    //Lock the node:
    node->uid = uid;            
    node->isLocked = true;
    node->isLockable = false;       
    
    //inform the ancestors:
    parent = node->parent;
    while (parent) {
        parent->isLockable = false;
        parent->locks.insert(node);
        parent = parent->parent;
    }
    
    return true;
}

bool UnLock(TreeNode* node, int uid) {
    /*
    Time complexity:
    Space complexity:
    */

    if ((node->isLockable) || (node->isLocked && (node->uid != uid))) return false;

    //Unlock the node having the given uid
    node->isLocked = false;
    node->isLockable = true;
    node->uid = -1;
    
    //inform the ancestors that the given node is unlocked
    TreeNode* parent = node->parent;
    while (parent) {
        parent->isLockable = true;
        parent->locks.erase(node);
        parent = parent->parent;
    }

    return true;
}

bool Upgrade(TreeNode* node, int uid) {
    /*
    Note: This function doesn't work when there are 0 locked nodes in its sub-tree.
    */

    /*
    Time complexity:
    Space complexity:
    */

    if (!(node->locks.size()) || (node->isLocked)) return false;

    //check if the locked nodes in the subtree have the same uid. Return false if different uid found.
    for (auto lock : node->locks) 
        if (lock->uid != uid) return false;

    //unlock the locks in the subtree
    /*
    Note: directly updating the tree structure while iterating over it can cause segementation faults.
        So while unlocking the nodes, populate the locked nodes from node->locks into a new set called locks.
    */
    unordered_set<TreeNode*> locks;
    bool upgrade = true;

    for (auto lock : node->locks) 
        locks.insert(lock);

    for (auto lock : locks) 
        upgrade &= UnLock(lock, uid);

    //Lock the current node with the same uid
    return upgrade & Lock(node, uid);
}

void PrintTree(TreeNode* root) {
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    int lvl = 0;

    while (q.size()) {
        auto node = q.front().first;
        int l = q.front().second;
        q.pop();

        if (lvl != l) {
            lvl = l;
            cout<<endl;
        }

        cout<<node->name<<" ";

        for (auto child : node->children) 
            q.push({child, l+1});
    }

    return;
}

string Solve(int op, string node_name, int uid) {
    auto node = mp[node_name];
    bool res = true;

    switch (op) {
        case 1:
            res = Lock(node, uid);
            break;
        case 2:
            res = UnLock(node, uid);
            break;
        case 3:
            res = Upgrade(node, uid);
            break;
    }

    return res ? "true" : "false";
}

int main() {
    /*
        1. N - number of nodes
        2. M - number of children
        3. Q - number of queries
        4. N lines: nodes of M-ary tree
        5. Q lines: queries (format -> Operation Type | Node name | UID)
        Note: Operation Type:
            i. 1 -> Lock
            ii. 2 -> Unlock
            iii. 3 -> Upgrade.
    */

    int n, m, q;
    cin>>n>>m>>q;

    //Construct Tree
    string node_name; cin>>node_name;
    TreeNode* new_node = new TreeNode(node_name);
    mp[node_name] = new_node;

    queue<TreeNode*> bfs; 
    bfs.push(new_node);

    int it = 1;
    while (bfs.size()) {
        auto node = bfs.front();
        bfs.pop();

        while (it < n && node->children.size() < m) {
            cin>>node_name;
            TreeNode* new_node = new TreeNode(node, node_name);
            mp[node_name] = new_node;
            node->children.push_back(new_node);
            bfs.push(new_node);
            it++;
        }
    }

    //PrintTree(mp["Asia"]);

    //Get Queries:
    while (q--) {
        int op;
        int uid;
        cin>>op>>node_name>>uid;

        cout<<Solve(op, node_name, uid)<<"\n";
    }

    return 0;
}

/*
Think for optimisations.
*/