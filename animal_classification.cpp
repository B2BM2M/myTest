#include <iostream>
using namespace std;

// preorder (data, left, right)
// inorder (left, data, right)
// postorder (left, right, data)

struct Node{
    string data;
    Node* left;
    Node* right;
};

Node* createNode(string idata){
    Node* newNode = new Node();
    newNode->data = idata;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

void printClassification(Node* root, int level){
    if (root == nullptr) return;
    else if( level == 0)
    {
        cout << root->data << " " << endl;
    }
    else // level > 0
    {   printClassification(root->left, level - 1);
        printClassification(root->right, level -1);
    }
}

int height(Node* root){
    if (root == NULL)
        return -1;
    else{
        // compute the height of each subtree
        int lheight = height(root->left);
        int rheight = height (root->right);

        // pick the larger one
        if (lheight > rheight)
            return (lheight + 1);
        else return (rheight + 1);
    }
}

void printLevelORderBFS(Node* root)
{
    int h = height(root);
    for(int i = 0; i <= h; i++)
        printClassification(root, i);
}

int main()
{
    // L1 tree (root)
    Node* root = createNode("animal");
    // Level 2 tree
    root->left = createNode("reptile");
    root->right = createNode("mammal");
    // Level 3 - all under reptile
    root->left->left = createNode("iguana");
    root->left->right = createNode("turtle");
    root->left->right = createNode("crocodile");
    // Level 3 - all under mammal
    root->right->left = createNode("feline");
    root->right->right = createNode("canine");
    root->right->right = createNode("monotreme");
    // Level 4 - all under feline
    root->right->left->left = createNode("jaguar");
    root->right->left->right = createNode("lion");
    root->right->left->right = createNode("cat");
    // Level 4 - all under canine
    root->right->right->left = createNode("dog");
    root->right->right->right = createNode("wolf");
    // Level 5 - all under cat
    root->right->left->right->left = createNode("persian");
    // Level 5 - all under dog
    root->right->right->left->left = createNode("poodle");
    root->right->right->left->right = createNode("pomeranian");
    root->right->right->left->right = createNode("st bernard");

    //printClassification(root->left);
    printClassification(root, 2);

}