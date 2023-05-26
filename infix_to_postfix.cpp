/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infix_to_postfix.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 05:33:18 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/05/26 10:26:46 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Eval.hpp"
using namespace std;


static queue<string>	put_error(char c)
{
	cout << SYN_ERROR << 'sdsd';
	cout << RESET<< endl;
	return queue<string>();
}

void	push_operand(stack<string>& op_stack, queue<string>& que, map<char, int> prec, string op)
{
	char	op1;
	char	op2;

	if (op_stack.empty())
	{
		op_stack.push(op);
		return ;
	}
	op1 = op[0];
	op2 = op_stack.top()[0];
	if (op2 == LEFT_B || op2 == RIGHT_B){
		op_stack.push(op);
		return ;
	}
	while (!op_stack.empty() && (op2 != LEFT_B && op2 != RIGHT_B) && prec[op1] <= prec[op2])
	{
		que.push(op_stack.top());
		op_stack.pop();
		if (!op_stack.empty())
			op2 = op_stack.top()[0];
	}
	op_stack.push(op);
}

void	push_num(queue<string>& que, string& exp, int& i)
{
	string	num;

	while (i < exp.size() && isdigit(exp[i]))
		num.push_back(exp[i++]);
	i--;
	que.push(num);
}

int	push_brackets(stack<string>& op_stack, queue<string>& que)
{
	while (!op_stack.empty())
	{
		if (op_stack.top()[0] == LEFT_B)
		{
			op_stack.pop();
			return (1);
		}
		que.push(op_stack.top());
		op_stack.pop();
	}
	return (0);
}
queue<string>	infix_to_postfix(string exp, map<char, int> prec)
{
	stack<string>	op_stack;
	queue<string>	res_queue;

	for (int i=0; i<exp.size(); i++)
	{
		if (!is_token(exp[i])  && exp[i] != LEFT_B && exp[i] != RIGHT_B)
			return (put_error(exp[i]));
		else if (is_operand(exp[i]))
		{
			string	op;
			op.push_back(exp[i]);
			push_operand(op_stack, res_queue, prec, op);
		}
		else if (isdigit(exp[i]))
			push_num(res_queue, exp, i);
		else if (exp[i] == LEFT_B)
			op_stack.push("(");
		else if (exp[i] == RIGHT_B)
		{
			if (!push_brackets(op_stack, res_queue))
				return (put_error(exp[i]));
		}
	}
	while (!op_stack.empty())
	{
		res_queue.push(op_stack.top());
		op_stack.pop();
	}
	return res_queue;
}
