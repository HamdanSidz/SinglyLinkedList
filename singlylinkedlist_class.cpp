#include <iostream>
using namespace std;

class node{
    private:
        static int count;
        int data;
        node* ptr_next;
        node *head;          // bahi yhn pe pointer node nami(type)
                                // ko save krega isliya yhn pr node type rakhi h...
        
    public:
        node(){
            ptr_next = NULL;
            count = count+1;
        }
        
        node(int data,node *node_addr){
            head = node_addr;
            this->data = data;
            node_addr->ptr_next = NULL;

        }

        void preappend(int data){
            node *n = new node();
            node *temp = head;
            head =  n;
            n->ptr_next = temp;
            n->data = data;
            
        }
        
        void append(int data){
            node *n = new node();
            node* temp = head;
            while(temp->ptr_next != NULL){
                temp = temp->ptr_next;
            }
            temp->ptr_next = n;
            n->data = data;
            n->ptr_next = NULL;

        }

        void atyourdesire(int data){
            int a;
            node *temp = head;

            cout<<"Enter number to whom after you want to insert number...";
            cin>> a;

            while(temp->data != a ){
                temp = temp->ptr_next;
            } 
            node *n = new node();
            n->data=data;
            node *temp2;
            temp2 = temp->ptr_next;
            temp->ptr_next = n;
            n->ptr_next = temp2;

        }

        void display(){
            node *temp = head;
            while(temp != NULL){            // y akhir tk gaya h..
                cout<<temp->data<<"->";         
                temp = temp->ptr_next;
            }
            cout<<"NULL"<<endl;
        }

        static void nodescount(){
            cout<<"no.of nodes: "<<count<<endl;
        }

};

int node::count=count+1;

int main(){

node n1(5,&n1);
n1.preappend(6);
n1.append(19);
n1.append(30);
n1.preappend(0);
n1.preappend(-1);
n1.append(29);
n1.atyourdesire(77);
n1.display();
n1.nodescount();
}