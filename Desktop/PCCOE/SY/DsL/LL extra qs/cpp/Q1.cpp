/*Given the head of a linked list and a position k, rotate the list to the right by k places. If the original list is 1->2->3->4->5->6 and k=3, resultant list will be 4->5->6->1->2->3 */
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

class ll{
    Node *head;
    public:
        ll(){
            head = NULL;
        }
        
        int getlen(){
            int c = 0;
            Node *temp = head;
            while(temp != NULL){
                c++;
                temp = temp -> next;
            }
            return c;
        }
        
        void insert(int val){
            Node *nn = new Node;
            nn -> data = val;
            nn -> next = NULL;
            if(head == NULL){
                //list is empty
                head = nn;
            }
            else{
                //nodes hai
                Node *temp = head;
                while(temp-> next){
                    temp = temp -> next;
                }
                temp -> next = nn;
            }
            return;
        }
        
        void print(){
            Node *temp = head;
            while(temp){
                cout << temp -> data << " ";
                temp = temp -> next;
            }
            cout << endl;
            return;
        }
        
        int sumOfLastn(int n){
            if(head == NULL || n < 0)
                return 0;
            else{
                Node *slow = head;
                Node *fast = head;
                //take fast to the nth node
                for(int i = 0; i < n; i++){
                    if(fast == NULL)//n > no of nodes
                        return 0;
                    fast = fast -> next;
                }
                //now fat stands on nth node 
                //slow ko aage badhao
                //fast ko bhi till it reaches last node
                while(fast){
                    fast = fast -> next;
                    slow = slow -> next;
                }
                
                // is on nth node
                int sum = 0;
                while(slow){
                    sum += slow -> data;
                    slow = slow -> next;
                }
                return sum;
            }
            
        }
        
};
int main() {
    ll mylist;
    mylist.insert(1);
    mylist.insert(2);
    mylist.insert(3);
    mylist.insert(4);
    mylist.insert(5);
    mylist.insert(6);
    mylist.print();
    int ans = mylist.sumOfLastn(2);
    cout << ans;
    return 0;
}