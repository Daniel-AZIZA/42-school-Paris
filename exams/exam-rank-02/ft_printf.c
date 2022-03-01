#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>

typedef struct	s_data
{
	va_list next;
	char	f;
	int	d;
	char	*str;
	unsigned int x;
	int 	sign;
	int	flag;
	int	before_flag;
	int	after_flag;
	int	octet;
}		t_data;


void	init(t_data *data)
{
	data->d = 0;
	data->str = NULL;
	data->x = 0;
	data->sign = 0;
	data->flag = 0;
	data->before_flag = 0;
	data->after_flag = 0;
}

void	ft_putchar(char c, t_data *data)
{
	write(1, &c, 1);
	data->octet++;
}

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (6);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	count_d(int nb, t_data *data)
{
	unsigned int	i;
	unsigned int	nbr;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		data->sign = 1;
		nbr = -nb;
	}
	else
		nbr = nb;
	while (nbr > 0)
	{
		i++;
		nbr /= 10;
	}
	return (i);
}

int	count_x(unsigned int nb)
{
	unsigned int	i;

	if (nb == 0)
		return (1);
	i = 0;
	while (nb > 0)
	{
		i++;
		nb /= 16;
	}
	return (i);
}

int	ft_atoi(char *str)
{
	int	nbr;
	int	neg;

	nbr = 0;
	neg = 1;
	while (*str && (*str == ' ' || *str == '\t'))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		nbr *= 10;
		nbr += *str - 48;
		str++;
	}
	return (nbr * neg);
}

void	ft_putnbr(int nb, t_data *data)
{
	unsigned int	nbr;

	if (nb < 0)
		nbr = -nb;
	else
		(nbr = nb);
	if (nbr / 10 != 0)
		ft_putnbr(nbr / 10, data);
	ft_putchar(48 + (nbr % 10), data);
}

void	ft_putstr(char *str, t_data *data, int i)
{
	if (!str)
	{
		if (i == -1)
		{
			write(1, "(null)", 6);
			data->octet += 6;
		}
		else
		{
			write(1, "(null)", i);
			data->octet += i;
		}
		return ;
	}
	if (i != -1)
	{
		while (*str && i--)
		{
			ft_putchar(*str, data);
			str++;
		}
	}
	else
	{
		while (*str)
		{
			ft_putchar(*str, data);
			str++;
		}
	}

}

void	ft_puthexa(unsigned int nb, t_data *data)
{
	char *base;

	base = "0123456789abcdef";
	if (nb / 16 > 0)
		ft_puthexa(nb / 16, data);
	ft_putchar(base[nb % 16], data);
}

void	ft_find_conv(char *format, t_data *data)
{
	data->f = *format;
	if (*format == 'd')
		data->d = va_arg(data->next, int);
	if (*format == 's')
		data->str = va_arg(data->next, char *);
	if (*format == 'x')
		data->x = va_arg(data->next, unsigned int);
}

void	ft_conv(t_data *data, int i)
{
	if (data->f == 'd')
		ft_putnbr(data->d, data);
	if (data->f == 's')
		ft_putstr(data->str, data, i);
	if (data->f == 'x')
		ft_puthexa(data->x, data);
}

int	get_count(t_data *data)
{
	if (data->f == 'd')
		return (count_d(data->d, data));
	if (data->f == 's')
		return (ft_strlen(data->str));
	if (data->f == 'x')
		return (count_x(data->x));
	return (0);
}

int	ft_count_precision(t_data *data, int count)
{
	if (data->flag && data->after_flag == 0 && ((data->f == 'd' && data->d == 0) || (data->f == 'x' && data->x == 0)))
		return (0);
	if (data->f == 'd' || data->f == 'x')
	{
		if (data->after_flag == 0 || data->after_flag <= count)
			return (count);
		return (data->after_flag > count) ? data->after_flag : count;
	}
	else
		return (data->after_flag >= count || !data->flag) ? count : data->after_flag;
}

