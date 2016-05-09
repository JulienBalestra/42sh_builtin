#ifndef INC_42SH_BUILTIN_ENV_CLEANER_H
#define INC_42SH_BUILTIN_ENV_CLEANER_H

/*
 * env_cleaner.c
 */
void	delete_env_list(t_env **env);
void	remove_link(t_env *link);

#endif //INC_42SH_BUILTIN_ENV_CLEANER_H
