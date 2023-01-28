
#include <iostream>
#include <map>
#include <string>

using namespace std;

int initialDots = 2;

void getRow (int c, string initialChar, string separator){

    string result= "";
    for (size_t i = 0; i < initialDots; i++) result = result + ".";

    result = !initialDots && initialChar == "" ? result + "|" : result;

    initialDots = max(--initialDots, 0);

    result = result + initialChar;
    for (size_t i = 0; i < c-initialDots; i++) result = result + separator;
    cout<< result << endl;

}

int main() {

    int T, R, C;
    cin >> T;

    for (size_t i = 0; i < T; i++)
    {
        initialDots = 2;
        cin >> R >> C;
        cout << "Case #" << i+1<< ":"<<endl;
        getRow (C, "+", "-+");

        for (size_t i = 0; i < R; i++)
        {
            getRow (C, "", ".|");
            getRow (C, "+", "-+");
        }
        
    }
    
    return 0;

}
