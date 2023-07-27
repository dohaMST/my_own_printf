#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/* task 0 functions */

int _printf(const char *format, ...);

/*task4 */

#define size_of_buff 1024

int handle_Buff(int c);

/* all we need in flags tasks */

#define flag_M  1
#define flag_P 2
#define flag_H 8
#define flag_Z 4
#define flag_S 16

int handle_flags(char *string);
int print_int(va_list args);
int print_decimal(va_list arg_list);
int print_decimal1(va_list arg_list);
int print_ch(va_list args);
int print_str(va_list args);
int print_percent(va_list args);
int print_bin(va_list arg_list);
int (*func_select(char format))(va_list);
int _putchar(char c);


/* related to task3 */

int handle_unsigned(va_list args);
int handle_octal(va_list args);
/* --------------*/


/*------------- */

int upper_heX(va_list args);
int lower_hex(va_list args);



/* related to task6 */

int handle_pointer(va_list args);

/*related to task13 */

int handle_rev(va_list args);

/*related to task14*/

int handle_rot(va_list args);

/* related to task5 */
int handle_S(va_list args);




#endif
