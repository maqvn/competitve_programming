#include <iostream>
using namespace std;

void bubbleSort(int num_array[]) {

    int array_size = 5;

    for(int i = 0; i < array_size - 1; i++) {
        for(int j = 0; j < array_size - 1; j++) {
            if(num_array[j] > num_array[j + 1]) {
                int temp = num_array[j];
                num_array[j] = num_array[j + 1];
                num_array[j + 1] = temp;
            }
        }
    }
}

int main() {

    int num_array[] = {5, 4, 3, 2, 1};
    bubbleSort(num_array);

    for(int i = 0; i < 5; i++) {
        cout << num_array[i] << " ";
    }
    cout << endl;
    
    return 0;
}