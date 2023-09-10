/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_wait.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:40:26 by jdubilla          #+#    #+#             */
/*   Updated: 2022/05/02 14:36:18 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

void	loop_wait(int argc)
{
	int	i;

	i = 0;
	while (i != argc - 3)
	{
		wait(NULL);
		i++;
	}
}
