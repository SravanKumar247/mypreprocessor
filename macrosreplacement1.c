#include"mypreprocessorheader.h"
int checkmacro(char *,int n,char *);
void storenamevalue(char *,char *,char *,int);
void searchnameandsubtitue(char *,char *,char *,char *,int);
char *macrosreplacement(char (*buf)[80])
{
	int n,m,l,i,j,flag=0;
	char arr[]="#define",arr1[20],arr2[20];
	n=strlen(arr);
	for(i=0;i<cnt;i++)
	{
		l=checkmacro(buf[i],n,arr);
		if(l!=0)
		{
			storenamevalue(buf[i],arr1,arr2,l);
			m=strlen(arr2);
			if(ispunct(arr2[m-1])&&arr2[m-1]!=41)
			{
			  flag=1;	
		          printf("error\n");
		           printf("%s %s %s\n",arr,arr1,arr2);
	                }
		}
	}
	if(flag==1) 
		exit(0);
	for(i=0;i<cnt;i++)
	{
	   l=checkmacro(buf[i],n,arr);
	   if(l!=0)
            {
	    storenamevalue(buf[i],arr1,arr2,l);
	    memmove(buf[i],buf[i+1],(cnt-(i+1))*sizeof(*buf));
	    cnt--;
	    l=i;
	    i--;
	   }
	   else continue;
	   for(j=l;j<cnt;j++)
	   {
	         searchnameandsubtitue(buf[j],arr1,arr2,arr,n);
	   }
	 }
	return buf;
}

void searchnameandsubtitue(char *temp,char *arr1,char *arr2,char *arr,int n)
{
	int cnt=0,i,j,n1,n2,b=0,a,k,l;
	char ch;
	n1=strlen(arr1);
	n2=strlen(arr2);
	l=checkmacro(temp,n,arr);
	for(i=0,j=0,k=n1;temp[i]!=10;i++)
	{
		if(l!=0)
		{
			if(temp[i]==arr1[j]&&temp[i+k]==10)
			{
				k--;
				cnt=(++j);
				if(cnt==n1)
				{
                                        b=cnt;
					printf("error\n");
					printf("you need to proceed y/n:");
					__fpurge(stdin);
					scanf("%c",&ch);
					if(ch=='y')
						goto input;
					else exit(0);
				}
				continue;
			}
			else 
			{
				j=0;
				continue;
			}
		}
		else
		{
		if(temp[i]==arr1[j])
		{
			cnt=(++j);
		        if(cnt==n1&&ispunct(temp[i+1]))
			{
				b=cnt;
				goto input;
			}
			continue;
		}
	       else 
		{
			j=0;
			continue;
		}
	        }
       input:  	if(b==n1)
		{
                      if(b<n2)
			{
				a=n2-b;
				memmove(temp+i+a+1,temp+i+1,strlen(temp+i+1)+1);
				for(i=(i+1)-b,k=0;k<n2;i++,k++)
					temp[i]=arr2[k];
				i=i+a;
			}
			else if(b>n2)
			{
				a=b-n2;
				memmove(temp+i-a,temp+i,strlen(temp+i)+1);
				for(i=(i-b)+1,k=0;k<n2;i++,k++)
					temp[i]=arr2[k];
				i=i-a;
			}
			else if(b==n2)
			{
				for(i=(i-b)+1,k=0;k<n2;i++,k++)
					temp[i]=arr2[k];
			}
		}
	}
		temp[i]=10;
		return ;
	
}
int checkmacro(char *str,int n,char *arr)
{
	int j,i,cnt=0,c;	
	for(j=0,i=0;str[j]!=10;j++)
	{
		if(str[j]==arr[i])
		{
			cnt++;
			i++;
			c=j;
		}
		else
		{
			i=0;
			continue;
		}
	}
	if(cnt==n)
		return c+1;
	return 0;
}
void storenamevalue(char *str,char *ptr1,char *ptr2,int n)
{
	int i,j,k,c=0,l,flag=0;
	      for(i=n+1,j=0;str[i]!=10;i++)
	      { 
		      if(str[i]!=32)
		      {
		              flag=1;
			      c=j++;
			      ptr1[c]=str[i];
			      l=i;
			      
		      }
		      else
		      {
			      j=0;
		      if(flag==1&&j==0) 
			      break;
		      continue;
		      }
	      }
	      ptr1[c+1]=0;
	      for(k=l+1,j=0;str[k]!=10;k++)
	      {
		      if(str[k]!=32)
		        ptr2[j++]=str[k];
		      else 
		      { 
			      j=0;
			      continue;
		      }
	      }
	      ptr2[j]=0;
	      return ;
}

