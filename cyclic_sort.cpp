// Cyclic Sort. Only applicable on consecutive range 1-n. 0 can't exist in array or duplicates.

#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b){
  int temp = a;
  a = b;
  b = temp;
}

void printArray(vector<int> &arr){
  for(int i = 0; i < arr.size(); i++)
      cout<<arr[i]<<" ";
  cout<<endl;
}

void cyclicSort(vector<int> &arr){
  int i = 0;
  while(i < arr.size()){
    int correctIndex = arr[i] - 1;
    if(arr[i] != arr[correctIndex]){
      swap(arr[i], arr[correctIndex]);
      printArray(arr);
    }
    else{
      i++;
    }
  }
}

int main(){  
    vector<int> arr = {5,1,2,4,3};
    
    cout<<"Original: ";
    printArray(arr);
    cyclicSort(arr);
    

}