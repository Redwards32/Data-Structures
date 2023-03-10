
#include "LinkedList_char.h"
#include<iostream>

using namespace std;

LinkedList_char::LinkedList_char()
{
    first = NULL;      //first and last are initalized
    last = NULL;
}

LinkedList_char::~LinkedList_char()
{
    clear();           //destructor is here to get rid of extra stuff after all the node is check
}

void LinkedList_char::insertAtBack (char initialValue) //adding node at the back
{
        Node*temp = new Node();
        temp -> val= initialValue;               // temp points to value

        if (first == nullptr)
        {
                first = temp;                    //Check is first and last have nothing in the node
        }
        if (last == nullptr)
        {
                last = temp;
        }
        else {
                last -> next = temp;    //If first and last is not null, then last point to next = temp so last can be temp, which adds a node at the back
                last = temp;
        }
}

bool LinkedList_char::removeFromBack()
{
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
                delete last;           //After the while loop exit, the last node delete so the temp node is the new last node
                last = temp;
                return true;
}

void LinkedList_char::print ()
{
    if (first != nullptr){
        Node* temp = first;
        while(temp != last){
            cout<<temp -> val << ",";     //spacing the values evenly
            temp = temp -> next;
        }
    cout<<temp -> val;
    }
    else cout<<" ";
}

bool LinkedList_char::isEmpty()
{
        if (first == nullptr ) {            //If the node is empty, then return true or false
            return true;
        } else
            return false;
}

int LinkedList_char::size()
{
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

void LinkedList_char::clear()        //Once again delete the list if the list is not empty
{
        while(!isEmpty()){
            removeFromBack();
        }
}

void LinkedList_char::insertAtFront(char initialValue)  //works the same way as insertAtBack
{                                                        //exercise 2
    Node*temp = new Node();
    temp -> val = initialValue;
    if (first == NULL){
        first = temp;
    }
    if (last == NULL){
        last = temp;
    }
    else{
        temp -> next = first;
        first = temp;
    }
}

bool LinkedList_char::removeFromFront()   //works the same way as removeFromBack
{                                          //exercise2
    Node*temp = first;
    if (first == NULL){
        return false;
    }
    if (first == last){
        delete first;
        first = NULL;
        last = NULL;
        return true;
    }
        temp = temp -> next;
        delete first;
        first = temp;
        return true;
}
