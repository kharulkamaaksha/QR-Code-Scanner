/* Given a sorted doubly linked list of distinct positive numbers, determine pairs in a doubly-linked list whose sum equals the provided value ‘val’ without consuming any extra space. */
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *prev;
    Node *next;
};

class DLL{
    Node *head = NULL;
    public:
        void insertAtEnd(int val){
		    Node *nn = new Node;
		    nn -> data = val;
		    nn -> prev = NULL;
		    nn -> next = NULL;
		    if(head == NULL){
			   head = nn;
		    }
		    else{
		        Node *temp = head;
			    while(temp -> next)
			        temp = temp -> next;
			    //last node pe aa gaye
			    temp -> next = nn;
			    nn -> prev = temp;
		    }
		    return;
        }
    
        void print(){
            Node *temp = head;
            while(temp){
                cout << temp -> data << "\t";
                temp = temp -> next;
            }
            cout << endl;
        }
    
    void pairToVal(int val){
        Node *low = head;
        Node *high = head;
        while(high -> next)
            high = high -> next;
        int extreme = high -> data + high -> prev -> data;
        int min = low -> data + low -> next -> data;
        if (val > extreme || val < min)
            return ;
        else if (val == extreme){
            cout << high -> data << " , " << high -> prev -> data << endl;
            return ;
        }
        else if (val == min){
            cout << low -> data << " , " << low -> next -> data << endl;
            return ;
        }
        else{
            //now check
            while(low && high && low != high && low -> prev != high){
                int sum = low -> data + high -> data;
                if (sum > val)
                    high = high -> prev;
                else if(sum < val)
                    low = low -> next;
                else{
                    //its equal
                    cout << low -> data << " , " << high -> data << endl;
                    return;
                }
            }
        }
        //not returned means mila nahi
        cout << val << " is not present as a sum" << endl;
        return;
    }
};
int main() {
    DLL mylist;
    mylist.insertAtEnd(10);
    mylist.insertAtEnd(21);
    mylist.insertAtEnd(32);
    mylist.insertAtEnd(44);
    mylist.insertAtEnd(50);
    mylist.insertAtEnd(55);
    mylist.insertAtEnd(60);
    mylist.insertAtEnd(79);
    mylist.print();
    mylist.pairToVal(94);
    return 0;
}