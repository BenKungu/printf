#include "main.h"
#include "main.h"

/**
 * print_op - function to check which specifier to print
 * @format: string being passed
 * @print_arr: array 
 */

int _printf(const char *format, ...) 
{
	va_list args;
	va_start(args, format);
	int count = 0;
	while (*format) 
	{
		if (*format == '%') 
		{
			format++;
			switch (*format) 
			{
				case 'c': 
				{
					char c = va_arg(args, int);
					putchar(c)
					count++;
					break;
				}
				case 's': 
				{
                    			char *s = va_arg(args, char *);
                    			fputs(s, stdout);
                    			count += strlen(s);
                    			break;
                		}
                		case '%': 
				{
                    			putchar('%');
                    			count++;
                    			break;
                		}
                		default:
                    			fprintf(stderr, "Unknown conversion specifier: %%%c\n", *format);
                    			return -1;
			}
		}
	       	else 
		{
			putchar(*format);
			count++;
        	}
        	format++;
	}
    	va_end(args);
    	return count;
}
