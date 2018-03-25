/*
 * Complete the function below.
 */

struct Node {
    Node* left;
    Node* right;
    int value;
    Node(int value):value(value),left(nullptr),right(nullptr){}
};

Node *root;
int counter;

void insert(Node *root, int key) {
    counter++;

    if (key <= root->value) {
        if (!root->left) {
            root->left = new Node(key);
        }
        else {
            insert(root->left, key);
        }
    }
    else {
        if (!root->right) {
            root->right = new Node(key);
        }
        else {
            insert(root->right, key);
        }
    }
}

void createBST(vector<int> keys) {
    counter = 0;
    for(auto &key : keys) {
        if(root) {
            insert(root, key);
        } else {
            root = new Node(key);
        }
        cout << counter << endl;
    }
}
