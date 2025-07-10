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

// int text_error(char *str)
// {
//     int i;

//     i = 0;
//     while (str[i])
//     {
//         if (str[i] == 34 || str[i] == 32 || str[i] ==)
//     }
// }



void detect_error2(t_token  *token)
{
    t_token *tmp;

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
}

int main()
{
    char *inpute;
    t_token *token;
    int n;

    while (1)
    {
        inpute = readline("minishell :");
        // if (detect_error(inpute) == 1);
        //     return (0);
        token = tokenization(inpute);
        t_token *tmp = token;
        // while (tmp)
        // {
        //     printf("%s\n", tmp->inpute);
        //     tmp = tmp->next;
        // }        
        detect_error(token);
        define_types(token);
        detect_error2(token);

    }
}
