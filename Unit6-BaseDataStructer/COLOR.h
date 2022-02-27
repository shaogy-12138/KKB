/*************************************************************************
	> File Name: COLOR.h
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Sun 27 Feb 2022 03:20:07 PM CST
 ************************************************************************/

#ifndef _COLOR_H
#define _COLOR_H
#endif
#define COLOR(a, b) "\033[" #b "m" a "\033[0m]"
#define GREEN(a) COLOR(a, 32)
#define RED(a) COLOR(a, 31)
