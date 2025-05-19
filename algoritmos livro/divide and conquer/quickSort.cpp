#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& numArray, int left, int right) {
    int pivot = numArray[left];
    int start = left;
    int temp;

    while(left < right){
        while(numArray[left] < pivot && left < right) {
            left ++;
        }
        while(numArray[right] > pivot && right > left) {
            right --;
        }
        temp = numArray[left];
        numArray[left] = numArray[right];
        numArray[right] = temp;
    }
    temp = numArray[left];
    numArray[left] = numArray[right];
    numArray[right] = temp;

    temp = numArray[left];
    numArray[left] = numArray[right];
    numArray[right] = temp;

    return right;
}

void quickSort(vector<int> &numArray, int left, int right) {
    int s = partition(numArray, left, right);
    quickSort(numArray, left, s - 1);
    quickSort(numArray, s + 1, right);
}

int main() {
    int arraySize;
    cin >> arraySize;

    vector<int> numArray(arraySize);

    for(int i = 0; i < arraySize; i++) {
        cin >> numArray[i];
    }

    for(int i = 0; i < arraySize; i++) {
        cout << numArray[i] << " ";
    }
    cout << endl;

    quickSort(numArray, 0, arraySize - 1);

    for(int i = 0; i < arraySize; i++) {
        cout << numArray[i] << " ";
    }
    cout << endl;

    return 0;
}