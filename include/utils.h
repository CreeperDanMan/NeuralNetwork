#ifndef UTILS_H
#define UTILS_H


#include "utils.h"
#include <stdio.h>
#include <math.h>

struct NeuralNetwork;
struct dataset;


float* getProbaVector(struct NeuralNetwork *network);

void setInputVector(struct NeuralNetwork *network, const float *vector);

unsigned int getParameterNumber(struct NeuralNetwork *network);

float maximum(const float *v, const unsigned int vSize, const unsigned int vectorFirstIndex);


void softmaxVector(const float *v, float *p, const unsigned int firstIndex, const unsigned int lastIndex, const unsigned int probaVectorSize);



void displayProbaVector(struct NeuralNetwork *network);

void displayInputVector(struct NeuralNetwork *network);

void copyDatasetInput(struct NeuralNetwork *network, struct dataset *data, unsigned int offset);




#endif // UTILS_H