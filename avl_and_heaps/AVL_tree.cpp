#include <iostream>
using namespace std;

struct Node {
    int key;;
    int height;
    int size;
    
    Node* left;
    Node* right;

    Node(int key) {
        this->key = key; 
        height = 0;
        size = 1;

        left = nullptr;
        right = nullptr;
    }

    ~Node() {}
};

class Avl {
    private:
        Node* root;
        int nodeCount;

        int getBalance(Node* root) {
            if(!root) {
                return 0;
            }
            return (getHeight(root->left) - getHeight(root->right));
        }
        int getHeight(Node* root) {
            if(!root) {
                return -1;
            }
            return root->height;
        }
        int getSize(Node* root) {
            if(!root) {
                return 0;
            }
            return root->size;
        }

        Node* leftRotate(Node* root) {
            Node* right = root->right;
            Node* rightLeft = right->left;

            right->left = root;
            root->right = rightLeft;

            root->height = 1 + max(getHeight(root->left), getHeight(root->right));
            root->size = 1 + getSize(root->left) + getSize(root->right);
            
            right->height = 1 + max(getHeight(right->left), getHeight(right->right));
            right->size = 1 + getSize(right->left) + getSize(right->right);


            return right;
            
        }
        Node* rightRotate(Node* root) {
            Node* left = root->left;
            Node* leftRight = left->right;
            
            left->right = root;
            root->left = leftRight;
            
            root->height = 1 + max(getHeight(root->left), getHeight(root->right));
            root->size = 1 + getSize(root->left) + getSize(root->right);
            
            left->height = 1 + max(getHeight(left->left), getHeight(left->right));
            left->size = 1 + getSize(left->left) + getSize(left->right);

            return left;
        }
      

    public:
        Avl() {
            root = nullptr;
            nodeCount = 0;
        }

        int findIndex(int key) {
            int index = 0;
            return findIndexHelp(root, key, index);
        }
        int findIndexHelp(Node* root, int key, int& index) {
            if(root) {
                if(key == root->key) {
                    return index + (getSize(root->left) + 1);
                }
                else if(key < root->key) {
                    return findIndexHelp(root->left, key, index);
                }
                else {
                    index += getSize(root->left) + 1;
                    return findIndexHelp(root->right, key, index);
                }
            }
            return 0;
        }


        void insert(int key) {
            root = insertHelp(root, key);
            nodeCount++;
        }
        Node* insertHelp(Node* root, int key) {
            if(!root) {
                return new Node(key);
            }
            else if(key < root->key) {
                root->left = insertHelp(root->left, key);
            }
            else {
                root->right = insertHelp(root->right, key);
            }

            root->size = 1 + getSize(root->left) + getSize(root->right);
            root->height = 1 + max(getHeight(root->left), getHeight(root->right));
            int balance = getBalance(root);

            if(balance < -1 && key >= root->right->key) {
                return leftRotate(root);
            }
            if(balance > 1 && key < root->left->key) {
                return rightRotate(root);
            }
            if(balance < -1 && key < root->right->key) {
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }
            if(balance > 1 && key >= root->left->key) {
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }

            return root;
        }


};

int main() {
    Avl tree;

    int numOfOperations;
    cin >> numOfOperations;

    int operation;
    int key;
    int index;

    for(int i = 0; i < numOfOperations; i++) {
        cin >> operation;
        cin >> key;

        if(operation == 1) {
            tree.insert(key);
        }
        else if(operation == 2) {
            index = tree.findIndex(key);
            if(index) {
                cout << index << '\n';
            }
            else {
                cout << "Data tidak ada\n"; 
            }
        }
    }

    return 0;
}
