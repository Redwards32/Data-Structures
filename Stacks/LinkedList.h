#ifndef LinkedList_h
#define LinkedList_h
// Representation of an element in the linked list
struct Node
{
    int val; // Value of the node
    Node *next; // Pointer to the next node
};
class LinkedList
{
    // Public Functions/Variables
    public:
        LinkedList(); // Constructor
        ~LinkedList(); // Destructor
        void insertAtBack(int valueToInsert);
        bool removeFromBack();
        void print();
        bool isEmpty();
        int size();
        void clear();
        /* IMPLEMENT THSES FUNCTIONS FOR EXERCISE2 */
        void insertAtFront(int valueToInsert);
        bool removeFromFront();
    protected:
        Node *first; // Pointer pointing to the begining of the list
        Node *last; // Pointer pointing to the end of the list
};
#endif
