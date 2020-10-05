#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>
#include<ctype.h>
char *removecomments(char (*p)[80],int);
char *macrosreplacement(char (*p)[80]);
void fileinclusion(char (*p)[80],char *);
extern int cnt;
