#!/bin/bash

make

gcc -Wall -Werror -Wextra ft_printf.c libftprintf.a main.c

./a.out
