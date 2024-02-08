/* My main does not follow the norme.
 * In case you want to test the whole ft_printf, you should uncomment the
 * variables and change the values as many times as you want!
 */

#include <stdio.h>
#include "ft_printf.h"

int main()
{
	char	c = 'H';
/*	char	*str = "42Barcelona";
	int		p = 14523;
	int		i = 0;
	int		digit = 0;
	unsigned int		x = 4294967295;
	unsigned int		X = 4294967286;
	unsigned int		u = 4294967295;
	int		*ptr = &p;
*/
	int org = 0;
	int mine = 0;

/*	org = printf("---Org---\nChar: %c\nStr: %s\nPtr: %p\nInt: %i\nDig: %d\nHex_low: %x\nHex_up: %X\nUns: %u\nPercent: %%\n", c, str, (void*)ptr, i, digit, x, X, u);
	mine = ft_printf("---Mine---\nChar: %c\nStr: %s\nPtr:%p\nInt: %i\nDig: %d\nHex_low: %x\nHex_up: %X\nUns: %u\nPercent: %%\n", c, str, (void*)ptr, i, digit, x, X, u );
*/
	org = printf("O:%s\n", c);
	mine = ft_printf("M:%s\n", c);

	printf("res:%d\nres:%d\n", org, mine);

	return (0);
}
