/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_tokenizer_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by rvincent          #+#    #+#             */
/*   Updated: 2022/12/05 18:22:19 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_here_doc(t_tok_lst **token, t_lex_lst **lex_lst, t_exec *exec)
{
	t_array_lst	*new_array;

	(*token)->input_fd = HERE_DOC;
	*lex_lst = (*lex_lst)->next;
	new_array = lstnew_array((*lex_lst)->content, exec);
	lstadd_back_array(&(*token)->delimiter, new_array);
	*lex_lst = (*lex_lst)->next;
}

void	add_redir_in(t_tok_lst **token, t_lex_lst **lex_lst, t_exec *exec)
{
	t_array_lst	*new_array;

	(*token)->input_fd = REDIR_IN;
	*lex_lst = (*lex_lst)->next;
	new_array = lstnew_array((*lex_lst)->content, exec);
	lstadd_back_array(&(*token)->in_file, new_array);
	*lex_lst = (*lex_lst)->next;
}

void	add_redir_out(t_tok_lst **token, t_lex_lst **lex_lst, t_exec *exec)
{
	t_array_lst	*new_array;

	(*token)->output_fd = REDIR_OUT;
	*lex_lst = (*lex_lst)->next;
	new_array = lstnew_array((*lex_lst)->content, exec);
	new_array->content2 = "O_TRUNC";
	lstadd_back_array(&(*token)->out_file, new_array);
	*lex_lst = (*lex_lst)->next;
}

void	add_app_out(t_tok_lst **token, t_lex_lst **lex_lst, t_exec *exec)
{
	t_array_lst	*new_array;

	(*token)->output_fd = APP_OUT;
	*lex_lst = (*lex_lst)->next;
	new_array = lstnew_array((*lex_lst)->content, exec);
	new_array->content2 = "O_APPEND";
	lstadd_back_array(&(*token)->out_file, new_array);
	*lex_lst = (*lex_lst)->next;
}

void	add_word(t_tok_lst **token, t_lex_lst **lex_lst, t_exec *exec)
{
	t_array_lst	*new_array;

	new_array = lstnew_array((*lex_lst)->content, exec);
	lstadd_back_array(&(*token)->args, new_array);
	*lex_lst = (*lex_lst)->next;
}
