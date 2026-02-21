    #include <iostream>
    #include <algorithm>
     
    using namespace std;
     
    struct Node {
        int key;
        int height;
     
        Node* left;
        Node* right;
     
        Node() {}
        Node(int key) {
            this->key = key; 
            this->height = 0;
            left = nullptr;
            right = nullptr;
        }
    };
     
    class Avl {
        private:
            Node* root;
            int nodeCount;
     
            void destroyTree(Node* root) {
                if(root) {
                    destroyTree(root->left);
                    destroyTree(root->right);
                    delete root;
                }
            }
     
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
     
            Node* leftRotate(Node* root) {
               Node* right = root->right;
               Node* rightLeft = right->left;
     
               right->left = root;
               root->right = rightLeft;
     
               root->height = 1 + max(getHeight(root->left), getHeight(root->right));
               right->height = 1 + max(getHeight(right->left), getHeight(right->right));
              
               return right;
              
           }
           Node* rightRotate(Node* root) {
               Node* left = root->left;
               Node* leftRight = left->right;
              
               left->right = root;
               root->left = leftRight;
              
               root->height = 1 + max(getHeight(root->left), getHeight(root->right));
               left->height = 1 + max(getHeight(left->left), getHeight(left->right));
              
               return left;
           }
     
        public:
     
            Avl() {
                root = nullptr;
                nodeCount = 0;
            }
            ~Avl() {
                destroyTree(root);
            }
     
            void insert(int key) {
                cout << "insert " << key << ": ";
     
                bool rotation = false;
                root = insertHelp(root, key, rotation);
                nodeCount++;
     
                if(!rotation) {
                    cout << "no rotation!\n";
                }
            }
     
            Node* insertHelp(Node* root, int key, bool& rotation) {
                if(!root) {
                    return new Node(key);
                }
                else if(key < root->key) {
                    root->left = insertHelp(root->left, key, rotation);
                }
                else {
                    root->right = insertHelp(root->right, key, rotation);
                }
     
                root->height = 1 + max(getHeight(root->left), getHeight(root->right));
                int balance = getBalance(root);
     
                if(balance < -1 && key >= root->right->key) {
                    cout << root->key << " is unbalanced, L-rotation!\n";
                    rotation = true;
                    return leftRotate(root);
                }
                if(balance > 1 && key < root->left->key) {
                    cout << root->key << " is unbalanced, R-rotation!\n";
                    rotation = true;
                    return rightRotate(root);
                }
                if(balance < -1 && key < root->right->key) {
                    cout << root->key << " is unbalanced, RL-rotation!\n";
                    rotation = true;
                    
                    root->right = rightRotate(root->right);
                    return leftRotate(root);
                }
                if(balance > 1 && key >= root->left->key) {
                    cout << root->key << " is unbalanced, LR-rotation!\n";
                    rotation = true;
     
                    root->left = leftRotate(root->left);
                    return rightRotate(root);
                }
     
                return root;
            }
     
            void inOrder() {
                inOrderHelp(root);
            }
            void inOrderHelp(Node* root) {
                if(root) {
                    inOrderHelp(root->left);
                    cout << ' ' << root->key;
                    inOrderHelp(root->right);
                }               
            }
     
            void posOrder() {
                posOrderHelp(root);;
            }
            void posOrderHelp(Node* root) {
                if(root) {
                    posOrderHelp(root->left);
                    posOrderHelp(root->right);
                    cout << ' ' << root->key;
                }
            }
     
            void preOrder() {
                preOrderHelp(root);
            }
            void preOrderHelp(Node* root) {
                if(root) {
                    cout << ' ' << root->key;
                    preOrderHelp(root->left);
                    preOrderHelp(root->right);
                }
            }  
    };
     
    int main() {
        Avl avlTree;
        
        int numOfInputs;
        cin >> numOfInputs;
     
        int input;
        for(int i = 0; i < numOfInputs; i++) {
            cin >> input;
            avlTree.insert(input);
        }
        cout << "preorder:";
        avlTree.preOrder();
        cout << '\n';
     
        cout << "inorder:";
        avlTree.inOrder();
        cout << '\n';
     
        cout << "postorder:";
        avlTree.posOrder();
        cout << '\n';
        
        return 0;
    }
