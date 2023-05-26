/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_postfix.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 05:39:45 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/05/26 10:40:33 by zel-bouz         ###   ########.fr       */
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

static	int	put_error(int& ret, string err)
{
	if (!err.empty()){
		cout << SYN_ERROR << err;
		cout << RESET << endl;
	}
	ret = 0;
	return (ret);
}

int	eval_postfix(queue <string> pfix, int& ret)
{
	stack<int>	res;
	string		token;
	int			num1;
	int			num2;

	while (!pfix.empty())
	{
		token = pfix.front();
		if (isdigit(token[0])){
			res.push(stoi(token));
			pfix.pop();
		}
		else if (is_operand(token[0]))
		{
			if (res.size() < 2)
				return (put_error(ret, token));
			num2 = res.top();
			res.pop();
			num1 = res.top();
			res.pop();
			if (token[0] == '/' && !num2)
				return (put_error(ret, "Zero Devisions Error"));
			res.push((calc(num1, num2, token[0])));
			pfix.pop();
		}
	}
	if (res.size() != 1) return (put_error(ret, ""));
	return (ret = 1, res.top());
}
