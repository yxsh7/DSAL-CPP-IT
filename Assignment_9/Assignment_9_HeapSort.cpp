/*
SI32 Yash Kamthe
GITHUB: https://github.com/yxsh7
Implement heap sort to sort given set of values using max or min heap
*/
#include <iostream>
using namespace std;

class HeapSort{
    private:
    void createHeap(int arr[], int size, int root);
    public:
    void sort(int arr[], int size);
};

void HeapSort::createHeap(int arr[], int size, int root){
    int largest, leftChild, rightChild;

    largest = root; // Assume root is already largest
    leftChild = 2*root+1;
    rightChild = 2*root+2;

    if(leftChild<size && arr[leftChild]>arr[largest])
        largest = leftChild;

    if(rightChild<size && arr[rightChild]>arr[largest])
        largest = rightChild;

    if(largest !=root){
        swap(arr[root], arr[largest]);
        createHeap(arr, size, largest);
    }

}

void HeapSort::sort(int arr[], int size){
    
    for (int i = size / 2 - 1; i >= 0; i--)
		createHeap(arr, size, i);
    
    for (int i = size - 1; i > 0; i--) {
		swap(arr[0], arr[i]);
		createHeap(arr, i, 0);
	}
}

int main(){

    int size;
    HeapSort heap;

	cout << "Enter Size of your array : ";
	cin >>size;
	int *arr = new int(size);
	cout << "Enter Array Elements : ";
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}

    heap.sort(arr, size);
    cout<<"Sorted Array : ";
    for (int i=0;i<size;i++){
        cout<< arr[i];
        if(i!=size-1) cout<< ", ";
    }
    cout<<endl;
    return 0;
}