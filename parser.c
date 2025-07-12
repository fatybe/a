#include "parser.h"

t_list *splite_tokens(t_token   *token)
{
    t_list *list;

    while (list)
    {
        
    }
}

int main()
{
    char *inpute;
    t_token *token;
    t_list  *list;
    int n;

    while (1)
    {
        inpute = readline("minishell :");
        token = tokenization(inpute);
        detect_error(token);
        define_types(token);
        detect_error2(token);
        list = splite_tokens(token);
        t_token *tmp = token;
        while (tmp)
        {
            printf("[ %s ]", tmp->inpute);
            tmp = tmp->next;
        }
        printf("\n");
    }
}
