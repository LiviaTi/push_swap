/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrei <liferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 12:27:59 by liferrei          #+#    #+#             */
/*   Updated: 2025/10/15 15:04:51 by liferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include	<unistd.h>
# include	<stdlib.h>
# include	<stddef.h>

typedef struct s_list
{
	int				number;
	int				index;
	struct s_list	*next;
}					t_list;

int		ft_isdigit(int c);
long	ft_atol(const char *str);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);

void	ft_lst_add_back(t_list **a, t_list *new_node);
int		lst_size(t_list **list);

void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);

#endif