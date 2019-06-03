/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return nullptr;
        Node *root = head;
        while (head) {
            if (head->child) {
                head->child->prev = nullptr;
                if (head->next)
                    head->next->prev = nullptr;
                Node *tmp_1 = flatten(head->child);
                Node *tmp_2 = flatten(head->next);
                Node *t = tmp_1;
                while (t) {
                    if (!t->next) {
                        t->next = tmp_2;
                        if (tmp_2)
                            tmp_2->prev = t;
                        break;
                    }
                    t = t->next;
                }
                head->next = tmp_1;
                tmp_1->prev = head;
                head->child = nullptr;
                break;
            } 
            head = head->next;
        }
        return root;
    }
};