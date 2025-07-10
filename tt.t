// #include "parser.h"

// void detect_error(char *inpute)
// {
//     int i;
//     int a;
//     int b;

//     a = 0;
//     b = 0;
//     i = 0;
//     while (inpute[i])
//     {
//         if (inpute[i] == 34)
//             a++;
//         if (inpute[i] == 39)
//             b++;
//         if (inpute[i] == 92)
//             printf("command not found\n");
//         if (inpute[i] == 59)
//             printf("command not found\n");
//         i++;
//     }
//     if (a % 2 != 0 || b % 2 != 0)
//         printf("command not found\n");
// }

// void get_string_with_quotes(char *inpute, char *str, int *i)
// {
//     int j;

//     j = 0;
//     if (inpute[*i] == 34)
//     {
//         while (inpute[*i] == 34 && inpute[*i])
//             (*i)++;
//         while (inpute[*i] != 34 && inpute[*i])
//             str[j++] = inpute[(*i)++];
//         while (inpute[*i] == 34 && inpute[*i])
//             (*i)++;
//     }
//     if (inpute[*i] == 39)
//     {
//         while (inpute[*i] == 39 && inpute[*i])
//             (*i)++;
//         while (inpute[*i] != 39 && inpute[*i])
//             str[j++] = inpute[(*i)++];
//         while (inpute[*i] == 39 && inpute[*i])
//             (*i)++;
//     }
// }

// void get_string_with_operation(char *inpute, char *str, int *i)
// {
//     int j;

//     j = 0;
//     if (inpute[*i] == '|')
//         while (inpute[*i] == '|' && inpute[*i])
//             str[j++] = inpute[(*i)++];
//     if (inpute[*i] == '>')
//         while (inpute[*i] == '>' && inpute[*i])
//             str[j++] = inpute[(*i)++];
//     if (inpute[*i] == '<')
//         while (inpute[*i] == '>' && inpute[*i])
//             str[j++] = inpute[(*i)++];
// }

// void get_string(char *inpute, char *str, int *i)
// {
//     int j;

//     j = 0;
//     if (inpute[*i] == '|' || inpute[*i] == '<' || inpute[*i] == '>')
//     {
//         get_string_with_operation(inpute, str, i);
//         return ;
//     }
//     while (inpute[*i] == 32 && inpute[*i] == '\t' && inpute[*i] != '|' && inpute[*i] != '<' 
//     && inpute[*i] != '>' && inpute[*i])
//         str[j++] = inpute[(*i)++];
// }

// void    leading_word(char *inpute, char *str, int *i)
// {
//     while (inpute[*i] == 32 || inpute[*i] == '\t')
//         (*i)++;
//     if (inpute[*i] == '\"' || inpute[*i] == '\'')
//         get_string_with_quotes(inpute, str, i);
//     if (inpute[*i] == 32 && inpute[*i] == '\t')
//         get_string(inpute, str, i);
// }

// t_token *create_node(t_token    *tmp, char  *str)
// {
//     tmp = malloc(sizeof(t_token));
//     if (!tmp)
//         exit (0);
//     tmp->inpute = str;
//     tmp->next = NULL;
//     return (tmp);
// }

// t_token *create_list(t_token *token, t_token *node)
// {
//     t_token *tmp;

//     tmp = token;
//     if (!token)
//     {
//         token = node;
//         return (token);
//     }
//     while (tmp->next != NULL)
//     {
//         tmp = tmp->next;
//     }
//     tmp->next = node;
//     return (token);
// }
// t_token *tokenization(char *inpute)
// {
//     t_token *token;
//     t_token *tmp;
//     char *str;
//     int i;

//     i = 0;
//     token = NULL;
//     while (inpute[i])
//     {
//         str = malloc(sizeof(char *) + 1);
//         leading_word(inpute, str, &i);
//         printf("%d\n", i);
//         tmp = create_node(token, str);
//         token = create_list(token, tmp);
//         printf("here\n");
//         // if (inpute[i] == 34)
//         // {
//         //     i++;
//         //     while (inpute[i] != 34 && inpute[i])
//         //         i++;
//         //     i++;
//         // }
//         // if (inpute[i] == 39)
//         // {
//         //     i++;
//         //     while (inpute[i] != 39 && inpute[i])
//         //         i++;
//         //     i++;
//         // }
//         // while (inpute[i] != 32 && inpute[i] != 34 && inpute[i] != 39 && inpute[i])
//         //     i++;
//         // while (inpute[i] == 32 && inpute[i])
//         //     i++;  
//     }
//     return (token);
// }

// // int ft_strcmp(char *inpute, char *str)
// // {
// //     int i;
// //     int j;

// //     i = 0;
// //     j = 0;
// //     while (inpute[i] || str[j])
// //     {
// //         if (inpute[i] != str[j])
// //             return (0);
// //         i++;
// //         j++;
// //     }
// //     return (1);
// // }

// // int is_alpha(char c)
// // {
// //     if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
// //         return (1);
// //     return (0);

// // }
// // void define_types(t_token *token)
// // {
// //     int i;
// //     t_token *tmp;

// //     tmp = token;
// //     while (tmp != NULL)
// //     {
// //         if (ft_strcmp(tmp->inpute, "|") == 1)
// //             tmp->type = PIPE;
// //         if (ft_strcmp(tmp->inpute, ">") == 1)
// //             tmp->type = RIGHT_FLESH;
// //         if (ft_strcmp(tmp->inpute, "<") == 1)
// //             tmp->type = LEFT_FLESH;
// //         if (ft_strcmp(tmp->inpute, ">>") == 1)
// //             tmp->type = DOUBLE_RIGHT_FLESH;
// //         if (ft_strcmp(tmp->inpute, "<<") == 1)
// //             tmp->type = DOUBLE_LEFT_FLESH;
// //         tmp = tmp->next;   
// //     }
// //     while (token)
// //     {
// //         if (token->inpute[0] == 34)
// //             token->type = DOUBLE_QUOTES;
// //         if (token->inpute[0] == 39)
// //             token->type = SIGLE_QUOTES;
// //         if (is_alpha(token->inpute[0]) == 1)
// //             token->type = T_WORD;
// //         token = token->next;
// //     }
// // }