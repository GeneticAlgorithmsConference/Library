#ifndef TREEEXPRESSIONTEXDNA_H_INCLUDED
#define TREEEXPRESSIONTEXDNA_H_INCLUDED

#include "treeexpressiondna.h"

class
{
    class TreeExpressionTexDna: public TreeExpressionDna
    {
public:
        TreeExpressionTexDna(): TreeExpressionDna() { };

        void print() override;
    };
};

void Genetic::TreeExpressionTexDna::print()
{
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
			dnalog << s[value];
			if(children.size() > 0)
			{
				dnalog << " { ";
				for(int i = 0; i < static_cast<int>(children.size()) - 1; ++i)
				{
					dynamic_cast<TreeExpressionDna*>(children[i]) -> print();
					dnalog << ", ";
				}
				dynamic_cast<TreeExpressionDna*>(children[children.size() - 1]) -> print();
				dnalog << " }";
			}
		} else if(value == 8)
		{
			dnalog << "\\frac{";
			dynamic_cast<TreeExpressionDna*>(children[0]) -> print();
			dnalog << "}{";
			dynamic_cast<TreeExpressionDna*>(children[1]) -> print();
			dnalog << "}";
		} else {
			dnalog << "({";
			dynamic_cast<TreeExpressionDna*>(children[0]) -> print();
			dnalog << "} " << s[value] << " {";
			dynamic_cast<TreeExpressionDna*>(children[1]) -> print();
			dnalog << "})";
		}
	} else {
		dnalog << value;
	}

	// dnalog << this;
	// if(children.size() > 0)
	// {
	// 	dnalog << " ( ";
	// 	for(int i = 0; i < children.size() - 1; ++i)
	// 	{
	// 		dynamic_cast<TreeExpressionDna*>(children[i]) -> print();
	// 		dnalog << ", ";
	// 	}
	// 	dynamic_cast<TreeExpressionDna*>(children[children.size() - 1]) -> print();
	// 	dnalog << " )";
	// }
}

#endif // TREEEXPRESSIONTEXDNA_H_INCLUDED
