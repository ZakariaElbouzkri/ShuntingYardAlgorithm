/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 01:15:44 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/05/26 10:40:01 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Eval.hpp"

using namespace std;

void	display_results(string infix, queue<string> postfix, int res)
{
	// display infix result
	cout << BOLDCYAN << "infix :\t\t";
	cout << BOLDWHITE << infix << endl;
	
	// display postfix result
	cout << BOLDGREEN << "postfix :\t" << BOLDWHITE;
	while (!postfix.empty())
	{
		cout << postfix.front() << ' ';
		postfix.pop();
	}
	cout << endl;
	
	// display result
	cout << MAGENTA << "result :\t" << BOLDWHITE << res;
	cout << RESET << endl;
}


int main()
{
	char			*infix;
	int				res;
	queue<string>	postfix;
	int				triger;
	map<char, int>	prec;

	init_precedence(prec);
	while (true)
	{
		infix = readline(PROMPT);
		if (!infix || !strcmp(infix, "exit"))
			return (0);
		postfix = infix_to_postfix(infix, prec);
		if (postfix.empty())
			continue;
		else
		{
			res = eval_postfix(postfix, triger);
			if (!triger)
				continue;
			display_results(infix, postfix, res);
		}
		add_history(infix);
	}
}
