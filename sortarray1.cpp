#include <iostream>
using namespace std;
int main()
{
    int ArraySize;

    cout << "Enter the size of the array: ";
    cin >> ArraySize;

    if (ArraySize == 0) { //will check if the user enter a valid number
        cout << "ERROR: you entered an incorrect value for the array size! ";
    } else {
        int userArray[ArraySize]; //will declare the array
        cout << "Enter the numbers in the array, separated by a space and press enter: ";
            for (int i = 0; i < ArraySize; i++) { //will read the given values
                cin >> userArray[i];
    }

    int i = 0;
    int j = 0;
    int condition;

    for (i = 0; i < ArraySize; i++) {

        for (j = 0; j < ArraySize; j++) {
            if (userArray[i] > userArray[j]) {
                condition = userArray[j];
                userArray[j] = userArray[i];
                userArray[i] = condition;
                }
            }
        }


    cout << "The is the sorted array in descending order: ";
    for (int i = 0; i < ArraySize; i++) {
        cout << userArray[i] << " "; //will print out the given numbers in descending order
    }

    cout << endl;
    cout << "The algorithm selected the minimum for the traverse of the array. ";

    return 0;
    }
}
