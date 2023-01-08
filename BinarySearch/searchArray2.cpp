#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;


int CheckArraySort(string* A, int lineSize);
int BinarySearch(string* A, string key, int lineSize);


int main()
{
    string line;
    int lineSize = 0;
    int check;
    int binary;
    string key;


    ifstream fileInput;
    fileInput.open("words_in");


    while (!fileInput.eof()){ //counting the unknown amount of words in the file line by line
        getline(fileInput,line);
        lineSize = lineSize + 1;
    }
    cout << "The size of the array is: " << lineSize - 1 << endl;
    string *A = new string[lineSize];
    fileInput.close();     //Close the file to start over
    
    
    fileInput.open("words_in");
    
    for(int i = 0; i < lineSize; i++){
        getline(fileInput, line);
        A[i] = line;
    }
    
    check = CheckArraySort(A, lineSize);
    binary = BinarySearch(A, key, lineSize);
    
    if(check == -1){
        cout << "The array is sorted in descending order!" << endl;
        cout << "Enter the desired key: ";
        cin >> key;
        if (binary > 0){
            cout << "Found the key: " << key << " at index " << BinarySearch(A, key, lineSize) << "!" << endl;
        return 0;
        }else
            cout << "Could not find the desired key in the array array!" << endl;
            return 0;
    }
    if(check == 0){
        cout << "The array is not sorted!" << endl;
    }
    if(check == 1){
        cout << "The arary is sorted in ascending order" << endl;
        cout << "Enter the desired key: ";
        cin >> key;
        if (binary == -1){
            cout << "Could not find the desired key in the array!" << endl;
            return 0;
        }else
            cout << "Found the key: " << key << " at index " << BinarySearch(A, key, lineSize) << "!" << endl;
        return 0;
    }
    delete[] A;
}

int CheckArraySort(string* A, int lineSize){
    
    int ascending = 0;
    int descending = 0;
    
    
    for(int i = 0; i < lineSize - 2; i++){
        if(A[i] < A[i+1]){
            ascending = 1;
            }
        }
    for(int i = 0; i < lineSize - 2; i++){
        if(A[i] > A[i+1]){
            descending = 1;
            }
        }
    if (ascending == 1 && descending == 1){
        return 0;
    }
    if (ascending == 0 && descending == 1){
        return -1;
    }
    if (ascending == 1 && descending == 0){
        return 1;
    }
    return 2;
}

int BinarySearch(string* A, string key, int lineSize) {
    int first = 0;
    int last = lineSize-2;

    while (first <= last) {
        int middle = (first + last)/2;
        if (A[middle] < key) { // if middle is less than value
            first = middle + 1;
        }
        if (A[middle] > key) { // if middle is greater than value
            //look to the left
            last = middle - 1;
        }
        if (A[middle] == key) {
            return middle;
        }
    }
    return -1;
}
