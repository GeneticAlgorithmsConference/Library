#include <iostream>
#include <iostream>

using namespace std;

#include "parser.h"

int main()
{
    Parser p;
    if(!p.parse("3 + 4 * 2 / (1 - 5)^2 + abs(7 - 13) + sin(pi/2)"))
        cout << "ERROR!\n";
    else
    {
        cout << "Polish Notation:\n";
        p.printNotation();
        cout << "Result: " << p.calc() << endl;
    }

    return 0;
}
