/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 05:03:02 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/05/26 08:50:51 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Eval.hpp"

bool	is_operand(char c)
{
	return (c == '/' || c == '*' || c == '-' || c == '+'); 
}


bool	is_token(char c)
{
	return (is_operand(c) || isdigit(c) || c == ' ');
}

void	init_precedence(map<char, int>& prec)
{
	prec['+'] = 1;
	prec['-'] = 1;
	prec['/'] = 2;
	prec['*'] = 2;
}
