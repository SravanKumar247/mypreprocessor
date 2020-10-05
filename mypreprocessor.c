//my-preprocessor
//1.removes comments
//2.include files
//3.macros replacement
//4.conditional compilation
#include"mypreprocessorheader.h"
int main(char argc,char *argv[])
{
	FILE *fp;
	char (*db)[80]=NULL;
	char temp[80];
	int i=0;
	if(argc<2)
	{
		printf("ERROR:command not found");
		return 0;
	}
	fp=fopen(argv[1],"r");
	while(fgets(temp,80,fp))
	{ 	
           db=realloc(db,(cnt+1)*sizeof(temp));
	   strcpy(db[cnt],temp);
	   cnt++;
	}
	fclose(fp);
	db=removecomments(db,cnt);
	db=macrosreplacement(db);
	fileinclusion(db,argv[1]);
	return 0;
}
int cnt;
