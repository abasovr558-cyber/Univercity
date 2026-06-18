#include <iostream>
#include <queue>

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

bool isMirror(Node* left, Node* right) {
    if (!left && !right) return true;

    if (!left || !right || left->value != right->value) return false;
    return isMirror(left->left, right->right) && isMirror(left->right, right->left);
}

bool isAnagramTree(Node* root) {
    if (!root) return true;
    return isMirror(root->left, root->right);
}

Node* buildTree(int val) {
    if (!(val) || val < 0) {
        return nullptr;
    }

    Node* root = new Node(val);
    std::queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        std::cout << "Введите левого потомка для " << current->value << " (или -1): ";
        int leftVal;
        if (std::cin >> leftVal && leftVal != -1) {
            current->left = new Node(leftVal);
            q.push(current->left);
        }

        std::cout << "Введите правого потомка для " << current->value << " (или -1): ";
        int rightVal;
        if (std::cin >> rightVal && rightVal != -1) {
            current->right = new Node(rightVal);
            q.push(current->right);
        }
    }

    return root;
}

int main() {
    std::cout << "Введите значение корня: ";
    int val;
    std::cin >> val;
    Node* root = buildTree(val);
    std::cout << isAnagramTree(root);
    return 0;
}