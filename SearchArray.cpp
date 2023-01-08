#include <iostream>
using namespace std;
int main()
{
    int ArraySize = 0;
    int NumberSearch = 0;


    cout << "Enter the size of the array: ";
    cin >> ArraySize;

    if(ArraySize <= 0) {
        cout << "ERROR: you entered an incorrrect value for the array size!" << endl;
    } else {
        int userArray[ArraySize];
        cout << "Enter the numbers in the array, separated by a space, and press enter: ";
            for (int i = 0; i < ArraySize; i++) {
                cin >> userArray[i];
            }

    cout << "Enter a number to search for in the array: ";
    cin >> NumberSearch;
    bool notFound = false; //will check if the value is not given

    for (int i = 0; i < ArraySize; i++) { //will look for the user's want value

        if (NumberSearch == userArray[i]) {
            notFound = true;
            cout << "Found value " << NumberSearch << " at index " << i << ", which took " << (i+1)  << " checks. " << endl;
        if (NumberSearch == 1) {
            cout << "We ran into the best case scenario! " << endl;

        return 0;
    }

    if (NumberSearch == ArraySize) { //if the user's want value will take too long to find
        cout << "We ran into the worst case scenario! " << endl;

        return 0;
            }
        }
    }

    if(!notFound) { //if the user's want value is not on the array
        cout << "The value v was not found in the array! ";
    }

        return 0;
    }
}
