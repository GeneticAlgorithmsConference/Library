#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include <vector>
#include <stack>
#include <string>
#include <math.h>

#include <stdio.h>

class Parser
{
private:

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
        return c >= '0' && c <= '9';
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
    vector< pair<int, int> > parts;
    void addNumber(int st, int en)
    {
        int v = 0;
        for(int i = st; i <= en; ++i)
            v = 10*v + (int)(inputExpr[i] - '0');
        parts.push_back(make_pair(1, v));
    }
    void addOperation(int st, int en)
    {
        int v = operationToInt(inputExpr.substr(st, en-st+1));
        parts.push_back(make_pair(2, v));
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
                addNumber(pos, lst-1);
                pos = lst;
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

    stack< pair<int, int> > buffer;
    vector< pair<int, int> > polishNotation;
    bool formNotation()
    {
        buffer.push(make_pair(-20, -20));
        for(int i = 0; i < parts.size(); ++i)
            if(parts[i].first == 1)
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

    bool parse(string expr)
    {
        parts.clear();
        polishNotation.clear();
        while(!buffer.empty())
            buffer.pop();
        inputExpr = expr;

        if(!setParts())
            return false;
        if(!formNotation())
            return false;
        return true;
    }

    void printNotation()
    {
        for(int i = 0; i < polishNotation.size(); ++i)
        {
            if(polishNotation[i].first == 1)
                cout << polishNotation[i].second << ' ';
            else
                cout << intToOperation(polishNotation[i].second) << ' ';
        }
        printf("\n");
    }

    double calc()
    {
        stack<double> tmp;
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
                double a = tmp.top(); tmp.pop();
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
                double b = a;
                a = tmp.top(); tmp.pop();
                if(polishNotation[i].second == operationToInt("+"))
                    { tmp.push( a + b ); continue; }
                if(polishNotation[i].second == operationToInt("-"))
                    { tmp.push( a - b ); continue; }
                if(polishNotation[i].second == operationToInt("*"))
                    { tmp.push( a * b ); continue; }
                if(polishNotation[i].second == operationToInt("/"))
                    { tmp.push( a / b ); continue; }
                if(polishNotation[i].second == operationToInt("^"))
                    { tmp.push( pow(a,b) ); continue; }
            }
            else if(polishNotation[i].first == 3)
            {
                //Variable
            }
        }
        return tmp.top();
    }
};

#endif // PARSER_H_INCLUDED
