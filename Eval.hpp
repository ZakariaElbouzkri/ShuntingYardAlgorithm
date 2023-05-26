/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Eval.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 04:58:18 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/05/26 06:04:19 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVAL_HPP
#define EVAL_HPP

#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>
#include <readline/readline.h>

#define LEFT_B '('
#define RIGHT_B ')'

using namespace std;

// ANSI color codes
#define RESET        "\033[0m"
#define BLACK        "\033[30m"
#define RED          "\033[31m"
#define GREEN        "\033[32m"
#define YELLOW       "\033[33m"
#define BLUE         "\033[34m"
#define MAGENTA      "\033[35m"
#define CYAN         "\033[36m"
#define WHITE        "\033[37m"
#define BOLDBLACK    "\033[1m\033[30m"
#define BOLDRED      "\033[1m\033[31m"
#define BOLDGREEN    "\033[1m\033[32m"
#define BOLDYELLOW   "\033[1m\033[33m"
#define BOLDBLUE     "\033[1m\033[34m"
#define BOLDMAGENTA  "\033[1m\033[35m"
#define BOLDCYAN     "\033[1m\033[36m"
#define BOLDWHITE    "\033[1m\033[37m"



#define PROMPT "\033[33mEnter Mathematic Expression : \033[0m"
#define SYN_ERROR "\033[31mSyntax Error "

bool	is_operand(char c);
bool	is_token(char c);

queue<string>	infix_to_postfix(string exp, map<char, int> prec);
int	eval_postfix(queue <string> pfix, int *ret);

#endif
