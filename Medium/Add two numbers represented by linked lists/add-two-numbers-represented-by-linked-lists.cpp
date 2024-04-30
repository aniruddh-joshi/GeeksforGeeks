//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
    public:
    //Function to add two numbers represented by linked list.
    struct Node* reverse(struct Node* head)
    {
        struct Node* curr = head, *prev = NULL, *temp;
        while(curr)
        {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    struct Node* removeleadingzeroes(struct Node* head)
    {
        while(head != NULL)
        {
            if(head->data == 0)
            head = head->next;
            else
            return head;
        }
        return head;
    
    }
    struct Node* addTwoLists(struct Node* num1, struct Node* num2)
    {
        num1 = removeleadingzeroes(num1);
        num2 = removeleadingzeroes(num2);
      
        if(num1 == NULL && num2 == NULL)
        {
             struct Node* temp = new Node(0);
             return temp;
        }
        if(num1 == NULL)
        return num2;
        
        if(num2 == NULL)
        return num1;
        
        num1 = reverse(num1);
        num2 = reverse(num2);
        struct Node* p = num1, *q = num2, *head = NULL, *prev = NULL;
        
        int curr = 0;
        while(p || q || curr) {
            int nump = p!=NULL ? p->data: 0;
            int numq = q!=NULL ? q->data: 0;
            
            if(p!=NULL)
            p=p->next;
            
            if(q!=NULL)
            q = q->next;
            
            int num = nump + numq + curr;
            
             curr = num/10;
            
            struct Node* temp = new Node(num%10);
            if(head == NULL)
            {
                head = temp;
                temp->next = NULL;
                prev = head;
            }
            else{
                prev->next = temp;
                temp->next = NULL;
                prev = temp;
            }
        }
        head = reverse(head);
        return head;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* num1 = buildList(n);
        
        cin>>m;
        Node* num2 = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(num1,num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends