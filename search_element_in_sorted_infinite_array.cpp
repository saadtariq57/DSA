// Search an element in an Infinte Sorted Array

#include <iostream>
using namespace std;

int binarySearch(int arr[], int key, int start, int end){
  int mid;
  while(start <= end){
    mid = (start + end) / 2;
    if(key == arr[mid]){
      return mid;
    }

    if(key < arr[mid]){
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }

  return -1;
}

int main()
{
    int arr[] = {2, 3, 5, 7, 11, 13, 15, 19, 23, 29, 100, 200}; //9-16
    int start = 0, end = 1;
    int key = 100;

    int result = -1;

    while(arr[start] <= key){
        if(arr[start] == key){
            result = start;
            break;
        }
        result = binarySearch(arr, key, start, end);
        cout<<result;
        if(result != -1){
            break;
        } else{
            start = end + 1;
            end = start * 2;
        }

    }

    // if(arr[start] == key){
    //   result = start;
    // }

    cout<<"Result = "<<result;

}
