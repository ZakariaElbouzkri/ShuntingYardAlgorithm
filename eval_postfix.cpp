/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_postfix.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 05:39:45 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/05/26 06:29:23 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Eval.hpp"

int	calc(int n1, int n2, char op)
{
	int res;
	if (op == '-')
		return (n1 - n2);
	else if (op == '+')
		return (n1 + n2);
	else if (op == '*')
		return (n1 * n2);
	return (n1 / n2);
}


int	eval_postfix(queue <string> pfix, int *ret)
{
	stack<int> res;
	string token;

	int	num1;
	int num2;

	// print_post(pfix);
	while (!pfix.empty())
	{
		token = pfix.front();
		if (isdigit(token[0])){
			res.push(stoi(token));
			pfix.pop();
		}
		else if (is_operand(token[0]))
		{
			if (res.size() < 2) {
				cout << SYN_ERROR << token << endl;
				return (*ret = 0);
			}
			num2 = res.top();
			res.pop();
			num1 = res.top();
			res.pop();
			if (token[0] == '/' && !num2) {
				cout << SYN_ERROR << "Zero Devisions Error" << endl;
				return (*ret = 0);
			}
			res.push((calc(num1, num2, token[0])));
			pfix.pop();
		}
	}
	if (res.size() != 1) {
		cout << SYN_ERROR << endl;
		return (*ret = 0);
	}
	return (*ret = 1, res.top());
}