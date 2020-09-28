#include <stdio.h>
//두번째 방법으로 다항식의 뺄셈을 표현하사오 
#define MAX 101 

typedef struct {
	float coef;
	int expon;
} polynomial;

polynomial fam[MAX]={{1,3}, {-1, 0},  {5,3},{8,2},{10,0}};
int avail=5;			//전역변수 

char compare (int a, int b){
	if (a>b) return '>';
	else if (a==b) return '=';
	else return '<';
}
void attach(float coef, int expon){
	fam[avail].coef=coef;
	fam[avail].expon=expon;
	avail++;
}
void  poly_add2 (int As, int Ae, int Bs, int Be, int *Cs, int * Ce){
	float tempcoef;
	*Cs=avail;
	
	while (As <= Ae && Bs<= Be){
		switch (compare (fam[As].expon, fam[Bs].expon)){
		case '>':
			attach (fam[As].coef, fam[As].expon);
			As++; break;
			
		case '=':
			tempcoef= fam[As].coef + fam[Bs].coef;
			if (tempcoef)
				attach (tempcoef, fam[As].expon);
			As++; Bs++; break;
			
		case '<':
			attach (fam[Bs].coef, fam[Bs].expon);
			Bs++; break;
		}
	}
	for (; As <=Ae ; As++)
		attach (fam[As].coef, fam[As].expon);
	for (; Bs <=Be ; Bs++)
		attach (fam[Bs].coef, fam[Bs].expon);
	*Ce=avail-1;
}

void poly_sub2 (int As, int Ae, int Bs, int Be, int *Cs, int *Ce){
	float tempcoef;
	while (As<=Ae && Bs<=Be){
		switch (compare(fam[As].expon, fam[Bs].expon)){
		case '>':
			attach(fam[As].coef, fam[As].expon);
			As++; break;
			
		case '=':
			tempcoef= fam[As].coef - fam[Bs].coef;
			attach (tempcoef, fam[As].expon);
			As++; Bs++; break;
			
		case '<':
			attach(-fam[Bs].coef, fam[Bs].expon);
			Bs++; break;
		}
	}
	for (;As<=Ae;As++)
		attach (fam[As].coef, fam[As].expon);
	for (;Bs<Be;Bs++)
		attach (-fam[Bs].coef, fam[Bs].expon);
	*Ce=avail-1;
}

void print_poly (int s, int e){
	int i;
	for (i=s;i<e;i++)
		printf("%3.1fx^%d + ", fam[i].coef, fam[i].expon);
	printf("%3.1fx^%d\n", fam[e].coef, fam[i].expon);
}
//{{1,3}, {-1, 0},  {5,3},{8,2},{10,0}}
int main (){
	int As=0, Ae=1, Bs=2, Be=4, Cs, Ce;
	poly_add2(As, Ae, Bs, Be, &Cs, &Ce);
	
	print_poly(As,Ae);
	print_poly(Bs,Be);
	printf("------------------------------------------\n");
	print_poly(Cs,Ce);
	
	printf("\n\n\n");
	
	fam[Ce+1].coef= 1.0; 	fam[Ce+1].expon= 3;	As=Ce+1;
	fam[Ce+2].coef= -1.0;	fam[Ce+2].expon= 0;	Ae=Ce+2;
	
	fam[Ce+3].coef= 5.0;	fam[Ce+3].expon= 3;	Bs=Ce+3;
	fam[Ce+4].coef= 8.0;	fam[Ce+4].expon= 2;
	fam[Ce+5].coef= 10.0;	fam[Ce+5].expon= 0;	Be=Ce+5;
	
	Cs= avail= Ce+6;
	Ce= avail;
	
	poly_sub2(As, Ae, Bs, Be, &Cs, &Ce);
	print_poly(As,Ae);
	print_poly(Bs,Be);
	printf("------------------------------------------\n");
	print_poly(Cs,Ce);
	
	return 0;
}
