//HW03 Prob1
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// store int value and keep a reference to each child
class Node
{
private:
    // 부모 노드 저장
    vector<Node*> parent; 
    // 해당 노드의 키를 저장
    vector<int> keys;
    // 해당 노드의 child 노드들 저장
    vector<Node*> children;

public:
    Node()
    {
        parent.push_back(nullptr);
        for (int i = 0; i < 4; ++i)
        { children.push_back(nullptr); }
    }
    int getNum() { return keys.size(); }
    friend class TFTree;
};

class TFTree
{
private:
    Node * root;

public:
    TFTree() : root {nullptr} {}
    bool isEmpty() { return root == nullptr; }
    bool isRoot( Node * v) { return v == root; }
    void put(int k);
    void erase(int k);
    void insertKey(Node* v, int i, int k);
    void deleteKey(Node* v, int i);
    bool overflow(Node* v) { return v->getNum() == 4; }
    bool underflow(Node* v) { return v->getNum() == 0; }
    Node* split(Node* v);
    Node* fusion(Node* w, int w_i, int v_i);
    void transfer(Node* w, int w_i, int v_i);
    int keysTraverse(int k, Node* v);
    Node* inorderTraverse(int k, Node* n);
    Node* inorderSuccessor(int k, int i, Node* v);
    void showTree(int depth, Node* v = nullptr);
};

// 24 트리의 pos 노드부터 시작하여 k를 찾기 위해 inorder traverse를 하고
// k가 있으면 그 노드를 반환하고 그렇지 않은 경우에는 다음 방문 순서가
// leaf 노드일때 멈추어 현재 노드를 반환함
Node* TFTree::inorderTraverse(int k, Node* pos)
{
    for (int i = 0; i < pos->getNum(); ++i)
        if (k == pos->keys[i])
            return pos;
    if (k < pos->keys[0])
    {
        if (pos->children[0] == nullptr)
            return pos;
        return inorderTraverse(k, pos->children[0]);
    }
    else if (pos->getNum() > 1)
    {
        for (int i = 0; i < pos->getNum() - 1; ++i)
        {
            if (pos->keys[i] < k && k < pos->keys[i + 1])
            {
                if (pos->children[i + 1] == nullptr)
                    return pos;
                return inorderTraverse(k, pos->children[i + 1]);
            }
        }
    }
    if (pos->children[pos->getNum()] == nullptr)
        return pos;
    return inorderTraverse(k, pos->children[pos->getNum()]);
}

int TFTree::keysTraverse(int k, Node * v)
{

}

/* 5개 노드에 대해 3 2로 쪼개기 */
Node* TFTree::split(Node* v)
{

}

/*
Handling underflow: case1
an adjacent siblings of v are 2 nodes
*/
Node* TFTree::fusion(Node* w, int w_i, int v_i)
{
    Node * par = w->parent;
    if (v_i == 0)
    { }
}

/*
Handling underflow: case2
an adjacent sibling w of v is a 3 node or a 4 node
*/
void TFTree::transfer(Node *w, int w_i, int v_i)
{
    
}


/*
int main() {
    while (true) {
        string s;
        cin >> s;
        if (!s.compare("INSERT")) {
            int key;
            cin >> key;
            cout << key << endl;
        }
        else if (!s.compare("DELETE")) {
            int key;
            cin >> key;
            cout << key << endl;
        }
        else if (!s.compare("SHOWTREE")) {
            cout << "show" << endl;
        }
        else {
            return 0;
        }
    }
    return 0;
}
*/
/*
https://www.baeldung.com/java-binary-tree <- 바이너리 트리 java

*/