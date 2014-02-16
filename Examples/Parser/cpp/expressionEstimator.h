/******************************************************
Copyright (c/c++) 2013-doomsday by Alexey Slovesnov
homepage http://slovesnov.narod.ru/indexe.htm
email slovesnov@yandex.ru
All rights reserved.
******************************************************/

#ifndef _expressionEstimator_h_
#define _expressionEstimator_h_

#include "stdafx.h"
#include "node.h"
#include "exception.h"

class Node;

class ExpressionEstimator
{

    friend class Node;

    std::string expression;
    double tokenValue;
    OPERATOR_ENUM _operator;
    int position;
    const double* argument;
    int argumentSize;
    int arguments;

    Node* root;

    inline bool isLetter()
    {
        return isalpha(expression[position])!=0;
    }

    inline bool isDigit()
    {
        return isdigit(expression[position])!=0;
    }

    inline bool isDigit(char c)
    {
        return isdigit(c)!=0;
    }

    inline bool isPoint()
    {
        return expression[position]=='.';
    }

    inline bool isFunctionSymbol()
    {
        char c=expression[position];
        return isalnum(c)!=0 || c=='_';
    }

    void getToken() throw (Exception);


    std::vector<Node*> vnode;

    Node* parse() throw (Exception);
    Node* parse1() throw (Exception);
    Node* parse2() throw (Exception);
    Node* parse3() throw (Exception);

    inline Node* createNode(OPERATOR_ENUM _operator, Node* left)
    {
        Node*node=new Node();
        node->init(this,_operator,0, left);
        return node;
    }

    inline Node* createNode(OPERATOR_ENUM _operator)
    {
        Node*node=new Node();
        node->init(this,_operator,0,NULL);
        return node;

    }

    inline Node* createNode(OPERATOR_ENUM _operator,double value)
    {
        Node*node=new Node();
        node->init(this,_operator,value, NULL);
        return node;
    }


    inline void checkBracketBalance(OPERATOR_ENUM open) throw (Exception)
    {
        if(open==LEFT_BRACKET && _operator!=RIGHT_BRACKET ||
                open==LEFT_SQUARE_BRACKET && _operator!=RIGHT_SQUARE_BRACKET ||
                open==LEFT_CURLY_BRACKET && _operator!=RIGHT_CURLY_BRACKET)
        {
            throw Exception("close bracket expected or another type of close bracket");
        }
    }

    static int getIndex(const char* a[],const char *v) throw (IllegalArgumentException);

    void clear();

public:

#ifdef _DEBUG
    static int totalCreated;
    static int totalDestroyed;
#endif

    ExpressionEstimator()
    {
        root=NULL;//don't remove
    }

    bool compile(const char* _expression) throw(Exception);

    inline double calculate(const double x[],int size) throw (Exception)
    {
        argument=x;
        argumentSize=size;
        return calculate();
    }

    double calculate() throw (Exception);

    /**
     *
     * @return number of expression arguments
     */
    inline int getArguments()
    {
        return arguments;
    }

    static double calculate(const char* s) throw (Exception);

    inline static void Init()
    {
        srand (time(NULL));
    }


    ~ExpressionEstimator();
};

#endif
