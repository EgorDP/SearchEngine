#include "Binary.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

template <typename T>
bool binarySearch(string query){
    vector<string> arr; 
    int left = 0;
    int right = arr.size()-1;
    bool found = false;
    if(left == right){ // Empty array
        return false;
    }
    while(!found){
        if(left > right){
            break;
        }
        int middle = ceil((double)(right-left)/2) + left;
        if(arr[middle] == query ){
            found = true;
        }else if(arr[middle] > query){
            right = middle-1;
        }else{
            left = middle+1;
        }
    }
    return found;
}
bool search(vector<string> arr, string query){
    int left = 0;
    int right = arr.size()-1;
    bool found = false;
    if(left == right){ // Empty array
        return false;
    }
    while(!found){
        if(left > right){
            break;
        }
        int middle = ceil((double)(right-left)/2) + left;
        if(arr[middle] == query ){
            found = true;
        }else if(arr[middle] > query){
            right = middle-1;
        }else{
            left = middle+1;
        }
    }
    return found;
}
// void testBinary(){
//     cout << "Entering Binary Test\n";
//     for(int i =0; i < 50; ++i){
//         vector<int> test;
//         int length = 50;
//         for(int x = 0; x < length; x++){
//             test.push_back(rand() % 100);
//         }
//         sort(test.begin(),test.end());
//         int index = 1;
//         if(i > 25){
//             int someNum = rand() % 100;
//             bool mine = binarySearch(test,someNum);
//             bool tested = binary_search(test.begin(), test.end(),someNum);
//             if(mine != tested){
//                 cout << "Fail" <<"\n";
//             }
//         }else{
//             if(binarySearch(test,test[index]) != (bool) binary_search(test.begin(), test.end(),test[index] )){
//                 cout << "Fail" <<"\n";
//             }
//         }
//         cout << i << "\n";
//     }
// }  