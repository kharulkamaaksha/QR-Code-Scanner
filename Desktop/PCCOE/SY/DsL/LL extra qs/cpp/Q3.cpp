#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    
};

class cll{
    Node *tail;

public:
    cll(){
        tail = NULL;
    }

    void insert(int val){
        Node *nn = new Node;
        nn->data = val;
        //empty list
        if (tail == NULL){
            tail = nn;
            nn->next = nn;
        } 
        else{
            nn->next = tail->next;  
            tail->next = nn;      
            tail = nn;            
        }
    }

    void printRecords(){
        if (tail == NULL){
            cout << "List is empty!" << endl;
            return;
        }
        Node *temp = tail->next;
        do {
            cout << temp->data << "\t";
            temp = temp->next;
        } while (temp != tail->next);
        cout << endl;
    }

    void deleteOddNodes() {
        if (tail == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        Node *current = tail->next;
        Node *prev = tail;
        int position = 1;

        //single node
        if (tail->next == tail){
            delete tail;
            tail = NULL;
            return;
        }
        while (current->next != tail->next){ 
            if (position % 2 == 1){  
                prev->next = current->next;
                Node *temp = current;
                current = current->next;
                delete temp;
            } 
            else{
                prev = current;  
                current = current->next; 
            }
            position++;
        }
        
        //Odd positioned last node
        if (position % 2 == 1 && current == tail){
            prev->next = current->next;
            tail = prev; 
            delete current;
        }
    }
};

int main() {
    cll list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);

    cout << "Original List: " << endl;
    list.printRecords();

    list.deleteOddNodes();
    
    cout << "List after deleting odd positioned nodes: " << endl;
    list.printRecords();

    return 0;
}
