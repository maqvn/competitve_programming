#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& list_b, vector<int>& list_c, vector<int>& list_a) {    
    
    int b = 0;
    int c = 0;
    int j = 0;

    while (b < list_b.size() && c < list_c.size()) {
        if(list_b[b] < list_c[c]) {
            list_a[j] = list_b[b];
            b++;
        }
        else {
            list_a[j] = list_c[c];
            c++;
        }
        j++;
    }

    while(b < list_b.size()) {
        list_a[j] = list_b[b];
        j++;
        b++;
    }
    while(c < list_c.size()) {
        list_a[j] = list_c[c];
        j++;
        c++;
    }
}

void mergeSort(vector<int>& list_a) {
    vector<int> list_b((list_a.size() / 2));
    vector<int> list_c(list_a.size() - (list_a.size() / 2));

    if (list_a.size() > 1) {
        for(int i = 0; i < list_a.size() / 2; i++) {
            list_b[i] = list_a[i];
        }
        for(int i = 0; i < list_a.size() - list_a.size() / 2; i++) {
            list_c[i] = list_a[i + list_a.size() / 2];
        }

        mergeSort(list_b);
        mergeSort(list_c);
        merge(list_b, list_c, list_a);
    }

}

int main() {
    vector<int> list_num = {8, 3, 2, 9, 7, 1, 5, 4};
    mergeSort(list_num);


    for(int i = 0; i < list_num.size(); i++) {
        cout << list_num[i] << " ";
    }

    cout << endl;

    return 0;
}