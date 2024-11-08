//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}




// } Driver Code Ends
//User function Template for C++

/*Link list node
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/
class Solution {
    public:
    void backsorter(struct Node* & head) {
        if(head==NULL)return;
        backsorter(head->next);
        Node * curr=head;
        Node * Next=head->next;
        int key=curr->data;
        while(Next!=NULL) {
            if(Next->data <key) {
                curr->data=Next->data;
                curr=Next;
                Next=Next->next;
            }
            else {
                break;
            }
        }
        curr->data=key;
    }
    Node* insertionSort(struct Node* head) {
        if(head==NULL || head->next==NULL)  return head;
        backsorter(head);
        return head;
    }
};

//{ Driver Code Starts.
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int n;
		cin >> n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < n; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

        Solution ob;

		head = ob.insertionSort(head);
		printList(head);

		cout << "\n";



	}
	return 0;
}
// } Driver Code Ends