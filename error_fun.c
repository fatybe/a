/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_fun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenjama <fbenjama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 19:20:56 by fbenjama          #+#    #+#             */
/*   Updated: 2025/07/11 19:24:28 by fbenjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void    detect_error(t_token    *token)
{

    while (token)
    {
        if (token->inpute[0] == '|')
            if (ft_strlen(token->inpute) > 1)
            {
                printf("error\n");
                exit (0);
            }
        if (token->inpute[0] == '>')
            if (ft_strlen(token->inpute) > 2)
            {
                printf("error\n");
                exit (0) ;
            }
        if (token->inpute[0] == '<')
            if (ft_strlen(token->inpute) > 2)
            {
                printf("error\n");
                exit (0);
            }
        token = token->next;
    }
}

int detect_error3(t_token *token)
{
    int a;
    int b;
    int i;

    while (token)
    {
        a = 0;
        b = 0;
        i = 0;
        if (token->type == T_WORD)
            while (token->inpute[i])
            {
                if (token->inpute[i] == 34 )
                    a++;
                if (token->inpute[i] == 39)
                    b++;
                i++;
            }
        if (a% 2 != 0 || b % 2 != 0)
            return (1);
        token = token->next;
    }
    return (0);
}

int detect_error4(t_token *token)
{
    int a;
    int i;

    while (token)
    {
        a = 0;
        i = 0;
        if (token->type == SIGLE_QUOTES)
            while (token->inpute[i])
            {
                if (token->inpute[i] == 39)
                    a++;
                i++;
            }
        if (a % 2 != 0)
            return (1);
        token = token->next;
    }
    return (0);
}

int detect_error5(t_token   *token)
{
        int a;
    int i;

    while (token)
    {
        a = 0;
        i = 0;
        if (token->type == DOUBLE_QUOTES)
            while (token->inpute[i])
            {
                if (token->inpute[i] == 34)
                    a++;
                i++;
            }
        if (a % 2 != 0)
            return (1);
        token = token->next;
    }
    return (0);
}

void detect_error2(t_token  *token)
{
    t_token *tmp;
    int a;
    int b;

    tmp = token;
    while (tmp->next)
        tmp = tmp->next;
    if (token->type == PIPE || token->type == LEFT_FLESH || token->type == DOUBLE_LEFT_FLESH
        || tmp->type == PIPE || tmp->type == LEFT_FLESH || tmp->type == RIGHT_FLESH 
        || tmp->type == DOUBLE_LEFT_FLESH || tmp->type == DOUBLE_RIGHT_FLESH)
    {
        printf("ERROR\n");
        // exit(0);
    }
    if (detect_error3(token) == 1 || detect_error4(token) == 1 || detect_error5(token) == 1)
    {
        printf("ERROR\n");
        // exit(0);
    }
}

