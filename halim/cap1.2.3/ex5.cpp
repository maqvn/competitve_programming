#include <bits/stdc++.h>
using namespace std;

struct Date {
    int dd;
    int mm;
    int yy;
    string nn;

    Date(int day, int month, int year, string nome) {
        dd = day;
        mm = month;
        yy = year;
        nn = nome;
    }
};

int main() {
    int a, d, m, y;
    cin >> a;
    string n;

    vector<Date> lista;
    
    for(int i = 0; i < a; i++) {
        cin >> d >> m >> y >> n;
        lista.push_back({d, m, y, n});

    }
    cout << '\n';
    // ===============================================================

    sort(lista.begin(), lista.end(), [](const Date &a, const Date &b){
        return a.mm < b.mm;
    });
    
    cout << "By month\n";
    for(auto x : lista) {
        cout << x.nn << " -mm- " << x.mm << '\n';
    }
    cout << '\n';

    // ===============================================================

    sort(lista.begin(), lista.end(), [](const Date &a, const Date &b){
        return a.dd < b.dd;
    });
    
    cout << "By day\n";
    for(auto x : lista) {
        cout << x.nn << " -dd- " << x.dd << '\n';
    }
    cout << '\n';

    // ===============================================================

    sort(lista.begin(), lista.end(), [](const Date &a, const Date &b){
        return a.yy < b.yy;
    });
    
    cout << "By year\n";
    for(auto x : lista) {
        cout << x.yy << " -yy- " << x.yy << '\n';
    }
    cout << '\n';

    return 0;
}