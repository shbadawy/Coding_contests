#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {

    int T, rem, color_value, current_color, j, k;  
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        vector< pair<int, int> > minimum_color_in_printers (4,make_pair(1000000,0));
        int result [4]={0,0,0,0};
        rem = 1000000;

        for( j = 0 ; j < 3; j++)
            for ( k = 0; k < 4; k++)
            {
                cin >> current_color;
                minimum_color_in_printers[k].first = min(minimum_color_in_printers[k].first, current_color);
                minimum_color_in_printers[k].second = k;
            }

        std::sort(minimum_color_in_printers.begin(), minimum_color_in_printers.end(), std::greater< pair<int, int> >());
        
        j = 0;
        while (j < 4 && rem>0)
        {
            color_value = min(minimum_color_in_printers[j].first, rem);
            result[minimum_color_in_printers[j].second] = color_value;
            rem -= color_value; 
            j++;
        }

        cout << "Case #" << i+1<< ": ";

        if (rem > 0 ) cout << "IMPOSSIBLE" << endl;
        else {
                for ( k  = 0; k < 4; k++) {
                    cout << result[k];
                    if (k != 3 ) cout << " ";
                    else cout << endl;
                }
        }

    }
    
    return 0;

}
