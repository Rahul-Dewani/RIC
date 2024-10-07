#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data; 
    vector<Node*> children; 
};


Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    return newNode;
}

void DFS(Node* root) {
    if (root == nullptr){
        return; 
    } 
    cout << root->data << " ";
    
    for (Node* child : root->children) {
        DFS(child);
    }
}


int main() {
    Node* root = createNode(50);
    root->children.push_back(createNode(39));
    root->children.push_back(createNode(28));
    root->children.push_back(createNode(11));

    root->children[0]->children.push_back(createNode(33));
    root->children[0]->children.push_back(createNode(43));

    cout << "DFS Traversal: ";
    DFS(root);

    return 0;
}
