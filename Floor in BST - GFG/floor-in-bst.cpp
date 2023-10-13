//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};


// } Driver Code Ends
// Function to search a node in BST.
class Solution{

public:
    void traverse(Node* root, std::vector<int>& temp) {
    if (root == nullptr) return;
    traverse(root->left, temp);
    temp.push_back(root->data);
    traverse(root->right, temp);
}

int floor(Node* root, int x) {
    vector<int> temp;
    traverse(root, temp);
    int k = -1;  
    for (int i = 0; i < temp.size(); i++) {
        if (temp[i] == x) {
            k = temp[i]; 
            break;
        } else if (temp[i] < x) {
            k = temp[i]; 
        }
    }
    return k;
}
};

//{ Driver Code Starts.

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int s;
        cin >> s;
        Solution obj;
        cout << obj.floor(root, s) << "\n";
    }
}

// } Driver Code Ends