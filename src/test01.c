typedef float cmplx_t[2];
int main(){
	cmplx_t input1,input2,output;
	scanf("%f %f",&input1[0],&input1[1]);
	scanf("%f %f",&input2[0],&input2[1]);
	cmplx_div(input1,input2,output);
	printf("\n%f %f i",output[0],output[1]);

}
