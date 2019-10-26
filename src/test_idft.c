typedef float cmplx_t[2];
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
	 int fd;
        cmplx_t inputTest[200];
        cmplx_t output[200];
	cmplx_t input[200];
        for(int i=0; i<200; i++){
                inputTest[i][0] = sin(2*50*M_PI*(float)(i+1)/200);
		inputTest[i][1] = 0;
        }
        fd = open("SomeFile.bin", O_RDONLY);
	//printf("%d",fd);
        for(int i = 0; i<200 ;i++){
                input[i][0] =(float)read_word(fd)/1;
                input[i][1] = (float)read_word(fd)/1;
		//printf("\n-->%f %f",input[i][0],input[i][1]);
        }
	cmplx_idft(input,output,200);
	for(int i = 0; i<200; i++){
		printf("\n %f %fi",output[i][0]-inputTest[i][0],output[i][1]-inputTest[i][1]);
		//printf("\n-->%f %f",output[i][0],output[i][1]);
	}
	close(fd);
}
