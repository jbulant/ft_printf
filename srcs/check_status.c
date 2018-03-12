#include "ft_printf.h"

t_bool			find_percent(const char *s, int *index)
{
	t_bool	ret;
	int		i;

	i = -1;
	ret = FALSE;
	while (s[++i])
	{
		if (s[i] == '%')
		{
			ret = TRUE;
			break ;
		}
	}
	*index = i;
	return (ret);
}

void		check_status(t_printf_data *data)
{
	if (find_percent(data->format_string + data->format_index, &data->max_copy))
		data->status = ANALYZING_PERCENT;
	else
		data->status = FINISH;	
}
