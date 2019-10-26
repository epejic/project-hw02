typedef float cmplx_t[2];
int main(){
	double mag,phs;
	scanf("%f %f",&mag,&phs);
	printf("\n%f",cmplx_real(mag,phs));

}
