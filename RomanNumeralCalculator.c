#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "RomanNumeralCalculator.h"

typedef struct _unit { char *Roman; int Arabic, len, over; } unitt, *unitp;

static unitt unit[] = {
    {  "M", 1000, 1, 3 }, { "CM",  900, 2, 1 },
    {  "D",  500, 1, 1 }, { "CD",  400, 2, 1 },
    {  "C",  100, 1, 3 }, { "XC",   90, 2, 1 },
    {  "L",   50, 1, 1 }, { "XL",   40, 2, 1 },
    {  "X",   10, 1, 3 }, { "IX",    9, 2, 1 },
    {  "V",    5, 1, 1 }, { "IV",    4, 2, 1 },
    {  "I",    1, 1, 3 }, {   "",    0, 0, 0 }
};

int RomanToArabic(char *arg) {
    unitp p = unit;
    int result = 0, count = p->over;
    while (*arg && p->len) {
        while (p->len) {
            if (strncmp(p->Roman, arg, p->len)) count = (++p)->over;
            else {
                arg += p->len;
                result += p->Arabic;
                if (!--count) count = (++p)->over;
            }
        }
    }
    return *arg ? 0 : result;
}

char *ArabicToRoman(int arg) {
    unitp p = unit;
    char buffer[64] = "", *result;
    while (arg > 0) {
        int sub = arg - p->Arabic;
        if (sub < 0) p++;
        else {
            strcat(buffer, p->Roman);
            arg = sub;
        }
    }
    result = malloc(strlen(buffer)+1);  // Memory leak unless freed.
    strcpy(result, buffer);
    return result;
}

char *RNC_add(char *arg1, char *arg2) {
    return ArabicToRoman(RomanToArabic(arg1) + RomanToArabic(arg2));
}

char *RNC_sub(char *arg1, char *arg2) {
    return ArabicToRoman(RomanToArabic(arg1) - RomanToArabic(arg2));
}

/* Extra untested functionality */
char *RNC_mul(char *arg1, char *arg2) {
    return ArabicToRoman(RomanToArabic(arg1) * RomanToArabic(arg2));
}

char *RNC_div(char *arg1, char *arg2) {
    return ArabicToRoman(RomanToArabic(arg1) / RomanToArabic(arg2));
}
