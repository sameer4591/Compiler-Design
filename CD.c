
Left factoring

#include<stdio.h>
#include<string.h>
int main()
{
    char gram[20],part1[20],part2[20],modifiedGram[20],newGram[20],tempGram[20];
    int i,j=0,k=0,l=0,pos;
    printf("Enter Production : A->");
    gets(gram);
    for(i=0;gram[i]!='|';i++,j++)
        part1[j]=gram[i];
    part1[j]='\0';
    for(j=++i,i=0;gram[j]!='\0';j++,i++)
        part2[i]=gram[j];
    part2[i]='\0';
    for(i=0;i<strlen(part1)||i<strlen(part2);i++){
        if(part1[i]==part2[i]){
            modifiedGram[k]=part1[i];
            k++;
            pos=i+1;
        }
    }
    for(i=pos,j=0;part1[i]!='\0';i++,j++){
        newGram[j]=part1[i];
    }
    newGram[j++]='|';
    for(i=pos;part2[i]!='\0';i++,j++){
        newGram[j]=part2[i];
    }
    modifiedGram[k]='X';
    modifiedGram[++k]='\0';
    newGram[j]='\0';
    printf("\nGrammar Without Left Factoring : : \n");
    printf(" A->%s",modifiedGram);
    printf("\n X->%s\n",newGram);
}









First and Follow

#include <ctype.h>
#include <stdio.h>
#include <string.h>
void followfirst(char, int, int);
void follow(char c);
void findfirst(char, int, int);
int count, n = 0;
char calc_first[10][100];
char calc_follow[10][100];
int m = 0;

char production[10][10];
char f[10], first[10];
int k;
char ck;
int e;

int main(int argc, char** argv)
{
	int jm = 0;
	int km = 0;
	int i, choice;
	char c, ch;
	count = 8;

	strcpy(production[0], "X=TnS");
	strcpy(production[1], "X=Rm");
	strcpy(production[2], "T=q");
	strcpy(production[3], "T=#");
	strcpy(production[4], "S=p");
	strcpy(production[5], "S=#");
	strcpy(production[6], "R=om");
	strcpy(production[7], "R=ST");

	int kay;
	char done[count];
	int ptr = -1;

	for (k = 0; k < count; k++) {
		for (kay = 0; kay < 100; kay++) {
			calc_first[k][kay] = '!';
		}
	}
	int point1 = 0, point2, xxx;

	for (k = 0; k < count; k++) {
		c = production[k][0];
		point2 = 0;
		xxx = 0;

		for (kay = 0; kay <= ptr; kay++)
			if (c == done[kay])
				xxx = 1;

		if (xxx == 1)
			continue;

		findfirst(c, 0, 0);
		ptr += 1;
t
		done[ptr] = c;
		printf("\n First(%c) = { ", c);
		calc_first[point1][point2++] = c;

		for (i = 0 + jm; i < n; i++) {
			int lark = 0, chk = 0;

			for (lark = 0; lark < point2; lark++) {

				if (first[i] == calc_first[point1][lark]) {
					chk = 1;
					break;
				}
			}
			if (chk == 0) {
				printf("%c, ", first[i]);
				calc_first[point1][point2++] = first[i];
			}
		}
		printf("}\n");
		jm = n;
		point1++;
	}
	printf("\n");
	printf("-----------------------------------------------"
		"\n\n");
	char donee[count];
	ptr = -1;
	for (k = 0; k < count; k++) {
		for (kay = 0; kay < 100; kay++) {
			calc_follow[k][kay] = '!';
		}
	}
	point1 = 0;
	int land = 0;
	for (e = 0; e < count; e++) {
		ck = production[e][0];
		point2 = 0;
		xxx = 0;

		for (kay = 0; kay <= ptr; kay++)
			if (ck == donee[kay])
				xxx = 1;

		if (xxx == 1)
			continue;
		land += 1;

		follow(ck);
		ptr += 1;

		donee[ptr] = ck;
		printf(" Follow(%c) = { ", ck);
		calc_follow[point1][point2++] = ck;

		for (i = 0 + km; i < m; i++) {
			int lark = 0, chk = 0;
			for (lark = 0; lark < point2; lark++) {
				if (f[i] == calc_follow[point1][lark]) {
					chk = 1;
					break;
				}
			}
			if (chk == 0) {
				printf("%c, ", f[i]);
				calc_follow[point1][point2++] = f[i];
			}
		}
		printf(" }\n\n");
		km = m;
		point1++;
	}
}

void follow(char c)
{
	int i, j;


	if (production[0][0] == c) {
		f[m++] = '$';
	}
	for (i = 0; i < 10; i++) {
		for (j = 2; j < 10; j++) {
			if (production[i][j] == c) {
				if (production[i][j + 1] != '\0') {

					followfirst(production[i][j + 1], i,
								(j + 2));
				}

				if (production[i][j + 1] == '\0'
					&& c != production[i][0]) {

					follow(production[i][0]);
				}
			}
		}
	}
}

void findfirst(char c, int q1, int q2)
{
	int j;
nal
	if (!(isupper(c))) {
		first[n++] = c;
	}
	for (j = 0; j < count; j++) {
		if (production[j][0] == c) {
			if (production[j][2] == '#') {
				if (production[q1][q2] == '\0')
					first[n++] = '#';
				else if (production[q1][q2] != '\0'
						&& (q1 != 0 || q2 != 0)) {
		
					findfirst(production[q1][q2], q1,
							(q2 + 1));
				}
				else
					first[n++] = '#';
			}
			else if (!isupper(production[j][2])) {
				first[n++] = production[j][2];
			}
			else {

				findfirst(production[j][2], j, 3);
			}
		}
	}
}

