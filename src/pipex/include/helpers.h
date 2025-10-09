/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvan-ast <jvan-ast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 12:10:07 by jvan-ast          #+#    #+#             */
/*   Updated: 2025/09/17 18:14:21 by jvan-ast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPERS_H
# define HELPERS_H

void	write_pipe(int fd[2]);
void	listen_pipe(int fd[2]);
int		pid_ok(int pid);

#endif
