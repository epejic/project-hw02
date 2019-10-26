typedef float cmplx_t[2];
int main(){
	cmplx_t input[5],output[5];
	for(int i=0;i<4;i++){
		scanf("%f %f",&input[i][0],&input[i][1]);
	}
	cmplx_dft(input,output,5);
	for(int i=0;i<4;i++){
		printf("\n%f %f",output[i][0],output[i][1]);
	}
}