void followfirst(char c, int c1, int c2)
{
	int k;

	if (!(isupper(c)))
		f[m++] = c;
	else {
		int i = 0, j = 1;
		for (i = 0; i < count; i++) {
			if (calc_first[i][0] == c)
				break;
		}

		while (calc_first[i][j] != '!') {
			if (calc_first[i][j] != '#') {
				f[m++] = calc_first[i][j];
			}
			else {
				if (production[c1][c2] == '\0') {

					follow(production[c1][0]);
				}
				else {

					followfirst(production[c1][c2], c1,
								c2 + 1);
				}
			}
			j++;
		}
	}
}








Predictive parsing


#include <stdio.h>
#include <string.h>


char prol[7][10] = { "S", "A", "A", "B", "B", "C", "C" };
char pror[7][10] = { "A", "Bb", "Cd", "aB", "@", "Cc", "@" };
char prod[7][10] = { "S->A", "A->Bb", "A->Cd", "B->aB", "B->@", "C->Cc", "C->@" };
char first[7][10] = { "abcd", "ab", "cd", "a@", "@", "c@", "@" };
char follow[7][10] = { "$", "$", "$", "a$", "b$", "c$", "d$" };


int numr(char c) {
    switch (c) {
        case 'S': return 0;
        case 'A': return 1;
        case 'B': return 2;
        case 'C': return 3;
        case 'a': return 0;
        case 'b': return 1;
        case 'c': return 2;
        case 'd': return 3;
        case '$': return 4;
    }
    return 2; 
}

int main() {
    int i, j, k;

    char table[5][6][10];
    for (i = 0; i < 5; i++)
        for (j = 0; j < 6; j++)
            strcpy(table[i][j], " ");

    for (i = 0; i < 7; i++) {
        k = strlen(first[i]);
        for (j = 0; j < 10; j++) {
            if (first[i][j] != '@')
                strcpy(table[numr(prol[i][0]) + 1][numr(first[i][j]) + 1], prod[i]);
        }
    }
    for (i = 0; i < 7; i++) {
        if (strlen(pror[i]) == 1) {
            if (pror[i][0] == '@') {
                k = strlen(follow[i]);
                for (j = 0; j < k; j++)
                    strcpy(table[numr(prol[i][0]) + 1][numr(follow[i][j]) + 1], prod[i]);
            }
        }
    }

    strcpy(table[0][0], " ");
    strcpy(table[0][1], "a");
    strcpy(table[0][2], "b");
    strcpy(table[0][3], "c");
    strcpy(table[0][4], "d");
    strcpy(table[0][5], "$");
    strcpy(table[1][0], "S");
    strcpy(table[2][0], "A");
    strcpy(table[3][0], "B");
    strcpy(table[4][0], "C");

    printf("\nPredictive parsing table:\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 6; j++) {
            printf("%-10s", table[i][j]);
            if (j == 5)
                printf("\n--------------------------------------------------------\n");
        }
    }

    return 0;
}










Shift reduce parser

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int z = 0, i = 0, j = 0, c = 0;
char a[16], ac[20], stk[15], act[10]; 

void check()
{
	strcpy(ac,"REDUCE TO E -> "); 
	
	for(z = 0; z < c; z++) 
	{
		if(stk[z] == '4') 
		{
			printf("%s4", ac);
			stk[z] = 'E';
			stk[z + 1] = '\0';
	
			printf("\n$%s\t%s$\t", stk, a); 
		}
	}
		
	for(z = 0; z < c - 2; z++)
	{
		if(stk[z] == '2' && stk[z + 1] == 'E' && 
								stk[z + 2] == '2') 
		{
			printf("%s2E2", ac);
			stk[z] = 'E';
			stk[z + 1] = '\0';
			stk[z + 2] = '\0';
			printf("\n$%s\t%s$\t", stk, a);
			i = i - 2;
		}
		
	}
		
	for(z=0; z<c-2; z++)
	{
		if(stk[z] == '3' && stk[z + 1] == 'E' && 
								stk[z + 2] == '3') 
		{
			printf("%s3E3", ac);
			stk[z]='E';
			stk[z + 1]='\0';
			stk[z + 1]='\0';
			printf("\n$%s\t%s$\t", stk, a);
			i = i - 2;
		}
	}
	return ;
}

int main()
{
	printf("GRAMMAR is -\nE->2E2 \nE->3E3 \nE->4\n"); 

	strcpy(a,"32423"); 
c
	c=strlen(a); 

	strcpy(act,"SHIFT"); 
	
	printf("\nstack \t input \t action"); 

	printf("\n$\t%s$\t", a); 
	
	for(i = 0; j < c; i++, j++) 
	{
		printf("%s", act); 
	
		stk[i] = a[j];	 
		stk[i + 1] = '\0';

		a[j]=' ';

		printf("\n$%s\t%s$\t", stk, a); 
	
		check(); 
	}
	

	check(); 
	if(stk[0] == 'E' && stk[1] == '\0') 
		printf("Accept\n");
	else //else reject
		printf("Reject\n");
}


