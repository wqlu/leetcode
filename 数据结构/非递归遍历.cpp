#include <bits/stdc++.h>
using namespace std;


struct Node {
    Node(const Node *t) : data(t->data), lChild(NULL), rChild(NULL) {}
    Node(int d) : data(d), lChild(NULL), rChild(NULL) {}
    struct Node *lChild;
    struct Node *rChild;
    int data;
};

// 前序遍历--DFS
void PreOrderTraverse(Node *root, void (*visit) (Node*)) {
    if (root == NULL) return;
    stack<Node *> s;
    Node *cur;
    s.push(root);
    while (!s.empty()) {
        cur = s.top();
        visit(cur);
        s.pop();
        if (cur->rChild != NULL)
            s.push(cur->rChild);
        if (cur->lChild != NULL)
            s.push(cur->lChild);
    }
}

// 中序遍历
void InOrderTraverse(Node *root, void (*visit) (Node *)) {
    stack<Node *> s;
    Node *cur = root;
    while (!s.empty() || cur != NULL) {
        while (cur != NULL) {
            s.push(cur);
            cur = cur->lChild;
        }
        cur = s.top();
        visit(cur);
        s.pop();
        if (cur->rChild == NULL)
            cur = NULL;
        else
            cur = cur->rChild;
    }
}

// 后序遍历
void PostOrderTraverse(Node *root, void (*visit) (Node *)) {
    stack<Node *> s;
    Node *cur = root;
    Node *visited = NULL;
    while (!s.empty() || cur != NULL) {
        while (cur != NULL) {
            s.push(cur);
            cur = cur->lChild;
        }
        cur = s.top(); // check but not visit.
        // 只有在右子节点访问过或者为NULL,才能visit curr
        if (cur->rChild == visited || cur->rChild == NULL) {
            visit(cur);
            s.pop();
            visited = cur;
            cur = NULL; // not current node, must pop.
        } else {
            cur = cur->rChild;
        }

    }
}

// 层次遍历
void LevelOrderTraverse(Node *t, void (*visit) (Node *)) {
    if (t == NULL) return;
    queue<Node *> q;
    Node *e;
    q.push(t);
    while (!q.empty()) {
        visit(e = q.front());
        q.pop();
        if (e->lChild != NULL)
            q.push(e->lChild);
        if (e->rChild != NULL)
            q.push(e->rChild);
    }
}

void insert(Node *&root, Node *t) {
    if (root == NULL)
        root = new Node(t);
    else if (t->data > root->data)
        insert(root->rChild, t);
    else if (t->data < root->data)
        insert(root->lChild, t);
    else
        ;
}

// 使用数组创建二叉树
Node* createTree(vector<int> &a) {
    if (a.size() == 0) return NULL;
    Node *root = new Node(a[0]);
    vector<int>::iterator iter = a.begin();
    iter++;
    for (; iter != a.end(); ++iter) {
        Node *t = new Node(*iter);
        insert(root, t);
    }
    return root;
}

void visit(Node *t) {
    cout << setw(3) << t->data << " ";
}

int main() {
    vector<int> a;
    for (int i = 0; i < 10; ++i) {
        int temp = rand() % 31;
        a.push_back(temp);
    }

    Node *root = createTree(a);

    cout << "LevelOrderTraverse: ";
    LevelOrderTraverse(root, visit);
    cout << endl;
    cout << "PreOrderTraverse: ";
    PreOrderTraverse(root, visit);
    cout << endl;
    cout << "InOrderTraverse: ";
    InOrderTraverse(root, visit);
    cout << endl;
    cout << "PostOrderTraverse: ";
    PostOrderTraverse(root, visit);
    cout << endl;
    return 0;
}
