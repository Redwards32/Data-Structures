#include<iostream>

void sortArr(int condition, int myArray[], int array_Size);

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
        

    sortArr(condition, myArray, array_size);
        return 0;
    }

}


void sortArr(int condition, int myArray[], int array_size){
    int placeholder;
    if(condition == 0){
        std::cout<<"This is the sorted array in ascending order: ";
        for (int i = 0; i < array_size; i++){
            for (int j = 0; j < array_size; j++){
                if (myArray[i] > myArray[j]){

                placeholder = myArray[i];
                myArray[i] = myArray[j];
                myArray[j] = placeholder;
                    }
                }
            }
        for(int i = 0; i < array_size; i++){
            std::cout << myArray[i] << " ";
        }
    }

    if(condition == 1){
        std::cout<<"This is the sorted array in descending order: ";
        for (int i = 0; i < array_size; i++){
            for (int j = 0; j < array_size; j++){
                if (myArray[i] > myArray[j]){
                    placeholder = myArray[i];
                    myArray[i] = myArray[j];
                    myArray[j] = placeholder;
                    }
                }
            }
        for(int i = 0; i < array_size; i++){
            std::cout << myArray[i] << " ";
        }
    }else if(condition > 1 || condition < 0){
    std::cout <<"You did not enter a valid OPTION to sort the array!!" << std::endl;
        }
}
