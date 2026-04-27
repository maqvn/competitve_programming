#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    int length;
    map<string, map<string, string>> op;
    
    op["+x"]["+y"] = "+y";
    op["+x"]["-y"] = "-y";
    op["+x"]["+z"] = "+z";
    op["+x"]["-z"] = "-z";

    op["-x"]["+y"] = "-y";
    op["-x"]["-y"] = "+y";
    op["-x"]["+z"] = "-z";
    op["-x"]["-z"] = "+z";

    op["+y"]["+y"] = "-x";
    op["+y"]["-y"] = "+x";
    op["+y"]["+z"] = "+y";
    op["+y"]["-z"] = "+y";

    op["-y"]["+y"] = "+x";
    op["-y"]["-y"] = "-x";
    op["-y"]["+z"] = "-y";
    op["-y"]["-z"] = "-y";

    op["+z"]["+y"] = "+z";
    op["+z"]["-y"] = "+z";
    op["+z"]["+z"] = "-x";
    op["+z"]["-z"] = "+x";

    op["-z"]["+y"] = "-z";
    op["-z"]["-y"] = "-z";
    op["-z"]["+z"] = "+x";
    op["-z"]["-z"] = "-x";

    while(cin >> length && length != 0) {
        string movement = "";
        string currentDirection = "+x";
        
        for(int j = 1; j < length; ++j) {
            cin >> movement;   
            if(movement != "No") {
                currentDirection = op[currentDirection][movement];
            }
        }
        cout << currentDirection << '\n';
    
    }

    return 0;
}