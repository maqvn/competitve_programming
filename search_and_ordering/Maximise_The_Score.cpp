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

int findMaxScore(vector<int>& numList) {
    int maxScore = 0;
    
    for(int i = numList.size() - 2; i >= 0; i-=2) {
        maxScore += numList[i];
    }

    return maxScore;
}

int main() {
    int numOfCases;

    cin >> numOfCases;

    for(int j = 0; j < numOfCases; j++) {
        int numOfPairs;
        cin >> numOfPairs;
        
        vector<int> numList(numOfPairs*2);
        for(int i = 0; i < numOfPairs*2; i++) {
            cin >> numList[i];
        }
        
        mergeSort(numList); 
        cout << findMaxScore(numList) << endl;
    }


    return 0;
}
