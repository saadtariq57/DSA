// Search in full sorted 2D array. We are using vector becasue C++ don't handle dynamic 2D arrays.

#include <iostream>
#include <vector>

using namespace std;

bool searchIn2DSorted(vector<vector<int>> &arr, int target){
  int rows = arr.size();
  int cols = arr[0].size();
  
  int low = 0;
  int high = rows * cols - 1;
  int mid;
  
  while(low <= high){
    mid = (low + high) / 2;
    
    // Need to find the coordinates of mid (row and column)
    int row = mid / cols;
    int col = mid % rows;
    
    if(target == arr[row][col])
      return true;
    else if(target < arr[row][col])
      high = mid - 1;
    else
      low = mid + 1;
  }
  
  return false;
}

int main(){
    vector<vector<int>> arr = {
        {1, 3, 5},
        {7, 9, 11},
        {13, 15, 17}
    };
    
    int target = 12;
    int result = searchIn2DSorted(arr, target);
    
    cout<<"Target found: "<<result; // 1 for true, 0 for false

}