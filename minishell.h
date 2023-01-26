/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:25:31 by jsauvage          #+#    #+#             */
/*   Updated: 2023/01/05 18:33:31 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./minishell_define.h"

extern int	g_status;

//----------------------------------------------------------------------------//
//						 			Utils				 					  //
//----------------------------------------------------------------------------//
char		*strjoin_char(char const *s1, char c, t_exec *exec);
char		**lst_to_str_array(t_array_lst *lst, t_exec *exec);
void		free_array(char **arr);
void		free_exit(t_exec *exec, int exit, bool close_fd);
//----------------------------------------------------------------------------//
//							 	Check access			 					  //
//----------------------------------------------------------------------------//
char		**get_paths(char **env);
//----------------------------------------------------------------------------//
//							 	Built-in			 						  //
//----------------------------------------------------------------------------//
int			ft_pwd(t_exec *exec);
int			ft_exit(char **args, t_exec *exec);
int			ft_echo(char **cmd);
int			ft_cd(char **path, t_exec *exec);
//----------------------------------------------------------------------------//
//							 	Built-in utils		 						  //
//----------------------------------------------------------------------------//
int			is_built_in(char *command);
int			is_built_in_no_fork(char *command);
int			exec_built_in(t_exec *exec);
int			check_exit_error(char **args, t_exec *exec);
//----------------------------------------------------------------------------//
//							 	Env	built-in	 							  //
//----------------------------------------------------------------------------//
int			ft_env(char **args, t_env_lst *env_lst);
int			ft_export(t_exec *exec, char **args);
int			ft_unset(t_env_lst **env_lst, char **args);
//----------------------------------------------------------------------------//
//							 	Env built-in utils		 					  //
//----------------------------------------------------------------------------//
int			export_env(char *arg, t_exec *exec);
void		unset_env(char *arg, t_env_lst **env_lst);
//----------------------------------------------------------------------------//
//							 	Env utils		 							  //
//----------------------------------------------------------------------------//
char		*get_env_name(char *env);
t_env_lst	*get_env_lst(char **env);
void		change_env_value(char *name, char *new_value, t_exec *exec);
char		*get_env_value(char *name, t_exec *exec);
void		free_env_lst(t_env_lst *env_lst);
//----------------------------------------------------------------------------//
//							 	Env lst			 							  //
//----------------------------------------------------------------------------//
t_env_lst	*lstnew_env(char *name, char *value);
t_env_lst	*lstlast_env(t_env_lst *lst);
void		lstadd_back_env(t_env_lst **lst, t_env_lst *new);
//----------------------------------------------------------------------------//
//							 	Lexer										  //
//----------------------------------------------------------------------------//
t_lex_lst	*lexer(char *readline_str, t_exec *exec);
//----------------------------------------------------------------------------//
//							 	Lexer lst utils								  //
//----------------------------------------------------------------------------//
t_lex_lst	*lstnew_lex(char *content, int operator, t_exec *exec);
t_lex_lst	*lstlast_lexer(t_lex_lst *lst);
void		lstadd_back_lex(t_lex_lst **lst, t_lex_lst *new);
void		read_lst(t_lex_lst *lst);
//----------------------------------------------------------------------------//
//							 	Lexer utils									  //
//----------------------------------------------------------------------------//
int			is_operator(char *readline_str);
int			get_word_size(char *readline_str);
void		get_word(char *readline_str, char **word);
void		go_to_word_end(char **readline_str);
//----------------------------------------------------------------------------//
//							 	Array lst utils								  //
//----------------------------------------------------------------------------//
t_array_lst	*lstnew_array(char *content, t_exec *exec);
t_array_lst	*lstnew_array_content2(char *c, char *c2, t_exec *exec);
t_array_lst	*lstlast_array(t_array_lst *lst);
void		lstadd_back_array(t_array_lst **lst, t_array_lst *new);
void		read_lst_array(t_array_lst *lst, char *type);
//----------------------------------------------------------------------------//
//							 	Check error									  //
//----------------------------------------------------------------------------//
int			check_error(t_lex_lst *lexed_list);
//----------------------------------------------------------------------------//
//							 	Expander									  //
//----------------------------------------------------------------------------//
void		expander(t_exec *exec);
//----------------------------------------------------------------------------//
//							 	Parser utils								  //
//----------------------------------------------------------------------------//
int			is_env(char *str);
char		*expand_env_name(char *str);
void		go_end_env_name(char **str);
//----------------------------------------------------------------------------//
//							 	Malloc lst utils							  //
//----------------------------------------------------------------------------//
t_mal_lst	*lstnew_malloc(void *adr);
t_mal_lst	*lstlast_malloc(t_mal_lst *lst);
void		lstadd_back_malloc(t_exec *exec, t_mal_lst *new);
void		free_lst_malloc(t_mal_lst *lst);
//----------------------------------------------------------------------------//
//							 	Token										  //
//----------------------------------------------------------------------------//
t_tok_lst	*get_token_lst(t_exec *exec);
//----------------------------------------------------------------------------//
//							 	Token utils									  //
//----------------------------------------------------------------------------//
void		add_here_doc(t_tok_lst **tok, t_lex_lst **lex_lst, t_exec *exec);
void		add_redir_in(t_tok_lst **tok, t_lex_lst **lex_lst, t_exec *exec);
void		add_redir_out(t_tok_lst **tok, t_lex_lst **lex_ls, t_exec *exec);
void		add_app_out(t_tok_lst **tok, t_lex_lst **lex_lst, t_exec *exec);
void		add_word(t_tok_lst **tok, t_lex_lst **lex_lst, t_exec *exec);
//----------------------------------------------------------------------------//
//							 	Token lst utils								  //
//----------------------------------------------------------------------------//
t_tok_lst	*lstnew_token(t_exec *exec);
t_tok_lst	*lstlast_token(t_tok_lst *lst);
void		lstadd_back_token(t_tok_lst **lst, t_tok_lst *new);
void		read_lst_token(t_tok_lst *lst);
int			ft_lstsize_token(t_tok_lst *lst);
//----------------------------------------------------------------------------//
//							 	Exec										  //
//----------------------------------------------------------------------------//
void		exec(t_exec *exec);
void		init_exec(t_exec *exec);
char		*get_right_path(char *path, t_array_lst *cmd, t_exec *exec);
//----------------------------------------------------------------------------//
//							 	Exec simple									  //
//----------------------------------------------------------------------------//
void		append(t_tok_lst *tok_lst);
void		redir_out(t_tok_lst *tok_lst);
void		redir_in(t_tok_lst *tok_lst);
void		here_doc(t_tok_lst *tok_lst);
//----------------------------------------------------------------------------//
//							 	Exec simple	management						  //
//----------------------------------------------------------------------------//
void		exec_token(t_exec *exec, int i);
void		here_doc_manage(t_exec *exec);
//----------------------------------------------------------------------------//
//							 	Exec utils									  //
//----------------------------------------------------------------------------//
char		*ft_newstrjoin(char *s1, char *s2);
void		close_fds(int fd_nbr, ...);
int			file_exist(char *file_name);
int			file_exec(char *file_name);
int			is_directory(char *path);
//----------------------------------------------------------------------------//
//							 	Exec here_doc								  //
//----------------------------------------------------------------------------//
int			check_heredoc(t_exec *exec);
void		position_last_heredoc(t_exec *exec);
void		heredoc_rm(t_tok_lst *tok_lst);
//----------------------------------------------------------------------------//
//							 	Exec error									  //
//----------------------------------------------------------------------------//
void		error_manager(t_exec exec);
void		error_message(char *file, char *message);
void		built_in_error_manage(t_exec *exec);
int			error_here_doc(t_exec *exec, int stdin_fd);
//----------------------------------------------------------------------------//
//							 	Exec access									  //
//----------------------------------------------------------------------------//
char		*get_wrong_access(t_tok_lst *tok_lst);
int			check_outfile(t_tok_lst *tok_lst);
int			check_infile(t_tok_lst *tok_lst);
void		ft_null_access(char **split_path, t_exec *exec);
char		*ft_abs_path(char *cmd, t_exec *exec);
//----------------------------------------------------------------------------//
//							 	Signal										  //
//----------------------------------------------------------------------------//
void		sig_int_rl(int sig_num);
void		signal_manager_hd(void);
void		sig_process(int sig_num);

#endif