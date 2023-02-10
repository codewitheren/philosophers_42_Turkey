/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muerdoga <muerdoga@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:01:57 by muerdoga          #+#    #+#             */
/*   Updated: 2023/02/10 15:54:16 by muerdoga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	write_error(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	write(2, "Hata: ", 7);
	write(2, str, len);
	write(2, "\n", 1);
	return (1);
}

int	error_manager(int error)
{
	if (error == 1)
		return (write_error("Girilen argüman hatalı."));
	if (error == 2)
		return (write_error("Mutex başlatılırken bir hata oluştu."));
	return (1);
}

void	eat_control(t_rules *r, t_philosopher *p)
{
	int	i;

	i = 0;
	while (r->nb_eat != -1 && i < r->nb_philo && p[i].x_ate >= r->nb_eat)
		i++;
	if (i == r->nb_philo)
		r->all_ate = 1;
}
