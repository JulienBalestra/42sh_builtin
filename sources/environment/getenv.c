#include <stdlib.h>
#include <unistd.h>

#include "env_builder.h"
#include "../libft/includes/libft.h"

/*
 * Browse the linked list env to find the link by key
 * Return the value of the link
 */
char		*get_env_value(char *name, t_env *env)
{
	while (env)
	{
		if (ft_strcmp(name, env->key) == 0)
		{
			return (env->value);
		}
		env = env->next;
	}
	return (NULL);
}

/*
 * Getenv with argument checking
 */
void		builtin_getenv(char **command, t_env *env)
{
	char	*value;

	if (ft_str2len(command) < 2)
		return ;
	else if (ft_str2len(command) != 2)
	{
		ft_putendl_fd("getenv: too many arguments", 2);
		return ;
	}
	if ((value = get_env_value(command[1], env)))
	{
		ft_putstr(value);
	}
	ft_putstr("\n");
}