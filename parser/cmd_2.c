/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:43:22 by isouaidi          #+#    #+#             */
/*   Updated: 2024/05/18 16:47:31 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_pars	*in_list(t_pars *current, t_pars	*new_redirection)
{
	new_redirection = malloc(sizeof(t_pars));
	new_redirection->tokken = current->tokken;
	new_redirection->val = ft_strdup(current->val);
	new_redirection->next = malloc(sizeof(t_pars));
	new_redirection->next->tokken = current->next->tokken;
	new_redirection->next->val = ft_strdup(current->next->val);
	new_redirection->next->next = NULL;
	return (new_redirection);
}

t_pars	*in_list3(t_cmd *cmd, t_pars *cur, t_pars *redi)
{
	t_pars	*temp;

	redi = malloc(sizeof(t_pars));
	redi->tokken = cur->tokken;
	redi->val = ft_strdup(cur->val);
	redi->next = malloc(sizeof(t_pars));
	redi->next->tokken = cur->next->tokken;
	redi->next->val = ft_strdup(cur->next->val);
	redi->next->next = NULL;
	if (cmd->redirections == NULL)
		cmd->redirections = redi;
	else
	{
		temp = cmd->redirections;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = redi;
	}
	return (redi);
}

void	add_val_to_cmd(t_cmd *ncmd, t_pars *current, int *i)
{
	ncmd->val[*i] = ft_strdup(current->val);
	(*i)++;
}

t_pars	*racc(int *i, t_pars *current, t_cmd *ncmd, t_pars *redi)
{
	if (current->tokken > 1)
	{
		redi = in_list3(*(&ncmd), *(&current),
				*(&redi));
		current = current->next;
	}
	else
		add_val_to_cmd(ncmd, current, *(&i));
	current = current->next;
	return (current);
}
