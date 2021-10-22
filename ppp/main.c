/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camscl <camscl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:35:18 by camscl            #+#    #+#             */
/*   Updated: 2021/10/22 15:45:58 by camscl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int  ft_strlen(char *str)
{
    int count;

    count = 0;
    while(str[count])
        count++;
    return(count);
}


void	ft_putendl_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}


int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s1[i] == s2[i] && i < (n - 1))
		i++;
	if (n)
		return (*((unsigned char *)s1 + i) - *((unsigned char *)s2 + i));
	return (0);
}
int     test_ber(char *file)
{
    int len;

    len = ft_strlen(file);
    if (file == 0)
        return (0);
    if (len < 5)
        return (0);
    if (ft_strncmp(file + len - 4, ".ber", 5) != 0)
        return (0);
    return(1);
}

void	die(char *errmsg, int errnum)
{
	if (errmsg != 0 || errnum != 0)
		ft_putendl_fd("Error", 2);
	if (errmsg != 0)
		ft_putstr_fd(errmsg, 2);
	if (errmsg != 0 && errnum != 0)
		ft_putstr_fd(": ", 2);
	if (errnum != 0)
		ft_putstr_fd(strerror(errnum), 2);
	if (errmsg != 0 || errnum != 0)
	{
		ft_putendl_fd("", 2);
		exit(1);
	}
	exit(0);
}
int main(int argc, char **argv)
{

   //if (argc != 2)
		//die("invalid number of arguments", 0);
   if (test_ber(argv[1]) == 0)
		die("invalid argument (<name>.ber)", 0);

return(0);
}

