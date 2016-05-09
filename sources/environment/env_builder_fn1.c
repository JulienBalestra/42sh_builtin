
/*
 * Inside a string, get the number of characters
 * until reach the first char c
 */
int		len_until_char(char *str, char c)
{
	int	i;

	i = 0;
	while (str && str[i] && str[i] != c)
		i++;
	return (i);
}

/*
 * Get the first link
 */
t_env	*get_start(t_env *env)
{
	while (env)
	{
		if (env->prev)
			env = env->prev;
		else
			break ;
	}
	return (env);
}

/*
 * Get the last link
 */
t_env	*get_end(t_env *env)
{
	while (env)
	{
		if (env->next)
			env = env->next;
		else
			break ;
	}
	return (env);
}