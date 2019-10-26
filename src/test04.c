typedef float cmplx_t[2];
int main(){
	cmplx_t input1;
	scanf("%f %f",&input1[0],&input1[1]);
	printf("\n%f",cmplx_phs(input1));

}
