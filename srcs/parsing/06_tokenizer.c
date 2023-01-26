/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_tokenizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by rvincent          #+#    #+#             */
/*   Updated: 2022/12/09 19:26:26 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_token(t_tok_lst	**token_head, t_tok_lst	**token_new, t_exec *exec)
{
	lstadd_back_token(token_head, *token_new);
	*token_new = lstnew_token(exec);
}

t_tok_lst	*get_token_lst(t_exec *exec)
{
	t_tok_lst	*token_head;
	t_tok_lst	*token_new;

	token_head = NULL;
	token_new = lstnew_token(exec);
	while (exec->lex_lst)
	{
		if (exec->lex_lst->operator == PIPE)
		{
			add_token(&token_head, &token_new, exec);
			exec->lex_lst = exec->lex_lst->next;
		}
		else if (exec->lex_lst->operator == HERE_DOC)
			add_here_doc(&token_new, &exec->lex_lst, exec);
		else if (exec->lex_lst->operator == REDIR_IN)
			add_redir_in(&token_new, &exec->lex_lst, exec);
		else if (exec->lex_lst->operator == REDIR_OUT)
			add_redir_out(&token_new, &exec->lex_lst, exec);
		else if (exec->lex_lst->operator == APP_OUT)
			add_app_out(&token_new, &exec->lex_lst, exec);
		else if (exec->lex_lst->operator == WORD)
			add_word(&token_new, &exec->lex_lst, exec);
	}
	lstadd_back_token(&token_head, token_new);
	return (token_head);
}