void 	ft_write_lc(t_data *data, int precision)
{
	int i = 0;

	while (i < (data->before_flag - precision - data->sign))
	{
		ft_putchar(' ', data);
		i++;
	}
}	

void	ft_flag(char *format, t_data *data)
{
	int count;
	int precision;
	int i = 0;

	if (*format >= '0' && *format <= '9')
		data->before_flag = ft_atoi(format);
	while (*format && *format != '.' && *format >= '0' && *format <= '9')
		format++;
	if (*format == '.')
	{
		data->flag = 1;
		format++;
	}
	if (*format >= '0' && *format <= '9')
		data->after_flag = ft_atoi(format);
	while (*format && *format >= '0' && *format <= '9')
		format++;

	ft_find_conv(format, data);

	count = get_count(data);
	precision = ft_count_precision(data, count);
	ft_write_lc(data, precision);
	if (data->f != 's' && data->flag && precision - count)
	{
		if (data->sign)
			ft_putchar('-', data);
		while (i < precision - count)
		{
			ft_putchar('0', data);
			i++;
		}
	}
	if ((data->flag == 0 || (precision - count == 0)) && data->sign)
		ft_putchar('-', data);
	if (precision == 0 && ((data->f == 'd' && data->d == 0) || (data->f == 'x' && data->x == 0)))
		return ;
	ft_conv(data, !data->flag ? -1 : precision);
}

int	ft_printf(const char *forma, ...)
{
	t_data	data;
	char	*format;

	init(&data);
	format = (char *)forma;
	va_start(data.next, forma);
	data.octet = 0; 	// !

	while (*format)
	{
		if (*format != '%')
			ft_putchar(*format, &data);
		if (*format == '%')
		{
			format++;
			ft_flag(format, &data);
			while (*format != 'd' && *format != 's' && *format != 'x')
				format++;
			init(&data); // !
		}
		format++;
	}

	va_end(data.next);
	return (data.octet);		
}

/*
int	main(void)
{
*/
/************basic test**************/
/*
	ft_printf("%d\n", ft_printf(""));
	ft_printf("%d\n", 42);
	ft_printf("%d\n", INT_MAX);
	ft_printf("%d\n", INT_MIN);
	ft_printf("%d\n", 0);
	ft_printf("%s\n", "vetgrthtrhtpmcz");	
	ft_printf("%s\n", "13454565%ù^ù(§§'");	
	ft_printf("%s\n", NULL);	
	ft_printf("%x\n", 42);
	ft_printf("%x\n", INT_MAX);
	ft_printf("%x\n", INT_MIN);
	ft_printf("%x\n", 0);
	ft_printf("%x\n", 98);
	ft_printf("%d\n", ft_printf("%s\n", NULL));
*/
/************multi test**************/
/*
	printf("retour : %d\n", ft_printf("%d gegre %d verver%d vrever%d vervre %s::::: %s vrvrevz ^ %s 123R43 %x fzef=:;ve %x rbreber %x verveve %x vzrvervze",42, INT_MAX, INT_MIN, 0, "jbojp,pjpo", "toto", NULL, 98, INT_MAX, INT_MIN, 0));

	printf("\n");

	printf("retour : %d\n", ft_printf("%d gegre %d verver%d vrever%d vervre %s::::: %s vrvrevz ^ %s 123R43 %x fzef=:;ve %x rbreber %x verveve %x vzrvervzen",42, INT_MAX, INT_MIN, 0, "jbojp,pjpo", "toto", NULL, 98, INT_MAX, INT_MIN, 0));
*/

