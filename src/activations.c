#include "activations.h"


float sigmoid(const float x){
        return 1.0f/(1.0f+expf(-x));
}

float sigmoidDerivative(const float x){
        return sigmoid(x)*(1.0f-sigmoid(x));
}

float ReLU(const float x) {
	return fmax(0.0f,x);
}

float ReLUDerivative(const float x) {
	return x>=0.0f ? 1.0f : 0.0f;
}

float SoftPlus(const float x) {
	return logf(1.0f+expf(x));
}

float leakyReLU(const float a, const float x) {
	return x>=0.0f ? x : a*x;
}

float eLU(const float a, const float x) {
	return x>=0.0f ? x : a*(expf(x)-1);
}

float eLUDerivative(const float a, const float x) {
	return x>=0.0f ? a*expf(x) : 1;
}

float SiLU(const float x) {
	return x*(1.0f/(1+expf(-x)));
}

float SiLUDerivative(const float x) {
	return x*SiLU(x)+sigmoid(x);
}
