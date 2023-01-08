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
    int numbers = 0;

    for (j = 0; j < ArraySize; j++) { //will check the values, then put it in j

    int j_min = j;
    int min;

        for (j = i+1; j < ArraySize; j++) { //will check the values, put it in j
            if (userArray[i] > userArray[j_min]) { //if j is bigger than i
                j_min = i;
                min = userArray[i];
                }
            }
        if (j_min > i) {
            condition = userArray[j];
            userArray[j] = userArray[j_min];
            userArray[j_min] = condition;
            numbers++;
        }
    }


    cout << "The is the sorted array in ascending order: ";
    for (int j = 0; j < ArraySize; j++) {
        cout << userArray[j] << " "; //will print out the given numbers in ascending order
    }

    cout << endl;
    cout << "The algorithm selected the maximum for the traverse of the array. " << endl;
    cout<< "It took " << numbers << " swaps to sort the array. " ;

    return 0;
    }
}
