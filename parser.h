#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
typedef enum e_type
{
    T_WORD = 0,
    SIGLE_QUOTES = 1,
    DOUBLE_QUOTES = 2,
    RIGHT_FLESH = 3,
    LEFT_FLESH = 4,
    PIPE = 5,
    DOUBLE_LEFT_FLESH = 6,
    DOUBLE_RIGHT_FLESH = 7,
    DOLLAR = 8
}t_type;

typedef struct token
{
    int flag;
    char *inpute;
    struct token *next;
    t_type type;
}t_token;

typedef struct list
{
    char *command;
    char *argument;
    char *inpute_file;
    char *outpute_file;
    struct list *pipe_next;
}t_list;

void    detect_error(t_token    *token);
void detect_error2(t_token  *token);
int detect_error3(t_token *token);
int detect_error4(t_token *token);
int detect_error5(t_token   *token);
t_token *tokenization(char *inpute);
void define_types(t_token *token);
void get_string_with_quotes(char *inpute, char *str, int *i);
void get_string_with_operation(char *inpute, char *str, int *i);
void get_string(char *inpute, char *str, int *i);
void    leading_word(char *inpute, char *str, int *i);
t_token *create_node(t_token    *tmp, char  *str);
t_token *create_list(t_token *token, t_token *node);
void get_string_with(char *inpute, char *str, int   *i, int    *j);
void    get_string_with_dollar(char *inpute, char *str, int *i);
int ft_strlen(char *str);
int ft_strcmp(char *inpute, char *str);

#endif