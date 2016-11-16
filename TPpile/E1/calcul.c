#include"pile.h"


int trans(char n){
	if(n=='1'){
		return 1;
	}
	if(n=='2'){
		return 2;
	}
	if(n=='3'){
		return 3;
	}
	if(n=='4'){
		return 4;
	}
	if(n=='5'){
		return 5;
	}
	if(n=='6'){
		return 6;
	}
	if(n=='7'){
		return 7;
	}
	if(n=='8'){
		return 8;
	}
	if(n=='9'){
		return 9;
	}
	if(n=='0'){
		return 0;
	}
	return -1;
}


void main(){
	int a,b,r;
	int i=0;
	char exp[N];
	printf("Donner l'expression :");
	scanf("%s",exp);
	while(exp[i]){
		if(isdigit(exp[i])){
			empiler(trans(exp[i]));	
		}
		else{
			depiler(&a);
			depiler(&b);
			if(exp[i]=='+'){
				empiler(a+b);
			}
			if(exp[i]=='-'){
				empiler(a-b);
			}
			if(exp[i]=='*'){
				empiler(a*b);
			}
			if(exp[i]=='/'){
				empiler(a/b);	
			}
	
		}
		
		i++;
	}
	depiler(&r);
	printf("Le résultat est %i\n",r);
	

}
