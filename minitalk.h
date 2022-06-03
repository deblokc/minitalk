/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:12:34 by tnaton            #+#    #+#             */
/*   Updated: 2022/01/14 15:00:07 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include "libft/libft.h"
# include <unistd.h>
# include <signal.h>
# include <stdio.h>

typedef struct s_char {
	unsigned char	c;
	unsigned int	i;
	struct s_char	*first;
	struct s_char	*next;
}	t_char;
#endif
