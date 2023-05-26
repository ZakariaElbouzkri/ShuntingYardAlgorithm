/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infix_to_postfix.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 05:33:18 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/05/26 05:37:35 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Eval.hpp"
using namespace std;


queue<string>	infix_to_postfix(string exp, map<char, int> prec)
{
	// map<char, int> prec;
	stack<string>	op_stack;
	queue<string>	res_stack;
	string	dt;

	for (int i=0; i<exp.size(); i++)
	{
		if (!is_token(exp[i])  && exp[i] != LEFT_B && exp[i] != RIGHT_B) {
			cout << SYN_ERROR << exp[i] << endl;
			return queue<string>();
		}
		else if (is_operand(exp[i]))
		{
			string op;
			op.push_back(exp[i]);
			if (op_stack.empty() || (op_stack.top()[0] == LEFT_B || op_stack.top()[0] == RIGHT_B)) {
				op_stack.push(op);
				continue;
			}
			else// 3 + 4 × 2 ÷ ( 1 − 5 ) ^ 2 ^ 3
			{
				while (!op_stack.empty() &&  prec[op[0]] <= prec[op_stack.top()[0]] && (op_stack.top()[0] != LEFT_B && op_stack.top()[0] != RIGHT_B))
				{
					res_stack.push(op_stack.top());
					op_stack.pop();
				}
				op_stack.push(op);
			}
		}
		else if (isdigit(exp[i]))
		{
			string dig;
			while (i < exp.size() && isdigit(exp[i]))
				dig.push_back(exp[i++]);
			i--;
			res_stack.push(dig);
		}
		else if (exp[i] == LEFT_B)
			op_stack.push("(");
		else if (exp[i] == RIGHT_B)
		{
			while (op_stack.top()[0] != LEFT_B)
			{
				res_stack.push(op_stack.top());
				op_stack.pop();
				if (op_stack.empty()){
					cout << SYN_ERROR << exp[i] << endl;
					return queue<string>();
				}
			}
			if (!op_stack.empty())
			{
				if (op_stack.top()[0] != LEFT_B){
					cout << SYN_ERROR << endl;
					return queue<string>();
				}
				op_stack.pop();
			}
		}
	}
	while (!op_stack.empty())
	{
		res_stack.push(op_stack.top());
		op_stack.pop();
	}
	return res_stack;
}