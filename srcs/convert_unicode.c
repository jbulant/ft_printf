#include "ft_printf.h"

static void		set_mask2(t_unicode *ucode)
{
	char convert[4];

	convert[0] = (UNIBYTE2 | ((char)(ucode->c >> 6))) & (UNIBYTE2 | MASK2);
	convert[1] = (UNIBYTE1 | (char)(ucode->c)) & (UNIBYTE1 | MASK1);
	*(short*)&convert[2] = 0;
	ucode->c = *(int*)convert;
}

static void		des(t_unicode *ucode)
{
	char convert[4];

	convert[0] = (UNIBYTE3 | ((char)(ucode->c >> 12))) & (UNIBYTE3 | MASK3);
	convert[1] = (UNIBYTE1 | ((char)(ucode->c >> 6))) & (UNIBYTE1 | MASK1);
	convert[2] = (UNIBYTE1 | (char)(ucode->c)) & (UNIBYTE1 | MASK1);
	convert[3] = 0;
	ucode->c = *(int*)convert;
}

static void		set_mask4(t_unicode *ucode)
{
	char convert[4];

	convert[0] = (UNIBYTE4 | (char)(ucode->c >> 18)) & (UNIBYTE4 | MASK4);
	convert[1] = (UNIBYTE1 | (char)(ucode->c >> 12)) & (UNIBYTE1 | MASK1);
	convert[2] = (UNIBYTE1 | (char)(ucode->c >> 6)) & (UNIBYTE1 | MASK1);
	convert[3] = (UNIBYTE1 | (char)(ucode->c)) & (UNIBYTE1 | MASK1);
	ucode->c = *(int*)convert;
}

t_unicode		convert_unicode(t_unicode ucode)
{
	static void	(*set_mask[3])(t_unicode*) = {set_mask2, des, set_mask4};
	int	i;

	i = -1;
	while(ucode.c >> (++i)  && i < 32)
		;
	if (i <= 7)
		ucode.size = 1;
	else if (i <= 11)
		ucode.size = 2;
	else if (i <= 16)
		ucode.size = 3;
	else
		ucode.size = 4;
	if (ucode.size != 1)
		set_mask[ucode.size - 2](&ucode);
	return (ucode);
}
