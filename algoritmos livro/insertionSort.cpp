#include <iostream>
using namespace std;

void insertionSort(int array_num[], int size_array) {
    for(int i = 1; i < size_array; i++) {
        
        int num = array_num[i];
        int j = i - 1;
        while(j >= 0 && array_num[j] > num) {
            array_num[j+1] = array_num[j];
            j -= 1;
        }
        array_num[j+1] = num;
    }
}

int main() {
    int array_num[5] = {5, 4, 3, 2, 1};

    insertionSort(array_num, 5);

    for(int i = 0; i < 5; i++) {
        cout << array_num[i] << " ";
    }

    cout << endl;

    return 0;
}