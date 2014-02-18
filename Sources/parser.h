#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include <vector>
#include <stack>
#include <string>
#include <math.h>
#include <stdlib.h>

#include <stdio.h>

using namespace std;

template <typename T>
class Parser
{
private:
    int max_var;

    inline int operationToInt(string oper)
    {
        if(oper == "(")
            return -11;
        if(oper == ")")
            return -12;

        if(oper == "+")
            return 51;
        if(oper == "-")
            return 52;

        if(oper == "*")
            return 61;
        if(oper == "/")
            return 62;

        if(oper == "^")
            return 81;

        if(oper == "pi")
            return 801;

        if(oper == "abs")
            return 901;
        if(oper == "sin")
            return 902;
        if(oper == "cos")
            return 903;
        if(oper == "tg")
            return 904;
        if(oper == "ctg")
            return 905;

        return -10;
    }
    string intToOperation(int oper)
    {
        if(oper == -11)
            return "(";
        if(oper == -12)
            return ")";

        if(oper == 51)
            return "+";
        if(oper == 52)
            return "-";

        if(oper == 61)
            return "*";
        if(oper == 62)
            return "/";

        if(oper == 81)
            return "^";

        if(oper == 801)
            return "pi";

        if(oper == 901)
            return "abs";
        if(oper == 902)
            return "sin";
        if(oper == 903)
            return "cos";
        if(oper == 904)
            return "tg";
        if(oper == 905)
            return "ctg";

        return "{ERROR}";
    }
    int getPriority(int i)
    {
        return i / 10;
    }

    bool isDigit(char c)
    {
        return (c >= '0' && c <= '9') || (c == '.');
    }
    bool isOperation(string str)
    {
        return str == "+" ||
               str == "-" ||
               str == "*" ||
               str == "/" ||
               str == "(" ||
               str == ")" ||
               str == "^" ||
               str == "abs" ||
               str == "sin" ||
               str == "cos" ||
               str == "tg" ||
               str == "ctg" ||
               str == "pi";
    }

    string inputExpr;
    vector< pair<int, T> > parts;
    bool addNumber(int st, int en)
    {
        T v = 0;
        int i = st;
        for(; i <= en && inputExpr[i] != '.'; ++i)
            v = v*10 + (int)(inputExpr[i] - '0');
        ++i;

        T x = 1;
        for(; i <= en && inputExpr[i] != '.'; ++i)
        {
            x /= 10.0;
            v += x * (int)(inputExpr[i] - '0');
        }

        if(i <= en)
            return false;

        parts.push_back(make_pair(1, v));
        return true;
    }
    void addOperation(int st, int en)
    {
        T v = operationToInt(inputExpr.substr(st, en-st+1));
        parts.push_back(make_pair(2, v));
    }
    bool addVariable(int st, int en)
    {
        T v = 0;
        int i = st;
        for(; i <= en && inputExpr[i] != '.'; ++i)
            v = v*10 + (int)(inputExpr[i] - '0');

        if(i <= en)
            return false;

        max_var = max(max_var, (int)v);
        parts.push_back(make_pair(3, v));
        return true;
    }
    bool setParts()
    {
        for(int i = 0; i < inputExpr.length(); ++i)
            if(inputExpr[i] == ' ')
            {
                inputExpr.erase(i, 1);
                --i;
            }
        cout << inputExpr << endl;

        inputExpr += ' ';
        int pos = 0;
        while(inputExpr[pos] != ' ')
        {
            int lst = pos;
            if(isDigit(inputExpr[pos]))
            {
                while(isDigit(inputExpr[lst]))
                    ++lst;
                if(!addNumber(pos, lst-1))
                    return false;
                pos = lst;
            }
            else if(inputExpr[pos] == '{')
            {
                ++lst;
                while(inputExpr[lst] != ' ' && inputExpr[lst] != '}')
                {
                    if(!isDigit(inputExpr[lst]))
                        return false;
                    ++lst;
                }

                if(inputExpr[lst] == ' ')
                    return false;

                if(!addVariable(pos+1, lst-1))
                    return false;

                pos = lst + 1;
            }
            else
            {
                while(inputExpr[lst] != ' ' &&
                      (!isOperation(inputExpr.substr(pos, lst-pos+1))))
                        ++lst;

                if(inputExpr[lst] == ' ')
                    return false;

                addOperation(pos, lst);
                pos = lst + 1;
            }
        }
        return true;
    }

