#include "ft_printf.h"

// 1 = >= 7
// 2 = >= 11
// 3 = >= 16
// 4 = >= 21

// 4
// 5
// 5
//


/*
void	set_mask2(t_unicode *ucode)
{
	char convert[2];

	convert[0] = UNIBYTE2 | (ucode->c.w[0] >> 6);
	convert[1] = UNIBYTE1 | ((ucode->c.w[1] >> 6) );

	
	convert[0] = UNIBYTE2 | ((char)(ucode->c >> 6) );
	convert[1] = UNIBYTE1 | ((char)(ucode->c << 2) >> 2);
}
*/

void	set_mask2(t_unicode *ucode)
{
	char convert[4];

	//convert[0] = UNIBYTE3 | (ucode->c.w[0] >> 4);
	//convert[1] = UNIBYTE1 | ((ucode->c.w[1] >> ) );

	convert[0] = (UNIBYTE2 | ((char)(ucode->c >> 6))) & (UNIBYTE2 | MASK3);
	convert[1] = (UNIBYTE1 | (char)(ucode->c)) & (UNIBYTE1 | MASK2);
	*(short*)&convert[2] = 0;
	ucode->c = *(int*)convert;
}

void	set_mask3(t_unicode *ucode)
{
	char convert[4];

	//convert[0] = UNIBYTE3 | (ucode->c.w[0] >> 4);
	//convert[1] = UNIBYTE1 | ((ucode->c.w[1] >> ) );

	convert[0] = (UNIBYTE3 | ((char)(ucode->c >> 12))) & (UNIBYTE3 | MASK4);
	convert[1] = (UNIBYTE1 | ((char)(ucode->c >> 6))) & (UNIBYTE1 | MASK2);
	convert[2] = (UNIBYTE1 | (char)(ucode->c)) & (UNIBYTE1 | MASK2);
	convert[3] = 0;
	ucode->c = *(int*)convert;
}

void	set_mask4(t_unicode *ucode)
{
	char convert[4];

	convert[0] = (UNIBYTE4 | (char)(ucode->c >> 18)) & (UNIBYTE4 | MASK4);
	convert[1] = (UNIBYTE1 | (char)(ucode->c >> 12)) & (UNIBYTE1 | MASK2);
	convert[2] = (UNIBYTE1 | (char)(ucode->c >> 6)) & (UNIBYTE1 | MASK2);
	convert[3] = (UNIBYTE1 | (char)(ucode->c)) & (UNIBYTE1 | MASK2);
	ucode->c = *(int*)convert;
}

/*
void	set_mask4(t_unicode *ucode)
{
	char convert[4];

	convert[0] = UNIBYTE4 | ((char)(ucode->c >> 18) );
	convert[1] = UNIBYTE1 | ((char)((ucode->c << 14) >> 12));
	convert[2] = UNIBYTE1 | ((char)((ucode->c << 8) >> 6));
	convert[3] = UNIBYTE1 | ((char)(ucode->c << 2) >> 2);
}
*/
void	get_unicode_size(t_unicode *ucode)
{
	int	i;

	i = -1;
	while(ucode->c >> (++i)  && i < 32)
		;
	if (i <= 7)
		ucode->size = 1;
	else if (i <= 11)
		ucode->size = 2;
	else if (i <= 16)
		ucode->size = 3;
	else
		ucode->size = 4;
}

int		parse_unicode(t_printf_data *data)
{
	static void	(*set_mask[3])(t_unicode*) = {set_mask2, set_mask3, set_mask4};
	t_unicode	ucode;

	ucode.c = va_arg(data->args, wchar_t);
	data->current_flags |= DELIM_UNI_CHAR;
//	print_bits(UNIBYTE1);
//	printf("\n");
//	print_bits(UNIBYTE3);
//	printf("\n");
//	print_bits(ucode.c);
//	printf("\n");
	if ((int)ucode.c < 0)
	{
		data->status = FINISH;
		data->ret_value = -1;
		return (-1);
	}
	get_unicode_size(&ucode);
	if (ucode.size != 1)
		set_mask[ucode.size - 2](&ucode);
	printf("%d == size\n", ucode.size);
	printf("%u == wchar\n", ucode.c);
	ft_memcpy(data->str->buffer + data->str->size, &ucode.c, ucode.size);
	data->format_index++;
	data->str->size += ucode.size;
	data->current_flags = 0;
	return ((data->status = COPYING));
}
