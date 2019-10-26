#include <unistd.h>
int read_word(int fd){
	int rWord;
	read(fd,&rWord,sizeof(int));
	return rWord;
}
short read_half(int fd){
	short rWord;
	read(fd,&rWord,sizeof(short));
	return rWord;
}
void write_word(int fd, int word){
	write(fd,&word,sizeof(word));
}
void write_half(int fd, short word){
	write(fd,&word,sizeof(word));
}
