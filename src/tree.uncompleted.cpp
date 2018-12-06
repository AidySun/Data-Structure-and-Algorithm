#include <iostream>
#include <queue>

using namespace std;

/*
rm tree.out ; g++ -std=c++11 tree.cpp -o tree.out && ./tree.out
*/

class TreeNode {
public:
    int val;
    TreeNode *l;
    TreeNode *r;

    TreeNode(int v): val(v) {
    }
};

class Tree {
public:
    TreeNode *root;

    Tree() : root(NULL) {
    }

    void Insert(TreeNode* n) {
        cout << "insert " << n->val << endl;
        TreeNode *p = root;
        while(NULL != p) {
            if (p->val <= n->val) {
                if (NULL == p->r) {
                    p->r = n;
                    return;
                }
                p = p->r;
            } else { 
                if (n->val < p->val) {
                }
                p = p->l;
            }
        }
        p = n;
    }

    void PrintTree() {
        cout <<"a"<<endl;
        queue<TreeNode*> q;
        q.push(root);
        cout <<"b" << endl;

        int level = 0;
        while(!q.empty()) {
            level++;
            cout << "level = " << level << endl;
            size_t s = q.size();
            cout << s << endl;
            for (auto i = 0; i < s; i++) {
               cout << "cout" << endl;
               TreeNode *p = q.front();
               cout << "TreeNode *p = q.front();" << endl;
               if (NULL == p) { 
                cout << "NULL == l" << endl;
            }
               cout << "p = " << p->val << endl;
               cout << p->val << endl;
               if (NULL != p->l) q.push(p->l);
               if (NULL != p->r) q.push(p->r);
               cout << p->val << "    ";
               q.pop();
           }
           cout << endl;
       }
   }

};

int main() {
    cout <<"main$a;";
    int N = 11;
    int a[] = {1, 3, 5, 7, 9, 2, 4, 8, 6, 0, 10};

    Tree t;
    for (auto i : a) {
        cout << i << "   ";
        TreeNode *n = new TreeNode(i);
        t.Insert(n);
    }
    cout << "done\n";
    t.PrintTree();
}
