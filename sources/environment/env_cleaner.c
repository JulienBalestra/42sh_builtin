#include <stdlib.h>

#include "env_cleaner.h"
#include "env_builder.h"

void	delete_env_list(t_env **env)
{
	t_env *current;

	while (*env)
	{
		current = (*env)->next;
		remove_link(*env);
		*env = current;
	}
}

void	remove_link(t_env *link)
{
	if (link)
	{
		free(link->key);
		link->key = NULL;
		free(link->value);
		link->value = NULL;
		free(link);
	}
}