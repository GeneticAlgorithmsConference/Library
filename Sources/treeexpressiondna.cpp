#include "treeexpressiondna.h"

#include <sstream>

const int Genetic::TreeExpressionDna::maxDepth = 2;

Genetic::TreeExpressionDna::TreeExpressionDna()
{

}

Genetic::TreeExpressionDna::TreeExpressionDna(int currentDepth)
{
    generate(currentDepth);
}

Genetic::TreeExpressionDna& Genetic::TreeExpressionDna::operator=(TreeExpressionDna& dna)
{
    value = dna.value;
    children.resize(dna.getChildrenNum());
    for(unsigned int i = 0; i < children.size(); ++i)
    {
        children[i] = new TreeExpressionDna();
        *(dynamic_cast<TreeExpressionDna*>(children[i])) = *(dynamic_cast<TreeExpressionDna*>(dna.children[i]));
    }
    return *this;
}

void Genetic::TreeExpressionDna::mutate(double parameter)
{
    // 0 - abs
    // 1 - sin
    // 2 - cos
    // 3 - tan
    // 4 - ctg

    // 5 - +
    // 6 - -
    // 7 - *
    // 8 - /
    // 9 - ^

    // 10 - x

    // if(value <= 4)
    // {
    // 	value = rand() % 5;
    // } else if(value <= 9)
    // {
    // 	value = rand() % 5 + 5;
    // } else if(value > 10)
    // {
    // 	value = rand() % (2 * range + 1) + 20;
    // }
    int depth;
    TreeExpressionDna* target = dynamic_cast<TreeExpressionDna*>(getRandom(depth));
    target -> generate(depth);
}

void Genetic::TreeExpressionDna::generate(double parameter)
{
    int currentDepth = parameter + 0.1;
    for(int i = 0; i < children.size(); ++i)
    {
        delete children[i];
    }
    children.clear();
    range = 10000;
    value = rand() % 3;
    if(currentDepth == maxDepth)
    {
        value = 2;
    }

    if(value == 0)
    {
        value = rand() % 5;
        children.resize(1);
        children[0] = new Genetic::TreeExpressionDna(currentDepth + 1);
    } else if(value == 1)
    {
        value = rand() % 5 + 5;
        children.resize(2);
        children[0] = new Genetic::TreeExpressionDna(currentDepth + 1);
        children[1] = new Genetic::TreeExpressionDna(currentDepth + 1);
    } else if(value == 2)
    {
        value = 10;
    } else {
        value = rand() % (2 * range + 1) + 20;
    }
}

std::string Genetic::TreeExpressionDna::print()
{
    std::stringstream os;
    static const char* s[] = {
        "\\abs",
        "\\sin",
        "\\cos",
        "\\tan",
        "\\ctg",
        "+",
        "-",
        "\\times",
        "/",
        "^",
        "x"
    };

    if(value <= 10)
    {
        if((value <= 4) || (value == 10))
        {
            os << s[value];
            if(children.size() > 0)
            {
                os << " { ";
                for(int i = 0; i < static_cast<int>(children.size()) - 1; ++i)
                {
                    dynamic_cast<TreeExpressionDna*>(children[i]) -> print();
                    os << ", ";
                }
                dynamic_cast<TreeExpressionDna*>(children[children.size() - 1]) -> print();
                os << " }";
            }
        } else if(value == 8)
        {
            os << "\\frac{";
            dynamic_cast<TreeExpressionDna*>(children[0]) -> print();
            os << "}{";
            dynamic_cast<TreeExpressionDna*>(children[1]) -> print();
            os << "}";
        } else {
            os << "({";
            dynamic_cast<TreeExpressionDna*>(children[0]) -> print();
            os << "} " << s[value] << " {";
            dynamic_cast<TreeExpressionDna*>(children[1]) -> print();
            os << "})";
        }
    } else {
        os << value;
    }

    // os << this;
    // if(children.size() > 0)
    // {
    // 	os << " ( ";
    // 	for(int i = 0; i < children.size() - 1; ++i)
    // 	{
    // 		dynamic_cast<TreeExpressionDna*>(children[i]) -> print();
    // 		os << ", ";
    // 	}
    // 	dynamic_cast<TreeExpressionDna*>(children[children.size() - 1]) -> print();
    // 	os << " )";
    // }
    return os.str();
}

double Genetic::TreeExpressionDna::getValue(double x) const
{
    if(value < 20)
    {
        switch(value)
        {
        case 0:
            return fabs(dynamic_cast<TreeExpressionDna*>(children[0]) -> getValue(x));
            break;
        case 1:
            return sin(dynamic_cast<TreeExpressionDna*>(children[0]) -> getValue(x));
            break;
        case 2:
            return cos(dynamic_cast<TreeExpressionDna*>(children[0]) -> getValue(x));
            break;
        case 3:
            return tan(dynamic_cast<TreeExpressionDna*>(children[0]) -> getValue(x));
            break;
        case 4:
            return 1.0 / tan(dynamic_cast<TreeExpressionDna*>(children[0]) -> getValue(x));
            break;
        case 5:
            return (dynamic_cast<TreeExpressionDna*>(children[0]) -> getValue(x) +
                    dynamic_cast<TreeExpressionDna*>(children[1]) -> getValue(x));
            break;
        case 6:
            return (dynamic_cast<TreeExpressionDna*>(children[0]) -> getValue(x) -
                    dynamic_cast<TreeExpressionDna*>(children[1]) -> getValue(x));
            break;
        case 7:
            return (dynamic_cast<TreeExpressionDna*>(children[0]) -> getValue(x) *
                    dynamic_cast<TreeExpressionDna*>(children[1]) -> getValue(x));
            break;
        case 8:
            return (dynamic_cast<TreeExpressionDna*>(children[0]) -> getValue(x) /
                    dynamic_cast<TreeExpressionDna*>(children[1]) -> getValue(x));
            break;
        case 9:
            return pow(dynamic_cast<TreeExpressionDna*>(children[0]) -> getValue(x),
                    dynamic_cast<TreeExpressionDna*>(children[1]) -> getValue(x));
            break;
        case 10:
            return x;
            break;
        default:
            return 0.0;
        }
    } else {
        return value;
    }
}
