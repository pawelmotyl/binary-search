/*
 * Author: Paweł Motyl
 * 
 * Recursive implementation of binrary search
 */

#include <iostream>

int binarySearch(int searchFor, int A[], int start, int stop);

int main() {
    int N = 20;
    int sortedArray[N] {1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 13, 15, 16, 16, 17, 17, 17, 17, 18, 40};
    
    int searchFor {0};
    std::cout<<"Enter integer value to search for in given array: ";
    std::cin>>searchFor;
    
    int result = binarySearch(searchFor, sortedArray, 0, N-1);
    
    if (result >= 0){
        std::cout<<"Index of searched element: "<<result<<std::endl;
    } else {
        std::cout<<searchFor<<" does not exist in the array"<<std::endl;
    }
    
    return 0;
}

int binarySearch(int searchFor, int A[], int start, int stop) {
    int numberOfElements = stop - start + 1;
    if (numberOfElements > 1)
    {
        int middle = (start + stop) / 2;
        if (searchFor <= A[middle]) {
            return binarySearch(searchFor, A, start, middle);
        } else {
            return binarySearch(searchFor, A, middle + 1, stop);
        }
    } else if(A[start] == searchFor) {
        return start;
    } else {
        return -1;
    }
}
