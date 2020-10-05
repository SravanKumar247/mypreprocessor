//my-preprocessor
//removes comments
#include"mypreprocessorheader.h"
char *removecomments(char (*db)[80],int cnt1)
{
	int i,j,l;
	for(i=0;i<cnt1;i++)
        {
	  for(j=0;j<80;j++)
	  {	
		if(db[i][j]==47&&db[i][j+1]==47)
		{
		  for(;db[i][j]!=10;j++)
		      db[i][j]=32;	  
		}
		else if(db[i][j]==47&&db[i][j+1]==42)
		{
			for(;db[i][j]!=42||db[i][j+1]!=47;j++)
			    db[i][j]=32;
			if(db[i][j]==42&&db[i][j+1]==47)
			{
				db[i][j]=32;
				db[i][j+1]=32;
			}
		}
          }
	}
	return db;
}




