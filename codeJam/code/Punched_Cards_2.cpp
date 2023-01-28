#include <iostream>
#include <string>

using namespace std;

string repeatString(string str, int numberOfTimes){

    string result = "";
    for (size_t i = 0; i < numberOfTimes; i++) result = result+ str;

    return result;

}

int main() {

    int T, R, C;

    cin >> T;

    for (size_t i = 0; i < T; i++)
    {

        cin >> R >> C;

        int numberOfRepetition;
        string line = "";

        cout << "Case #" << i+1<< ":"<<endl;

        for (int j = 0 ; j < R*2+1; j++){

            numberOfRepetition = j ==0 ? C-1 : C;

            line = j < 2 ? repeatString(".", 2 - j) : "";
            line = j > 2 && j%2 != 0 ? "|" : line; 
            line = j%2 == 0 ? line + "+" + repeatString("-+", numberOfRepetition) : line  + repeatString(".|", numberOfRepetition);
            cout << line << endl;

        }
        
    }
    
    return 0;

}
