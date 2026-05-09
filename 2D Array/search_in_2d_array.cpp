// It's better to use vectors because classic 2D array in C++ can't be dynamically pass.

#include <iostream>
using namespace std;

int searchIn2D(int arr[][4], int totalRows, int col, int target){
  int row = 0;
  
  while(row < totalRows && col >= 0){
    if( target == arr[row][col] )
      return arr[row][col];
    else if( target > arr[row][col] )
      row++;
    else
      col--;
  }
  
  return -1;
}

int main(){
    int arr[3][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12}
    };
    
    int target = 1;
    
    int result = searchIn2D(arr, 3, 4 - 1, target);
    
    if(result == -1){
      cout<<target<<" not found!";
    }
    else{
      cout<<"Target found: "<<result;
    }


}