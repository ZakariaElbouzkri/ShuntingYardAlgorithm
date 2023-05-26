/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 01:15:44 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/05/26 06:05:00 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Eval.hpp"
using namespace std;

int main()
{
	char	*infix;
	int		res;
	queue<string> postfix;
	int triger = 1;
	map<char, int> prec;

	// init prec map
	prec['+'] = 1;
	prec['-'] = 1;
	prec['/'] = 2;
	prec['*'] = 2;

	while (true)
	{
		infix = readline(PROMPT);
		if (!infix)
			return (1);
		postfix = infix_to_postfix(infix, prec);
		res = eval_postfix(postfix, &triger);
		if (!triger)
			continue;
		// display result
		cout << endl << BOLDCYAN << cout << "Infix: " <<  BOLDWHITE << infix << RESET << endl << endl;
		cout << BOLDGREEN << "Postfix: " << BOLDWHITE;
		while (!postfix.empty())
		{
			cout << postfix.front() << " ";
			postfix.pop();
		}
		cout << RESET << endl << endl;
		cout << MAGENTA  << "Resul : " << res << RESET << endl << endl;
		add_history(infix);
	}
}
