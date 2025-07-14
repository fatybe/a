#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
typedef enum e_type
{
    T_WORD,
    SIGLE_QUOTES,
    DOUBLE_QUOTES,
    RIGHT_FLESH,
    LEFT_FLESH,
    PIPE,
    DOUBLE_LEFT_FLESH,
    DOUBLE_RIGHT_FLESH,
    DOLLAR
}t_type;

typedef struct token
{
    int flag;
    char *inpute;
    struct token *next;
    t_type type;
}t_token;

typedef struct type
{
    output_redir,
    input_redir,
    heredoc,
    append_output_redir
}t_redir_type;

typedef struct 
{
    char *file;
    t_redir_type type;
}t_file;

typedef struct list
{
    char *arg;
    t_file *redir;
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