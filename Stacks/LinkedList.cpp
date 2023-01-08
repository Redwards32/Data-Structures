#include "LinkedList.h"
#include<iostream>

using namespace std;

LinkedList::LinkedList() {
    first = nullptr;      //first and last are initalized
    last = nullptr;
}

LinkedList::~LinkedList() {       //destructor
}

void LinkedList::insertAtBack (int initialValue) { //insert node at the end of list
        Node*temp = new Node();
        temp -> val= initialValue;               // temp points to value

        if (first == nullptr) {
                first = temp;        //Check if first and last have nothing in the node
        }
        if (last == nullptr) {
                last = temp;
        } else {
                last -> next = temp;    //If first and last is not null, then last point to next = temp so last can be temp, which adds a node at the back
                last = temp;
        }
}

bool LinkedList::removeFromBack() { //Removes the last element of list
        Node*temp = first;
        if(last == nullptr){
                return false;
        }
        if(first==last){
                delete first;    //since first is equal to last it does matter if its delete first or delete last
                first = nullptr;
                last = nullptr;
                return true;
        }
        while(temp -> next != last){
                temp = temp -> next;   //check until next = last
        }
                delete last;           //After the while loop exit, the last node delete so the temp node is the new last node``
                last = temp;
                return true;
}

void LinkedList::print () {
    if (first != nullptr) {
        Node* temp = first;
        while(temp != last){
            cout<<temp -> val << ",";     //spacing the values evenly
            temp = temp -> next;
        }
    cout << temp -> val;
    } else cout<<" ";
}

bool LinkedList::isEmpty() {
        if (first == nullptr ) {    //Will check if the node is empty, then return true or false
            return true;
        } else
            return false;
}

int LinkedList::size() {
        Node *temp;
        int counter = 1;
        if(first == nullptr && last == nullptr){
            return 0;
        }
        else {
            temp = first;
        while (temp != last){        //if temp is not last, then it will go down the list to count how long it is
            temp = temp -> next;
            counter++;                //counter add by 1
        }
    }
    return counter;
}

void LinkedList::clear() {        //Delete the list if the list is not empty
        while(!isEmpty()){
            removeFromBack();
        }
}

void LinkedList::insertAtFront(int initialValue) {  //works the same way as insertAtB

//exercise 2
    Node*temp = new Node();
    temp -> val = initialValue;
    if (first == nullptr){ // can set first and last on the same line
        first = temp;
    }
    if (last == nullptr){
        last = temp;
    }
    else{
        temp -> next = first;
        first = temp;
    }
}

bool LinkedList::removeFromFront() {   //works the same way as removeFromBack
//exercise2
    Node*temp = first;
    if (first == nullptr) {
        return false;
    }
    if (first == last) {
        delete first;
        first = nullptr;
        last = nullptr;
        return true;
    }
        temp = temp -> next;
        delete first;
        first = temp;
        return true;
}
