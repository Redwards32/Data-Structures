#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;


int CheckArraySort(string* A, int lineSize);

int main()
{
    string line;
    int lineSize = 0;
    int check;


    ifstream fileInput;
    fileInput.open("CheckArray_in");


    while (!fileInput.eof()){ //counting the unknown amount of words in the file line by line
        getline(fileInput,line);
        lineSize = lineSize + 1;
    }
    cout << "The size of the array is: " << lineSize - 1 << endl;
    string *A = new string[lineSize];
    fileInput.close();     //Close the file to start over
    
    
    fileInput.open("CheckArray_in");
    
    for(int i = 0; i < lineSize; i++){
        getline(fileInput, line);
        A[i] = line;
    }
    
    check = CheckArraySort(A, lineSize);
    
    if(check == -1){
        cout << "The array is sorted in descending order!" << endl;
    }
    if(check == 0){
        cout << "The array is not sorted!" << endl;
    }
    if(check == 1){
        cout << "The arary is sorted in ascending order" << endl;
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

