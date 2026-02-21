    #include <iostream>
    #include <vector>
    #include <string>
    using namespace std;
     
    struct Estudante {
        string nome;
        string curso;
        int nota;
        int idade;
     
        Estudante() {}
     
        Estudante(string nome, string curso, int nota, int idade) {
            this->nome = nome;
            this->curso = curso;
            this->nota = nota;
            this->idade = idade;
        }
    };
     
    void merge(vector<Estudante>& numArray, int left, int right) {
        vector<Estudante> temp(numArray.size());
        for(int i = left; i <= right; i++) {
            temp[i] = numArray[i];
        }
        
        int mid = (right + left) / 2;
        int i1 = left;
        int i2 = mid + 1;
     
        for(int curr = left; curr <= right; curr++) {
            if(i1 > mid) {
                numArray[curr] = temp[i2++];
            }
            else if(i2 > right) {
                numArray[curr] = temp[i1++];
            }
            else if(temp[i1].nota > temp[i2].nota) {
                numArray[curr] = temp[i1++];
            }
            else if (temp[i1].nota < temp[i2].nota){
                numArray[curr] = temp[i2++];
            }
            else {
                if(temp[i1].idade < temp[i2].idade) {
                    numArray[curr] = temp[i2++];
                }
                else {
                    numArray[curr] = temp[i1++];
                }
            }
        }
        
    }
     
    void mergeSort(vector<Estudante>& numArray, int left, int right) {
        if(left < right) {
            int mid = (left + right) / 2;
            mergeSort(numArray, left, mid);
            mergeSort(numArray, mid + 1, right);
            merge(numArray, left, right);
        }
    }
     
    int main() {
        int numCandidates;
        cin >> numCandidates;
     
        vector<Estudante> listaCC;
        vector<Estudante> listaEC;
        vector<Estudante> listaIA;
     
        string nome;
        string curso;
        int nota;
        int idade;
     
        for(int i = 0; i < numCandidates; i++) {
            cin >> nome;
            cin >> curso;
            cin >> nota;
            cin >> idade;
     
            Estudante candidato(nome, curso, nota, idade);
            
            if(curso == "CC") {
                listaCC.push_back(candidato); 
            }
            else if(curso == "EC") {
                listaEC.push_back(candidato);
            }
            else {
                listaIA.push_back(candidato);
            }
        }
     
        mergeSort(listaCC, 0, listaCC.size() - 1);
        mergeSort(listaEC, 0, listaEC.size() - 1);
        mergeSort(listaIA, 0, listaIA.size() - 1);
     
        int notaDeCorteCC;
        if(listaCC.size() >= 100) {
            notaDeCorteCC = listaCC[99].nota;
        }
        else if(listaCC.size() > 0) {
            notaDeCorteCC = listaCC[listaCC.size() - 1].nota;
        }
     
        int notaDeCorteEC;
        if(listaEC.size() >= 100) {
            notaDeCorteEC = listaEC[99].nota;
        }
        else if(listaEC.size() > 0) {
            notaDeCorteEC = listaEC[listaEC.size() - 1].nota;
        }
     
        int notaDeCorteIA;
        if(listaIA.size() >= 50) {
            notaDeCorteIA = listaIA[49].nota;
        }
        else if(listaIA.size() > 0) {
            notaDeCorteIA = listaIA[listaIA.size() - 1].nota;
        }
     
     
        int contador = 0;
     
        if(listaCC.size() == 0) {
            cout << ">> CC (nota de corte = ?)" << endl;
        }
        else {
            cout << ">> CC (nota de corte = " << notaDeCorteCC << ")" << endl;
        }
        cout << "- 1a entrada" << endl;
        while(contador < 50 && contador < listaCC.size()) {
            cout << listaCC[contador].nome << endl;
            contador ++;
        }
     
        cout << "- 2a entrada" << endl;
        while(contador < 100 && contador < listaCC.size()) {
            cout << listaCC[contador].nome << endl;
            contador++;
        }
     
     
     
        contador = 0;    
     
        if(listaEC.size() == 0) {
            cout << ">> EC (nota de corte = ?)" << endl;
        }
        else {
            cout << ">> EC (nota de corte = " << notaDeCorteEC << ")" << endl;
        }
        cout << "- 1a entrada" << endl;
        while(contador < 50 && contador < listaEC.size()) {
            cout << listaEC[contador].nome << endl;
            contador ++;
        }
     
        cout << "- 2a entrada" << endl;
        while(contador < 100 && contador < listaEC.size()) {
            cout << listaEC[contador].nome << endl;
            contador++;
        }
     
     
     
        contador = 0;
     
        if(listaIA.size() == 0) {
            cout << ">> IA (nota de corte = ?)" << endl;
        }
        else {
            cout << ">> IA (nota de corte = " << notaDeCorteIA << ")" << endl;
        }
        cout << "- 1a entrada" << endl;
        while(contador < 25 && contador < listaIA.size()) {
            cout << listaIA[contador].nome << endl;
            contador ++;
        }
     
        cout << "- 2a entrada" << endl;
        while(contador < 50 && contador < listaIA.size()) {
            cout << listaIA[contador].nome << endl;
            contador++;
        }
     
     
        return 0;
    }
