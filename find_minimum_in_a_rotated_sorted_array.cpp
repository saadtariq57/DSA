#include <iostream>
using namespace std;

int findPivot(int arr[], int size){
    int low = 0;
    int high = size - 1;
    int mid;

    while( low < high ){
        mid = (low + high) / 2;
        
        if(arr[mid] > arr[high]){
            low = mid + 1;
        }
        else {
            high = mid;
        }
    }

    return arr[low];
}

int main(){
    // Pivot is also the smallest number in the array, so that's the minimum in the Rotated Sorted array
    int arr[6] = {15, 18, 2, 3, 6, 12};
    int pivot = findPivot(arr, 6);
    cout<<"Pivot: "<<pivot;
}