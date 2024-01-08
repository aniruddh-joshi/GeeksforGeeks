//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}


Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}


// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
};

*/
class Solution 
{ 
    public: 
    struct Node* reverse(struct Node* head) { 
        struct Node* curr = head; 
        struct Node* prev = NULL; 
        struct Node* next = NULL; 
         
        while(curr != NULL) { 
            next = curr -> next; 
            curr -> next = prev; 
            prev = curr; 
            curr = next; 
        } 
         
        return prev; 
    } 
    struct Node* merge(Node* l1, Node* l2) { 
        if(l1 == NULL) 
            return l2; 
        if(l2 == NULL) 
            return l1; 
         
        Node* temp = NULL; 
        if(l1 -> data < l2 -> data) { 
            temp = l1; 
            temp -> next = merge(l1 -> next, l2); 
        } 
        else { 
            temp = l2; 
            temp -> next = merge(l1, l2 -> next); 
        } 
         
        return temp; 
    } 
    struct Node * mergeResult(Node *node1,Node *node2) 
    { 
        node1 = merge(node1, node2); 
        node1 = reverse(node1); 
        return node1; 
    }   
};



//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }
        
        Solution ob;
        struct Node* result = ob.mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}

// } Driver Code Ends