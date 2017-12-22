#include <stdio.h>

void test(char *str, char *to_find, int n, 
	int m, int i, int j, int *tee)
{
	if (j>m && str[i]==to_find[0])
		*tee = i;
	else if (j>m && str[i]!=to_find[0])
		*tee = -1;
	else
	{
		while (i<=n-m)
		{
			if (str[i]==to_find[0])
			{
				while (j<=m)
				{
					if (str[i+j]==to_find[j])
						return test(str, to_find, n, m, i, j+1, tee);
					else
						return test(str, to_find, n, m, i+1, 0, tee);
				}
			}
			else
				return test(str, to_find, n, m, i+1, 0, tee);
		}
	}
}
	
char *ft_strstr(char *str, char *to_find)
{
	int m=0, n=0;

	while (str[n])
		++n;
	while (to_find[m])		
		++m;
	--n;
	--m;

	int te=-1;
	int *tee;
	tee=&te;

	test(str, to_find, n, m, 0, 0, tee);

	if (te!=-1)
	{
		int i=0;
		while (i>=0 && i<n+1)
		{
			if (i+te<n+1)
			{
				str[i]=str[i+te];
				++i;
			}
			else
			{
				str[i]='\0';
				i++;
			}
		}
		return str;
	}
	else
		return NULL;
}

int		main(int argc, char **argv)
{
	if (argc < 3)
		printf("ta gueule\n");
	else
		printf("%s\n", ft_strstr(argv[1], argv[2]));
	return 0;
}