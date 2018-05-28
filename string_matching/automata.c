#include<stdio.h>
#include<string.h>
#define CHARS 256
 
int NextS(char *pat, int L, int s, int c)
{
    if (s < L && c == pat[s])
        return s+1;
    int n, i;
    for (n = s; n > 0; n--)
    {
        if (pat[n-1] == c)
        {
            for (i = 0; i < n-1; i++)
                if (pat[i] != pat[s-n+1+i])
                    break;
            if (i == n-1)
                return n;
        }
    }
 
    return 0;
}
void table(char *pat, int L, int t[][CHARS])
{
    int s,c;
    for (s = 0; s <= L; ++s)
        for (c = 0; c < CHARS; ++c)
            t[s][c] = NextS(pat, L, s, c);
}
void search(char *pat, char *txt)
{
    int L = strlen(pat);
    int N = strlen(txt);
    int t[L+1][CHARS];
    table(pat, L, t);
    int i, s=0;
    for (i = 0; i < N; i++)
    {
        s = t[s][txt[i]];
        if (s == L)
            printf ("\n Pattern found at index %d",i-L+1);
    }
}
int main()
{
	char txt[1000],pat[100];
	FILE *f=fopen("2.txt","r");
	while(!feof(f))
	{
		fscanf(f,"%s\n",txt);
		fscanf(f,"%s\n",pat);
		printf("%s\n",txt);
		printf("%s\n",pat);
    }
    search(pat, txt);
    return 0;
}
