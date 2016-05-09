#include <stdlib.h>
#include <unistd.h>

#include "env_builder.h"
#include "../libft/includes/libft.h"


/*
 * Create the linked list with all entries inside environ
 * except the OLDPWD who's ignored and
 * always create a list with PWD
 */
t_env		*build_env_list(char **environ)
{
	t_env	*env;
	int		i;

	env = NULL;
	i = 0;
	if (ft_str2len(environ) == 0)
		env = manage_empty_environ();
	else
	{
		while (*environ)
		{
			if (ft_strncmp("PWD=", *environ, 4) == 0)
				i = 1;
			if (ft_strncmp("OLDPWD", *environ, 6) != 0)
				env = create_env_link(env, *environ);
			environ++;
		}
		if (i == 0)
			env = build_env_pwd(env);
	}
	return (get_start(env));
}

/*
 * Create the PWD entry with getcwd(3)
 */
t_env		*build_env_pwd(t_env *env)
{
	char	*buf_wd;
	char	*tmp;
	t_env	*new_env;

	new_env = NULL;
	if ((buf_wd = (char *)malloc(sizeof(char) * BUF_CWD_SIZE)))
	{
		buf_wd = getcwd(buf_wd, BUF_CWD_SIZE);
		tmp = ft_strjoin("PWD=", buf_wd);
		free(buf_wd);
		new_env = create_env_link(env, tmp);
		free(tmp);
	}
	return (new_env);
}

/*
 * Create a link from an string like PATH=/bin
 * key == PATH / value == /bin
 * Append at the end of the list, return the current link
 */
t_env		*create_env_link(t_env *env, char *environ_entry)
{
	t_env	*link;
	int		len_until;

	if ((link = (t_env *)malloc(sizeof(t_env))))
	{
		len_until = len_until_char(environ_entry, '=');
		link->key = ft_strndup(environ_entry, (size_t)len_until);
		environ_entry = &environ_entry[len_until + 1];
		link->value = ft_strdup(environ_entry);
		link->next = NULL;
		if (env)
		{
			link->prev = env;
			env->next = link;
		}
		else
			link->prev = NULL;
		return (link);
	}
	return (NULL);
}

/*
 * Create an entry for PWD to get a non null environment
 */
t_env	*manage_empty_environ(void)
{
	char	*buf_pwd;
	char	*string;
	t_env	*env;

	env = NULL;
	if ((buf_pwd = (char *)malloc(sizeof(char) * BUF_CWD_SIZE)))
	{
		string = ft_strjoin("PWD=", getcwd(buf_pwd, BUF_CWD_SIZE));
		env = create_env_link(env, string);
		free(buf_pwd);
		free(string);
	}
	return (env);
}