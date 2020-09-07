#include<stdio.h>
#include<stdlib.h>
//#include<unistd.h>
#include<time.h>

typedef enum{false,true}bool;
static long long unsigned iterat=0;//iterat
static long long  max_val=100;
static long long unsigned count_realloc=0;


char* 
init_matrix_1(char * matrix,  void * fun){
	if(iterat > (1<<16)) return matrix;//2^16
	bool(*f)(char*) = fun;
	if(f(matrix)==true) return matrix;
	matrix= realloc(matrix, sizeof(matrix)*2*++count_realloc);
	return init_matrix_1(matrix, fun);
}

bool 
my_fun_deprecated(void){
	iterat++;
	if(iterat>max_val) return true;
	return false;
}
bool my_fun(char*m){
	iterat++;
	if(max_val < 0){
		m[iterat-1]=rand() % 127;
		printf("%d\t", m[iterat-1]);
		//sleep(1);
		return false;
	}
	
	if(iterat>max_val) return true;
	return false;

}

int
main(int arc, char**argv, char**env){
	if(arc > 1) max_val = atoi(argv[1]);
	srand(time(NULL));
	char * m = (char*) malloc(1);//char is one byte almost everywhere
	m=init_matrix_1(m, my_fun);
	system("clear||cls");
	puts("Your matrix(reversed): \n");
	for(iterat;iterat--;){
		m[iterat-1]=rand() % 127;
		printf("%d\t", m[iterat-1] );
	}
	puts("\n");
	
}

