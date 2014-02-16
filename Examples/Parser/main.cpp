#include <iostream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <math.h>

#include "parser.h"

using namespace std;

int main()
{
    vector<double> vars;
    vars.push_back(123);

    Parser<double> p(&vars);
    if(!p.parse("3 + 4 * 2 / (1 - 5)^2 + abs(7 - 13) + sin(pi/2) +{0}+ 0.5"))
        cout << "ERROR!\n";
    else
    {
        cout << "Polish Notation:\n";
        p.printNotation();
        cout << "Result: ";
        double r = p.calc();
        if(r != NAN)
            cout << fixed << setprecision(6) << r << endl;
        else
            cout << "NaN\n";
    }

    return 0;
}
