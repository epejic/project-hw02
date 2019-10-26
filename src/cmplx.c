#include <math.h>
typedef float cmplx_t[2];

// returns |a|
double cmplx_mag(cmplx_t a){
	return sqrt(a[0]*a[0]+a[1]*a[1]);
}

// returns phase in radians of a
double cmplx_phs(cmplx_t a){
	return atan(a[1]/a[0]);
}


// returns real part of mag/_phs
double cmplx_real(double mag, double phs){
	return mag*cos(phs);
}


// returns imaginary part of mag/_phs
double cmplx_imag(double mag, double phs){
	return mag*sin(phs);
}


// c = a / b;
void cmplx_div(cmplx_t a, cmplx_t b, cmplx_t c){
	c[0]=cmplx_real(cmplx_mag(a)/cmplx_mag(b),cmplx_phs(a)-cmplx_phs(b));
	c[1]=cmplx_imag(cmplx_mag(a)/cmplx_mag(b),cmplx_phs(a)-cmplx_phs(b));
}

// c = a * b;
void cmplx_mul(cmplx_t a, cmplx_t b, cmplx_t c){
	c[0]=cmplx_real(cmplx_mag(a)*cmplx_mag(b),cmplx_phs(a)+cmplx_phs(b));
	c[1]=cmplx_imag(cmplx_mag(a)*cmplx_mag(b),cmplx_phs(a)+cmplx_phs(b));

}


// returns dft transformation of complex input signal
void cmplx_dft(cmplx_t *input, cmplx_t *output, int N){
	for (int i = 0; i < N; i++) {
        double sumreal = 0;
        double sumimag = 0;
        for (int j = 0; j < N; j++) {
            double angle = 2 * M_PI * i * j / N;
            sumreal +=  input[j][0] * cos(angle) + input[j][1] * sin(angle);
            sumimag += -input[j][0] * sin(angle) + input[j][1] * cos(angle);
        }
        output[i][0] = sumreal;
        output[i][1] = sumimag;
    }
}
// returns inverse dft transformation of complex input signal
void cmplx_idft(cmplx_t *input, cmplx_t *output, int N){
	for (int i = 0; i < N; i++) {  
        double sumreal = 0;
        double sumimag = 0;
        for (int j = 0; j < N; j++) {  
            double angle = 2 * M_PI * i * j / N;
            sumreal += input[j][0] * cos(angle) + input[j][1] * sin(angle);
            sumimag += input[j][0] * sin(angle) + input[j][1] * cos(angle);
        }
        output[i][0] = sumreal/N;
        output[i][1] = sumimag/N;
    }
}
