#include "ft_printf.h"
/*
		n = 5678
		ret_value = 3578


*/

int				ft_big_putstr(t_str *str)
{
	int		ret_value;

	ret_value = (int)str->size;
	write (1, str->buffer, str->size);
	str->size = 0;
	return (ret_value);
}

int				ft_big_strset(t_str *dst, char c, size_t n)
{
	int		ret_value;

	ret_value = 0;
	if (!dst)
		return (-1);
	if (!n)
		return (0);
	if (dst->size + n >= STR_BUFFSIZE)
	{
		ret_value += ft_big_putstr(dst);
		while (n >= STR_BUFFSIZE)
		{
			write(1, &c, STR_BUFFSIZE);
			n -= STR_BUFFSIZE;
			ret_value += STR_BUFFSIZE;
		}
	}
	ft_memset(dst->buffer + dst->size, c, n);
	dst->size += n;
	return (ret_value);
}

int				ft_big_strset_off(t_str *dst, int off, char c, size_t n)
{
	int		ret_value;

	ret_value = 0;
	if (!dst)
		return (-1);
	if (!n)
		return (0);
	if (dst->size + n >= STR_BUFFSIZE)
	{
		ret_value += ft_big_putstr(dst);
		while (n >= STR_BUFFSIZE)
		{
			write(1, &c, STR_BUFFSIZE);
			n -= STR_BUFFSIZE;
			ret_value += STR_BUFFSIZE;
		}
	}
	printf("\nSH |%s| SH\n", dst->buffer);
	ft_memset(dst->buffer + dst->size + off, c, n);
	dst->size += n;
	return (ret_value);
}

int				ft_big_strncat(t_str *dst, const char *src, size_t n)
{
	int		ret_value;

	ret_value = 0;
	if (!dst || !src)
		return (-1);
	if (!n)
		return (0);
	if (dst->size + n >= STR_BUFFSIZE)
	{
		ret_value += ft_big_putstr(dst);
		while (n >= STR_BUFFSIZE)
		{
			write(1, src, STR_BUFFSIZE);
			src += STR_BUFFSIZE;
			n -= STR_BUFFSIZE;
			ret_value += STR_BUFFSIZE;
		}
	}
	ft_memcpy(dst->buffer + dst->size, src, n);
	dst->size += n;
	return (ret_value);
}
