#include <iostream>
#include <vector>
using namespace std;

void heapifyUp(vector<int>& array, int index) {    
    if(index > 1) {
        int parentIndex = index / 2;
        
        if (array[index] < array[parentIndex]) {
            swap(array[index], array[parentIndex]);
            heapifyUp(array, parentIndex);
        }
    }
}

void heapifyDown(vector<int>& array, int index, int n) {
    
    int k = index;
   int v = array[index];
   int lowestChild = 2 * k;
   bool heap = false;
 
   while(!heap && k * 2 <= n) {
       lowestChild = 2 * k;
       if(lowestChild < n) {
           if(array[lowestChild] > array[lowestChild + 1]) {
               lowestChild = lowestChild + 1;
            }
       }
       if(v <= array[lowestChild]) {
           heap = true;
       }
       else {
           array[k] = array[lowestChild];
           k = lowestChild;
       }
   }
   array[k] = v;
}

void insert(vector<int>& array, int key) {
    array.push_back(key);
    heapifyUp(array, array.size() - 1);
}

int remove(vector<int>& array, int n) {
    swap(array[1], array[n]);
    heapifyDown(array, 1, n - 1);
    
    int last = array.back();
    array.pop_back();

    return last;
}
 
void heapBottomUp(vector<int>& array) {
   int n = array.size() - 1;
  
   for(int i = n / 2; i >= 1; i--) {
       heapifyDown(array, i, n);
   }
}

void solution(vector<int>& heap) {
    int x;
    int y;
    while(heap.size() > 2) {
        x = heap.back();
        heap.pop_back();
        
        y = heap.back();
        heap.pop_back();

        insert(heap, (x + y) - 1);
    }

    cout << heap[1] << '\n';
    
}

int main() {
    
    int numOfCases;
    cin >> numOfCases;
    
    int numOfElements;
    int element;
    for(int i = 0; i < numOfCases; i++) {
        cin >> numOfElements;
        vector<int> heap = {0};

        for(int j = 0; j < numOfElements; j++) {
            cin >> element;
            heap.push_back(element);
        }

        heapBottomUp(heap);
        solution(heap);
    }
}
