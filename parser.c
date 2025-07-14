#include "parser.h"

// void    get_arguments(t_list  *list, t_token *token)
// {
//     int i;

//     while (token && token->type != DOUBLE_LEFT_FLESH && token->type != DOUBLE_RIGHT_FLESH && 
//     token->type != RIGHT_FLESH && token->type != LEFT_FLESH)
//     {
//         i = 0;
//         while (token->inpute[i])
//         {
//             list->argument[i] = token->inpute[i];
//             i++;
//         }
//         list->argument[i] = 32;
//         token = token->next;
//     }
//     list->argument = 0;
// }

// t_list  *splite_tokens(t_token  *token)
// {
//     t_list *list;

//     list = malloc(sizeof(t_list));
//     if (!list)
//         exit (0);
//     if (token->type != RIGHT_FLESH && token->type != LEFT_FLESH 
//         && token->type != DOUBLE_LEFT_FLESH && token->type != DOUBLE_RIGHT_FLESH)
//     {
//         printf("wakwak\n");
//         list->command = token->inpute;
//         token = token->next;
//     }
//     get_arguments(list, token);
//     return (list);
// }

void    get_argument(t_token *token, char *str)
{
    int i;
    int j;

    i = 0;
    while (token && token->type != DOUBLE_LEFT_FLESH && token->type != DOUBLE_RIGHT_FLESH && 
    token->type != RIGHT_FLESH && token->type != LEFT_FLESH && token->type != PIPE)
    {
        j = 0;
        while (token->inpute[j])
            str[i++] = token->inpute[j++];
        str[i++] = 32;
        token = token->next;
    }
    str[j] = 0;
}

void get_node(t_list *list, t_token *token)
{
    char *str;

    str = malloc(sizeof)
    while ()
}

t_list *split_token(t_token *token)
{
    t_list *list;

    while (token)
    {
        list = malloc(sizeof(t_list));
        if (!list)
            exit (0);
        get_node(list, token);
        while (token->type != PIPE && token)
            token->next;
        if (token->type == PIPE)
            token = token->next;
    }
    return (list);
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
        // list = splite_tokens(token);
        t_token *tmp = token;
        while (tmp)
        {
            printf("[ %s ]", tmp->inpute);
            tmp = tmp->next;
        }
        printf("\n");
        printf("\n");
    }
}
