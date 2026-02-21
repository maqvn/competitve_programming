    #include <iostream>
    #include <vector>
     
    using namespace std;
     
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
     
    void remove(vector<int>& array, int n) {
        swap(array[1], array[n]);
        heapifyDown(array, 1, n - 1);
        array.pop_back();
    }
     
    void heapBottomUp(vector<int>& array) {
       int n = array.size() - 1;
      
       for(int i = n / 2; i >= 1; i--) {
           heapifyDown(array, i, n);
       }
    }
     
    bool checkDuplicate(vector<int>& array) {
        int key = array[1];
        if(array[2] == array[1] || array[3] == array[1]) {
            while(array[1] == key && array.size() >= 2) {
                remove(array, array.size() - 1);
            } 
            return true;
        }
        return false;
    }
     
    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
     
        vector<int> heap = {0};
     
        int numOfPlayers;
        cin >> numOfPlayers;
     
        int numberChose;
        for(int i = 0; i < numOfPlayers; i++) {
            cin >> numberChose;
            heap.push_back(numberChose);
        }
     
        heapBottomUp(heap);
     
        bool duplicate;
        while(heap.size() > 2 && checkDuplicate(heap)) {}
     
        if(heap.size() > 1) {
            cout << heap[1] << '\n';
        }
        else {
            cout << "-1\n";
        }
     
        return 0;
    }
