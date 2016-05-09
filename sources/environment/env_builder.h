#ifndef INC_42SH_BUILTIN_ENV_H
#define INC_42SH_BUILTIN_ENV_H

#define BUF_CWD_SIZE	2048

/*
 * Linked list for environment stored with Key / Value
 * e.g. key = PATH, value = /bin:/usr/bin
 */
typedef struct		s_env
{
	struct s_env	*next;
	struct s_env	*prev;
	char			*key;
	char			*value;
}					t_env;

/*
 * env_builder.c
 */
t_env				*build_env_list(char **environ);
t_env				*build_env_pwd(t_env *env);
t_env				*create_env_link(t_env *env, char *environ_entry);
t_env				*manage_empty_environ(void);

/*
 * env_builder_fn1.c
 */
int					len_until_char(char *str, char c);
t_env				*get_start(t_env *env);
t_env				*get_end(t_env *env);

#endif
