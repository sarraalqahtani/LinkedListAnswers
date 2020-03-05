#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Node.h"
using namespace std;

int main() {
    Node* head= new Node();
    Node* current= head;
    int x;
    cout<<"enter a list of integers and -1 to stop"<<endl;
    cin>>x;
    //populate the linked list with at least 7 nodes
    while(x!=-1){
       Node* n= new Node(x);
       current->InsertAfter(n);
       current=n; //current=current->getNext;
       cin>>x;

    }


    //1) find the node that has the minimum value
    current=head->getNext();
    int min=current->getValue();
    while(current!= nullptr){
        if(current->getValue()<min) {
            min = current->getValue();
        }
        current=current->getNext();
    }

    cout<<min<<endl;

    //2) remove the 4th node from the list
    current=head->getNext();
    Node* prev=head;
    int counter=0;
    while(current!=nullptr)
    {
        if(counter==3){
            prev->setNext(current->getNext());
            current->setNext(nullptr);
            delete current;
            break;
        }
        counter++;
        prev=current;
        current=current->getNext();
    }


    //3) remove the last node
    current=head->getNext();
    prev=head;
    while(current!=nullptr)
    {
        if(current->getNext()== nullptr){
            prev->setNext(nullptr);
            delete current;
            break;

        }
        prev=current;
        current=current->getNext();
    }

    //4) remove the first node
      current=head->getNext();
      head->setNext(nullptr);
      delete head;
      head=current;



    //6) delete all nodes
    current=head;
    while(current!=nullptr)
    {
        current=current->getNext();
        head->setNext(nullptr);
        delete head;
        head=current;
    }
    //print the nodes of the linked list
    if(head!= nullptr) {
        current = head->getNext();
        while (current != nullptr) {
            current->printNode();
            current = current->getNext();
        }
    }
}