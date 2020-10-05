#include"mypreprocessorheader.h"
int checkheaderfile(char *,int n,char *);
int storefilename(char *,int n,char *);
char *storefilecontintobuf(char *,int,int *,char (*buf1)[80]);
void fileinclusion(char(*buf)[80],char *newfilename)
{
	FILE *fp1;
	char arr[]="#include",arr1[20],filename[20];
	int cnt1=0,cnt2=0,n,n1,i,l,j,flag=0,flag1=0;
	char (*buf1)[80]=NULL;
	n=strlen(arr);
	n1=strlen(newfilename);
	newfilename[n1-1]='i';
	for(i=0;i<cnt;i++)
	{
	
		l=checkheaderfile(buf[i],n,arr);
		if(l==1)
		{
		     l=strlen(buf[i]);
		     if(ispunct(buf[i][l+1])==1)
			{	
			  flag=1;	
		          printf("error\n");
		           printf("%s\n",buf[i]);
			}
	                
		}
	}
	if(flag==1)
		exit(0);
        for(i=0;i<cnt;i++)
	{
	        l=checkheaderfile(buf[i],n,arr);
		if(l!=0)
		{
			cnt2++;
	        	l=storefilename(buf[i],l,arr1);
		        if(cnt2<2)
			{
			  fp1=fopen(newfilename,"w");
			  if(fp1==NULL)
				  printf("file not opened\n");
			buf1=storefilecontintobuf(arr1,l,&cnt1,buf1);
			buf1=removecomments(buf1,cnt1);
			   for(l=0;l<cnt1;l++)
			   {
				  for(j=0;buf[l][j]==32&&j<80;j++);
			           if(j!=80)	  
			            fprintf(fp1,"%s",buf1[l]);
			   }
         		  fclose(fp1);
			  buf1=realloc(buf1,0);
			}
			else if(cnt2>=2)
			{
				cnt1=0;
				fp1=fopen(newfilename,"a");
	                	buf1=storefilecontintobuf(arr1,l,&cnt1,buf1);
				buf1=removecomments(buf1,cnt1);
				for(l=0;l<cnt1;l++)
				{
				  for(j=0;buf[l][j]==32&&j<80;j++);
			           if(j!=80)	  
				   fprintf(fp1,"%s",buf1[l]);
				}
				fclose(fp1);
		                buf1=realloc(buf1,0);
			}
		}
          }
		fp1=fopen(newfilename,"a");
		for(i=0;i<cnt;i++)
		{
			if(!checkheaderfile(buf[i],n,arr))
			{
				for(j=0;buf[i][j]==32&&j<80;j++);
				if(j!=80)
			            fprintf(fp1,"%s",buf[i]);
			     }
					      					     		      
		}
		fclose(fp1);
                buf=realloc(buf,0);
		return ;
}
char *storefilecontintobuf(char *arr1,int l,int *cnt1,char (*buf1)[80])
{
	char temp[80],filepath[80]="/usr/include/";     //bigmistake filepath was given in main         
	FILE *fp;
	int b=*cnt1;
	strcat(filepath,arr1);                            	//then strcat keep on concate the generated array 
		 if(l==1)                                
		 {
			 fp=fopen(filepath,"r");
			 if(fp==0)
			 {
				 printf("error1\n");
				 exit(0);
			 }
		 }
		 else
		 {
			 fp=fopen(arr1,"r");
			 if(fp==0)
			 {
				 fp=fopen(filepath,"r");
				 if(fp==0)
				 {
					 printf("error2 %s\n",filepath);
					 exit(0);
				 }
			 }
		 }
	        while(fgets(temp,80,fp))
	        {
		buf1=realloc(buf1,(b+1)*sizeof(temp));
		strcpy(buf1[b],temp);
		b++;
	        }
	        fclose(fp);
		*cnt1=b;
		return buf1;
	
}
		  
int storefilename(char *temp,int n,char *arr1)
{	
           int i=0,j=0,k;
	   for(i=n+1;temp[i]!=10;i++);
	   if(ispunct(temp[i-1])&&temp[i-1]!=34&&temp[i-1]!=62)
	   {
		   printf("warning:%s",temp+n-8);                            //if headerfile is crct declared but ispunct present at last
	    }
	   for(k=n;temp[k]!=10;k++)
	   {
   	   if(temp[k]==34)
	   {
		   for(i=k+1,j=0;temp[i]!=34;i++)
		      arr1[j++]=temp[i];
		   arr1[j]=0;
		   return 0;
		   
	   }
	   else if(temp[k]==60)
	   {
		   for(i=k+1,j=0;temp[i]!=62;i++)
			   arr1[j++]=temp[i];
		   arr1[j]=0;                        //error not terminated the string with null
		   return 1;
	   }
	   }
	   
	   if(temp[k]==10)
	   {	   
		   printf("error:%s\n",temp+n-8);             //if headerfile is not crctly declared.
		   exit(0);
	   }
	   
	   
}
int checkheaderfile(char *temp,int n,char *arr)
{
	int i,j,cnt=0,c;
	for(i=0,j=0;temp[i]!=10;i++)                       //done mistake by not valid arr to function 
        {                                      //bug 
		if(temp[i]==arr[j])
		{
			cnt++;
			j++;
			c=i;
		}
	        else
		{	j=0;
			continue;
		}
	}
	if(cnt==n)
		return c+1;
	return 0;
}