    stack< pair<int, T> > buffer;
    vector< pair<int, T> > polishNotation;
    bool formNotation()
    {
        buffer.push(make_pair(-20, -20));
        for(int i = 0; i < parts.size(); ++i)
            if(parts[i].first == 1 || parts[i].first == 3)
            {
                polishNotation.push_back(parts[i]);
            }
            else if(parts[i].first == 2)
            {
                if(parts[i].second == operationToInt("("))
                {
                    buffer.push(parts[i]);
                }
                else if(parts[i].second == operationToInt(")"))
                {
                    while(buffer.size() > 1 &&
                          buffer.top().second != operationToInt("("))
                    {
                        polishNotation.push_back(buffer.top());
                        buffer.pop();
                    }
                    buffer.pop();
                    if(buffer.size() == 0)
                        return false;
                }
                else
                {
                    while(getPriority(buffer.top().second) >=
                          getPriority(parts[i].second))
                    {
                        polishNotation.push_back(buffer.top());
                        buffer.pop();
                    }
                    buffer.push(parts[i]);
                }
            }

        while(buffer.size() > 1)
        {
            if(buffer.top().second == operationToInt("("))
                return false;
            polishNotation.push_back(buffer.top());
            buffer.pop();
        }
        return true;
    }

public:

    Parser()
    {
        variables = NULL;
    }

    Parser(vector<T>* _variables)
    {
        variables = _variables;
    }

    bool parse(string expr)
    {
        max_var = -1;
        parts.clear();
        polishNotation.clear();
        while(!buffer.empty())
            buffer.pop();
        inputExpr = expr;

        if(!setParts())
            return false;
        if(!formNotation())
            return false;

        parts.clear();
        polishNotation.clear();
        while(!buffer.empty())
            buffer.pop();
        inputExpr.clear();

        return true;
    }

    void printNotation()
    {
        for(int i = 0; i < polishNotation.size(); ++i)
        {
            if(polishNotation[i].first == 1)
                cout << polishNotation[i].second << ' ';
            else if(polishNotation[i].first == 3)
                cout << '{' << polishNotation[i].second << '}' << ' ';
            else
                cout << intToOperation(polishNotation[i].second) << ' ';
        }
        printf("\n");
    }

    vector<T>* variables;

    T calc()
    {
        stack<T> tmp;
        for(int i = 0; i < polishNotation.size(); ++i)
        {
            if(polishNotation[i].first == 1)
            {
                //Constant
                tmp.push(polishNotation[i].second);
            }
            else if(polishNotation[i].first == 2)
            {
                //Getiing constants
                if(polishNotation[i].second == operationToInt("pi"))
                    { tmp.push( acos(-1) ); continue; }

                //Unar Function
                T a = tmp.top(); tmp.pop();
                if(polishNotation[i].second == operationToInt("abs"))
                    { tmp.push( fabs(a) ); continue; }
                if(polishNotation[i].second == operationToInt("sin"))
                    { tmp.push( sin(a) ); continue; }
                if(polishNotation[i].second == operationToInt("cos"))
                    { tmp.push( cos(a) ); continue; }
                if(polishNotation[i].second == operationToInt("tg"))
                    { tmp.push( sin(a) / cos(a) ); continue; }
                if(polishNotation[i].second == operationToInt("ctg"))
                    { tmp.push( cos(a) / sin(a) ); continue; }

                //Binar Function
                T b = a;
                a = tmp.top(); tmp.pop();
                if(polishNotation[i].second == operationToInt("/"))
                {
                    if(b == 0.0) { return NAN; }
                    tmp.push( a / b ); continue;
                }
                if(polishNotation[i].second == operationToInt("+"))
                    { tmp.push( a + b ); continue; }
                if(polishNotation[i].second == operationToInt("-"))
                    { tmp.push( a - b ); continue; }
                if(polishNotation[i].second == operationToInt("*"))
                    { tmp.push( a * b ); continue; }
                if(polishNotation[i].second == operationToInt("^"))
                    { tmp.push( pow(a,b) ); continue; }
            }
            else if(polishNotation[i].first == 3)
            {
                //Variable
                if(variables == NULL)
                    return NAN;
                int j = polishNotation[i].second;
                if(j < 0 || j >= variables -> size())
                    return NAN;
                T res = (*variables)[j];
                tmp.push(res);
            }
        }
        return tmp.top();
    }

    int getVariablesCount()
    {
        return max_var + 1;
    }
};

#endif // PARSER_H_INCLUDED
