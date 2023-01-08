#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;


int CheckArraySort(string* A, int lineSize);
int BinarySearch(string* A, string key, int last, int first);


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
    
    if(check == -1){
        cout << "The array is sorted in descending order!" << endl;
        cout << "Enter the desired key: ";
        cin >> key;
        binary = BinarySearch(A, key, lineSize, 0);
        if (binary > 0){
            cout << "Found the key: " << key << " at index " << binary << "!" << endl;
        return 0;
        }else
            cout << "Could not find the desired key in the array array!" << endl;
            return 0;
    }
    if(check == 0){
        cout << "The array is not sorted!" << endl;
    }
    if(check == 1){
        cout << "The array is sorted in ascending order" << endl;
        cout << "Enter the desired key: ";
        cin >> key;
        binary = BinarySearch(A, key, lineSize, 0);
        if (binary == -1){
            cout << "Could not find the desired key in the array!" << endl;
            return 0;
        }else
            cout << "Found the key: " << key << " at index " << binary << "!" << endl;
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

int BinarySearch(string* A, string key, int last, int first)
{
    if (first <= last) {
        int mid = (first + (last - 1)) / 2;
  
        // If the element is present at the middle
        // itself
        if (A[mid] == key){
            return mid;
        }
  
        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (A[mid] < key){
            last = mid - 1;
            return BinarySearch(A, key, last, first);
        }
        else{
            first = mid + 1;
        return BinarySearch(A, key, last, first);
        }
    }
  
    // We reach here when element is not
    // present in array
    return -1;
}