/*************test field**************/
/*
 	ft_printf("%.d\n", 0);
 	ft_printf("%.x\n", 0);
	ft_printf("%.d\n", 42);
	ft_printf("%10.d\n", 42);
	ft_printf("%.10d\n", 42); 
	ft_printf("%10.5d\n", 42);
	ft_printf("%10.1d\n", 42);
	ft_printf("%10.10d\n", 42);
	ft_printf("%0.0d\n", 42);
	ft_printf("%1.0d\n", 42);
	ft_printf("%15.0d\n", INT_MIN);
	ft_printf("%.15d\n", INT_MIN);
	ft_printf("%.15d\n", -42);
	ft_printf("%15.15d\n", INT_MIN);
	ft_printf("%15.13d\n", INT_MIN);
	ft_printf("%.d%.d\n", INT_MIN, INT_MAX);
	ft_printf("%15.d%15.d\n", INT_MIN, INT_MAX);
	ft_printf("%.15d%.15d\n", INT_MIN, INT_MAX);
	ft_printf("%.d\n", -554354);
	ft_printf("%100.d\n", -554354);
	ft_printf("%.100d\n", -554354);
	ft_printf("%142d\n", -532534);
	ft_printf("%137d\n", 98765);
	ft_printf("%137x\n", 98765);

	ft_printf("%.x\n", 42);
	ft_printf("%10.x\n", 42);
	ft_printf("%.10x\n", 42); 
	ft_printf("%10.5x\n", 42);

	ft_printf("%.d", INT_MAX);
	ft_printf("%.10x", INT_MAX);
	ft_printf("%17.d", INT_MIN);
	ft_printf("%.54d", 3255778);
	ft_printf("%14.56x", INT_MIN);
	ft_printf("%12.98x", 325876);
	ft_printf("%98.15x\n",0);
	ft_printf("%98.15d\n",0);
	ft_printf("%.15d\n",0);
	ft_printf("%98.d\n",0);
	ft_printf("%39.39d", 1224213);
	ft_printf("%54.12d",764746);
	ft_printf("%0.0d", 23432);
	ft_printf("%0.3x", 8768);
	ft_printf("%43.23d",12564564);
	ft_printf("%12.43x",988888);
	ft_printf("%12.43x",-988888);
	ft_printf("%56.13x",-988888);

	ft_printf("%.s\n", "toto");
	ft_printf("%10.s\n", "toto");
	ft_printf("%.10s\n", "toto");
	ft_printf("%10.1s\n", "toto");
	ft_printf("%65.87s\n", "toto");
	ft_printf("%65.87s\n", "totozfveizjrbvoerbvoejrbvoierbvierbvibervie");
	ft_printf("%41.76s\n", "totofhezijzbevzjvbrzijbveirbviejrbviberzov");
	ft_printf("%41.73s\n", "toto");
	ft_printf("%12.32s", NULL);
	ft_printf("%1.1s", NULL);
	ft_printf("%.1s", NULL);
	ft_printf("%1s\n",NULL);
	ft_printf("%100.100s", NULL);
	ft_printf("%.100s", NULL);
	ft_printf("%100s\n",NULL);
	ft_printf("%100.s\n",NULL); //1er pb
	ft_printf("%.s\n", NULL);

	ft_printf("%32s", "abc");
*/
/*************end joking*************/
/*
printf("retour : %d\n", ft_printf("%d%x%s%.d%.x%.s%74.d%62.x%52.s%.98d%.86x%.42s%54.76d%63.90x%42.42d%42.42x%42.42s%12.21d%432.23x%12.65s%53.32s%0.0d%0.0x%.0s%12.32s\n", 
	INT_MIN,
	INT_MIN,
	NULL,
	4533543,
	765765,
	"bnoknokbnojbijbvijb",
	INT_MAX,
	INT_MAX,
	"vzfgezrf",
	76474,
	634523,
	"jkblnlkbnkb",
	INT_MAX,
	INT_MIN,
	42,
	49999,
	"IHBK,NMLNJVIV",
	INT_MIN,
	INT_MAX,
	"UGCVIVBIPHPOIB-----",
	"DXUCHVLOBOB",
	532523,
	908876,
	NULL,
	NULL));


printf("retour : %d\n", ft_printf("vavevervrrrrrrrre %d fzibfozjnf %x 325463434^ù%d grngoerbnvoer %d eonzcoizebnvcoiezc %x voeznvoiezvz %x iuvbzeriubfizeu %x oinbvzornvoirzbvrb %d vezobnvozibviozer %d%d%x vzobnvzobv %d vjefv %x", INT_MAX, INT_MAX, INT_MIN, 3255778, INT_MIN, 325876, 0, 1224213, 764746, 23432, 8768, 12564564, 988888));


printf("retour : %d\n", ft_printf("vavevervrrrrrrrre %.d fzibfozjnf %.10x 325463434^ù%17.d grngoerbnvoer %.54d eonzcoizebnvcoiezc %14.56x voeznvoiezvz %12.98x iuvbzeriubfizeu %98.15x oinbvzornvoirzbvrb %39.39d vezobnvozibviozer %54.12d%0.0d%0.3x vzobnvzobv %43.23d vjefv %12.43x", INT_MAX, INT_MAX, INT_MIN, 3255778, INT_MIN, 325876, 0, 1224213, 764746, 23432, 8768, 12564564, 988888));


printf("retour : %d\n", ft_printf("fzjbenbfjiz 324 %d%x %s fjzhfozhrz %.d erggre %.x vregre rvfzre vzv \n \t zrz %.s vsfvzv , %74.d vzvzvze %62.x zfevzev %52.s konpl,pnze$ %.98d vzevez %.86x vrevrzaf %.42s vzvze %54.76d vzvzrv %63.90x fnjznoznrg reger  %42.42dgrzg %42.42x grgreg %42.42s grgrg rrg re%12.21d%432.23x%12.65s%53.32s vrzgr %0.0d fezfe %0.0x grgerg er%.0s vvrezvzr%12.32s\n",
	INT_MIN,
	INT_MIN,
	NULL,
	4533543,
	765765,
	"bnoknokbnojbijbvijb",
	INT_MAX,
	INT_MAX,
	"vzfgezrf",
	76474,
	634523,
	"jkblnlkbnkb",
	INT_MAX,
	INT_MIN,
	42,
	49999,
	"IHBK,NMLNJVIV",
	INT_MIN,
	INT_MAX,
	"UGCVIVBIPHPOIB-----",
	"DXUCHVLOBOB",
	532523,
	908876,
	NULL,
	NULL));

	

ft_printf("retour : %d\n", ft_printf("fzjbenbfjiz 324 %d%x %s fjzhfozhrz %.d erggre %.x vregre rvfzre vzv \n \t zrz %.s vsfvzv , %74.d vzvzvze %62.x zfevzev %52.s konpl,pnze$ %.98d vzevez %.86x vrevrzaf %.42s vzvze %54.76d vzvzrv %63.90x fnjznoznrg reger  %42.42dgrzg %42.42x grgreg %42.42s grgrg rrg re%12.21d%432.23x%12.65s%53.32s vrzgr %0.0d fezfe %0.0x grgerg er%.0s vvrezvzr%12.32s ezetgze ezrrz erz  %1000.d rrefrefe %.1000d FZE FEZV %200d zfeferzfez %.200d zvfevezrvre                  erre %100.s",
	INT_MIN,
	INT_MIN,
	NULL,
	4533543,
	765765,
	"bnoknokbnojbijbvijb",
	INT_MAX,
	INT_MAX,
	"vzfgezrf",
	76474,
	634523,
	"jkblnlkbnkb",
	INT_MAX,
	INT_MIN,
	42,
	49999,
	"IHBK,NMLNJVIV",
	INT_MIN,
	INT_MAX,
	"UGCVIVBIPHPOIB-----",
	"DXUCHVLOBOB",
	532523,
	908876,
	NULL,
	NULL,
	INT_MIN,
	INT_MIN,
	INT_MAX,
	INT_MAX,
	NULL));
*//*
	return (0);
}*/
