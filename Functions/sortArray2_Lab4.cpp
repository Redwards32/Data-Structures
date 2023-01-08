#include<iostream>

void InsertionSort(int condition, int myArray[], int array_Size);

int main()
{
    int array_size;
    int values;
    int condition;


    std::cout<<"Enter the size of the array: ";
    std::cin>>array_size;

    if(array_size<=0){
    std::cout<<"\nERROR : you entered an incorrect value for the array size!!"<<std::endl;
    }else{
    int myArray[array_size];
        std::cout<< "Enter the numbers in the array, separated by a space, and press enter: " << std::endl;
        for(int i = 0; i < array_size; i++){
        std::cin>>values;
        myArray[i]=values;
    }
        std::cout<<"Sort in ascending (0) or descending (1) order: ";
        std::cin>>condition;
        
    InsertionSort(condition, myArray, array_size);
        return 0;
    }

}


void InsertionSort(int condition, int myArray[], int array_size){
    int placeholder;
    int j;
    
    if (condition == 0) {
        std::cout<<"This is the sorted array in ascending order: ";
        for (int i = 1; i < array_size - 1; i++) {
            placeholder = myArray[i];
            j = i;
           
            while (j > 0 && myArray[j - 1] > placeholder) {
                
                myArray[j] = myArray[j - 1];
                j--;
            }
            myArray[j] = placeholder;
        }
        for(j = 0; j < array_size; j++){
        std::cout << myArray[j] << " ";
        }
    
    }
    
    if (condition == 1) {
        std::cout<<"This is the sorted array in descending order: ";
        for (int i = 1; i < array_size; i++) {
            placeholder = myArray[i];
            j = i;
           
            while (j > 0 && myArray[j - 1] < placeholder) {
                
                myArray[j] = myArray[j - 1];
                j--;
            }
            myArray[j] = placeholder;
        }
        for(j = 0; j < array_size; j++){
        std::cout << myArray[j] << " ";
        }
    
    }
}
