//
//  main.cpp
//  combineString
//
//  Created by Richard Soksann Edwards on 2/21/22.
//

#include <iostream>


std::string combineStr(std::string entered_string, int num_of_times){
    
    std::string string_holder = entered_string;
    for(int i = 1; i < num_of_times; i++){
        entered_string = entered_string + string_holder;
    }
    return entered_string;
}




int main(){
    std::string entered_string;
    int num_of_times;
    
    std::cout << "Enter a string: " << std::endl;
    std::cin >> entered_string;
    
    std::cout << "Enter a number of times: " << std::endl;
    std::cin >> num_of_times;
    
    std::cout << "The resulting string is: " <<combineStr(entered_string, num_of_times);
}



