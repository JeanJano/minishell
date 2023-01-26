/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_define.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by rvincent          #+#    #+#             */
/*   Updated: 2023/01/05 18:35:07 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_DEFINE_H
# define MINISHELL_DEFINE_H

# include "./libft/libft.h"
# include "./minishell.h"
# include <linux/limits.h>
// # include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <signal.h>
# include <termios.h>
# include <term.h>

# define WORD 0 // file name ou command ou argument
# define PIPE 1 // pipe
# define REDIR_IN 2 // <
# define REDIR_OUT 3 // >
# define HERE_DOC 4 // <<
# define APP_OUT 5 // >>
# define TRUE 1
# define FALSE 0

typedef struct a_list
{
	char			*content;
	char			*content2;
	struct a_list	*next;
}					t_array_lst;

typedef struct m_list
{
	void			*adr;
	struct m_list	*next;
}					t_mal_lst;

typedef struct l_list
{
	char			*content;
	int				operator;
	struct l_list	*next;
}					t_lex_lst;

typedef struct env_list
{
	char			*name;
	char			*value;
	struct env_list	*next;
}					t_env_lst;

typedef struct t_list
{
	t_array_lst		*args;

	int				input_fd;
	t_array_lst		*in_file;
	t_array_lst		*delimiter;
	int				output_fd;
	t_array_lst		*out_file;
	struct t_list	*next;
}					t_tok_lst;

typedef struct e_list
{
	char			*readline_str;

	pid_t			*pid;
	int				pipe_fd[2];
	int				stdin_fd;

	t_lex_lst		*lex_lst;
	t_tok_lst		*tok_lst;
	t_env_lst		*env_lst;
	t_mal_lst		*mal_lst;
	t_array_lst		*here_doc_lst;

	int				nb_command;
}					t_exec;

#endif
