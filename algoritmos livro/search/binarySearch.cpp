#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> num_array, int arraySize, int key) {
    int l = 0;
    int r = arraySize;
    int m = r / 2;

    while(l <= r) {
        if(num_array[m] == key) {
            return m;
        }
        else if(m > key) {
            r = m - 1;
            m = r / 2;
        }
        else {
            l = m + 1;
            m = (r + l) / 2;
        }
    }

    return -1;
}

int main() {
    int array_size;
    int number;
    int key;

    cin >> array_size;
    cin >> key;

    vector<int> num_array(array_size);

    for(int i = 0; i < array_size; i++) {    
        cin >> number;
        num_array[i] = number;
    }

    cout << binarySearch(num_array, array_size, key) << endl;


    return 0;
}