

#include "parser.h"


int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

void get_string_with(char *inpute, char *str, int   *i, int    *j)
{
    if (inpute[*i] == 34)
    {
        while (inpute[*i] == 34 && inpute[*i])
            str[(*j)++] = inpute[(*i)++];
    }    
    if (inpute[*i] == 39)
    {
        while (inpute[*i] == 39 && inpute[*i])
            str[(*j)++] = inpute[(*i)++];
    }
    while (inpute[*i] != 32 && inpute[*i] != '\t' && inpute[*i] != '|' && inpute[*i] != '<' 
    && inpute[*i] != '>' && inpute[*i])
        str[(*j)++] = inpute[(*i)++];
}

void get_string_with_quotes(char *inpute, char *str, int *i)
{
    int j;

    j = 0;
    if (inpute[*i] == 34)
    {
        while (inpute[*i] == 34 && inpute[*i])
            str[j++] = inpute[(*i)++];
        while (inpute[*i] != 34 && inpute[*i])
            str[j++] = inpute[(*i)++];
    }
    if (inpute[*i] == 39)
    {
        while (inpute[*i] == 39 && inpute[*i])
            str[j++] = inpute[(*i)++];
        while (inpute[*i] != 39 && inpute[*i])
            str[j++] = inpute[(*i)++];
    }
    get_string_with(inpute, str, i, &j);
    // if (inpute[*i] ==)
    str[j] = 0;
}

void get_string_with_operation(char *inpute, char *str, int *i)
{
    int j;

    j = 0;
    if (inpute[*i] == '|')
    {
        while (inpute[*i] == '|' && inpute[*i])
            str[j++] = inpute[(*i)++];
        str[j] = 0;
        return ;        
    }
    if (inpute[*i] == '>')
    {
        while (inpute[*i] == '>' && inpute[*i])
            str[j++] = inpute[(*i)++];
        str[j] = 0;
        return ;
    }
    if (inpute[*i] == '<')
    {
        while (inpute[*i] == '<' && inpute[*i])
            str[j++] = inpute[(*i)++];
        str[j] = 0;
        return ;
    }
}

void    get_string_with_dollar(char *inpute, char *str, int *i)
{
    int j;

    j = 0;
    while (inpute[*i] == '$' && inpute[*i])
        str[j++] = inpute[(*i)++];
    while (inpute[*i] != 32 && inpute[*i] != '\t' && inpute[*i] != '>' && inpute[*i] != '<' 
        && inpute[*i] != '|' && inpute[*i] && inpute[*i] != 34 && inpute[*i] != 39)
        str[j++] = inpute[(*i)++];
    str[j] = 0;
}

void    tmjnina(char *inpute, char *str, int *j, int *i)
{
    if (inpute[*i] == 34)
    {
        while (inpute[*i] == 34 && inpute[*i]) 
            str[(*j)++] = inpute[(*i)++];
        while (inpute[*i] != 34 && inpute[*i] != '|' && inpute[*i] != '<' 
            && inpute[*i] != '>' && inpute[*i])
            str[(*j)++] = inpute[(*i)++];
    }
    if (inpute[*i] == 39)
    {
        while (inpute[*i] == 39 && inpute[*i]) 
            str[(*j)++] = inpute[(*i)++];
        while (inpute[*i] != 39 && inpute[*i] != '|' && inpute[*i] != '<' 
            && inpute[*i] != '>' && inpute[*i])
            str[(*j)++] = inpute[(*i)++];
    }
}

void get_string(char *inpute, char *str, int *i)
{
    int j;

    j = 0;
    if (inpute[*i] == '|' || inpute[*i] == '<' || inpute[*i] == '>')
    {
        if (inpute[*i] == '|' || inpute[*i] == '<' || inpute[*i] == '>')
            get_string_with_operation(inpute, str, i);
        return ;
    }
    while (inpute[*i] != 32 && inpute[*i] != '\t' && inpute[*i] != '|' 
        && inpute[*i] != '<' && inpute[*i] != '>' && inpute[*i])
    {
        str[j++] = inpute[(*i)++];
        if (inpute[*i] == 34 || inpute[*i] == 39)
            tmjnina(inpute, str, &j, i);
    }
    str[j] = 0;
}

void    leading_word(char *inpute, char *str, int *i)
{
    while (inpute[*i] == 32 || inpute[*i] == '\t')
        (*i)++;
    if (inpute[*i] == 34 || inpute[*i] == 39)
    {
        get_string_with_quotes(inpute, str, i);
        return ;
    }
    if (inpute[*i] != 32 && inpute[*i] != '\t' && inpute[*i])
        get_string(inpute, str, i);
}

t_token *create_node(t_token    *tmp, char  *str)
{
    tmp = malloc(sizeof(t_token));
    if (!tmp)
        exit (0);
    tmp->inpute = str;
    tmp->next = NULL;
    return (tmp);
}

t_token *create_list(t_token *token, t_token *node)
{
    t_token *tmp;

    tmp = token;
    if (!token)
    {
        token = node;
        return (token);
    }
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = node;
    return (token);
}
t_token *tokenization(char *inpute)
{
    t_token *token;
    t_token *tmp;
    char *str;
    int i;

    i = 0;
    token = NULL;
    while (inpute[i])
    {
        str = malloc(sizeof(char *) + 1);
        leading_word(inpute, str, &i);
        tmp = create_node(token, str);
        // if (token->flag == 1)
        //     tmp->type = DOUBLE_QUOTES;
        // if (token->flag == 2)
        //     tmp->type = SIGLE_QUOTES;
        token = create_list(token, tmp);
    }
    return (token);
}

int ft_strcmp(char *inpute, char *str)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (inpute[i] || str[j])
    {
        if (inpute[i] != str[j])
            return (0);
        i++;
        j++;
    }
    return (1);
}

void    define_type(t_token *token)
{
    int i;
    int j;

    i = 0;
    j = ft_strlen(token->inpute);
    if (token->inpute[0] == 34 && token->inpute[j - 1] == 34)
        token->type = DOUBLE_QUOTES;
    if (token->inpute[0] == 39 && token->inpute[j - 1] == 39)
        token->type = SIGLE_QUOTES;
    if (token->inpute[0] == '$')
        token->type = DOLLAR;
    // else
    //     token->type = T_WORD;
    if (token->inpute[0] != '>' && token->inpute[0] != '<' && token->inpute[0] != '|' && token->inpute[0] != '$')
        if ((token->inpute[0] != 34 || token->inpute[j - 1] != 34) 
        && (token->inpute[0] != 39 || token->inpute[j - 1] != 39))
            token->type = T_WORD;
}

void define_types(t_token *token)
{
    int i;
    t_token *tmp;

    tmp = token;
    while (tmp != NULL)
    {
        if (ft_strcmp(tmp->inpute, "|") == 1)
            tmp->type = PIPE;
        if (ft_strcmp(tmp->inpute, ">") == 1)
            tmp->type = RIGHT_FLESH;
        if (ft_strcmp(tmp->inpute, "<") == 1)
            tmp->type = LEFT_FLESH;
        if (ft_strcmp(tmp->inpute, ">>") == 1)
            tmp->type = DOUBLE_RIGHT_FLESH;
        if (ft_strcmp(tmp->inpute, "<<") == 1)
            tmp->type = DOUBLE_LEFT_FLESH;
        tmp = tmp->next;   
    }
    while (token)
    {
        define_type(token);
        token = token->next;
    }
}
