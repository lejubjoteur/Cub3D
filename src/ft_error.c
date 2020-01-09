/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgimenez <qgimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 12:33:28 by qgimenez          #+#    #+#             */
/*   Updated: 2020/01/08 14:39:39 by qgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_putstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

int		ft_error(int code)
{
	if (code == 1)
		ft_putstr("Error\nArgument fichier map.\n");
	else if (code == 2)
		ft_putstr("Error\nLa map n\'est pas close.\n");
	else if (code == 3)
		ft_putstr("Error\nTaille des lignes incorrect.\n");
	else if (code == 4)
		ft_putstr("Error\nCaractere inconnu!\n");
	else if (code == 5)
		ft_putstr("Error\nPosition du joueur introuvable.\n");
	else if (code == 6)
		ft_putstr("Error\nPropriete de la fenetre incorrect.\n");
	else if (code == 7)
		ft_putstr("Error\nInformations manquantes"
		" pour un ou plusieurs elements.\n");
	else if (code == 8)
		ft_putstr("Error\nFichier en argument incorrect.\n");
	return (0);
}
