typedef float cmplx_t[2];
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>


int main(){
	int fd;
	cmplx_t input[200];
	cmplx_t output[200];
	for(int i=0; i<=200; i++){
		input[i][0] = sin(2*50*M_PI*(float)(i+1)/200);
		//input[i][1] = 0;
		//input[i][0] = i;
	}
	fd = open("SomeFile.bin", O_CREAT | O_WRONLY);
	//printf("%d",fd);
	cmplx_dft(input,output,200);
	for(int i = 0; i<200 ;i++)
	{
		write_word(fd,(int)(output[i][0]*1));
		write_word(fd,(int)(output[i][1]*1));
		//printf("\n-->%f %f",output[i][0],output[i][1]);
	}
	close(fd);
}
