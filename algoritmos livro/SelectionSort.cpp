#include <iostream>
using namespace std;

void selection_sort(int list_size, int num_list[]) {
    
    int minimum;
    for(int i = 0; i < list_size - 1; i++) {
        minimum = i;

        for(int j = i; j < list_size; j++) {
            
            if(num_list[j] < num_list[minimum]) {
                minimum = num_list[j];
            }
            
            int temp = num_list[minimum];
            num_list[minimum] = num_list[j];
            num_list[j] = temp;
        } 
    }
}

int main() {
    int num_list[5] = {5, 4, 3, 2, 1};
    selection_sort(5, num_list);
    
    for(int i = 0; i < 5; i++) {
        cout << num_list[i] << " ";
    }

    cout << endl;

    return 0;
}
