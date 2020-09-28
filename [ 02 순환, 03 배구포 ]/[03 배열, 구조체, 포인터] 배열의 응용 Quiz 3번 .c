#include <stdio.h>
#define MAX 101
//첫번째 방법으로 다형식의 뺄셈을 구현하시오 

typedef struct {
	int degree;
	float coef [MAX];
} polynomial;

int maxof(polynomial A, polynomial B){
	if (A.degree > B.degree) return A.degree;
	else B.degree;
}

polynomial add1 (polynomial A, polynomial B){
	polynomial C;
	int Apos=0,Bpos=0, Cpos=0;		//배열의 인덱스를 뜻하는 변수 
	int degree_a= A.degree;		//_붙은건 조절수야  (조절하면서 조건을 맞춘다는 뜻) 
	int degree_b= B.degree;		//_붙은 degree는 위에서부터 내려올거야 
	C.degree=maxof(A,B);
	
	while (Apos <= A.degree && Bpos <= B.degree){	
		if (degree_a > degree_b){
			C.coef[Cpos++]=A.coef[Apos++];
			degree_a--; 
		} 
		else if (degree_a == degree_b){
			C.coef[Cpos++]= A.coef[Apos++] + B.coef[Bpos++];
			degree_a--; degree_b--;
		}
		else {
			C.coef[Cpos++]=B.coef[Bpos++];
			degree_b--;
		}
	}
	return C;
	
} 

polynomial sub1 (polynomial AA, polynomial BB){
	polynomial CC;
	int AApos=0, BBpos=0, CCpos=0;
	int degree_aa = AA.degree;
	int degree_bb = BB.degree;
	CC.degree= maxof(AA ,BB);
	
	while (AApos <= AA.degree && BBpos <= BB.degree){
		if (degree_aa > degree_bb){
			CC.coef[CCpos++] = AA.coef[AApos++];
			degree_aa--; 
		}
		else if (degree_aa == degree_bb){
			CC.coef[CCpos++] = AA.coef[AApos++] -BB.coef[BBpos++];
			degree_aa--; degree_bb--;  
			
		}
		else {
			CC.coef[CCpos++] = -BB.coef[BBpos++];
			degree_bb--;
		}
	}
	return CC;
}

void print_polynomial(polynomial p){
	int i;
	for (i=p.degree; i>0; i--){
		if (p.coef[p.degree-i]==0) continue;
		printf("%3.1fx^%d + ", p.coef[p.degree-i],i);
	}
		
	printf("%3.1f\n", p.coef[p.degree]);
}

int main (){
	polynomial a= {3,{4,2,0,5}};
	polynomial b= {3,{2,6,0,4}};
	polynomial c;
	
	c=add1(a,b);
	print_polynomial(a);
	print_polynomial(b);
	printf("--------------------------------------------\n");
	print_polynomial(c);
	printf("\n\n\n");
	
	polynomial aa= {3,{4,2,0,5}};
	polynomial bb= {3,{2,6,0,4}};
	polynomial cc= sub1(aa,bb);
	print_polynomial(aa);
	print_polynomial(bb);
	printf("--------------------------------------------\n");
	print_polynomial(cc);
	
	return 0;
}
