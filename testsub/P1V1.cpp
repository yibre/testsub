//HW03 Prob1
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// store int value and keep a reference to each child
class Node
{
private:
    vector<int> keys;
    // �ش� ����� Ű�� ����
    vector<Node*> children;
    // �ش� ����� child ���� ����
    Node *par{ nullptr };

public:
    Node()
    {
        for (int i = 0; i < 4; ++i)
            children.push_back(nullptr);
    }
    int getNum() { return keys.size(); }
    friend class TFTree;
};

class TFTree
{
private:

public:
    bool isEmpty();

};

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
https://www.baeldung.com/java-binary-tree <- ���̳ʸ� Ʈ�� java

*/