#include <iostream>
#include <iostream>

using namespace std;

#include "parser.h"

int main()
{
    Parser p;
    if(!p.parse("3 + 4 * 2 / (1 - 5)^2"))
        cout << "ERROR!\n";
    else
    {
        p.printNotation();
    }

    return 0;
}
