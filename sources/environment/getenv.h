#ifndef PROJECT_GETENV_H
#define PROJECT_GETENV_H

/*
 * getenv.c
 */
char		*get_env_value(char *name, t_env *env);
void		builtin_getenv(char **command, t_sh *shell);

#endif //PROJECT_GETENV_H
