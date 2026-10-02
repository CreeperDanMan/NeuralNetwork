#include "utils.h"
#include "network.h"
#include "dataset.h"

float* getProbaVector(struct NeuralNetwork *network) {
	return network -> probaVector;
}

void setInputVector(struct NeuralNetwork *network, const float *vector) { // à ce point, si l'utilisateur rentre un vecteur de mauvaise taille, c'est qu'il l'a voulu
	for (unsigned int i = 0; i<network->probaVectorSize; i++) {
		network -> probaVector[i] = vector[i];
	}
}

unsigned int getParameterNumber(struct NeuralNetwork *network) {
	return network->numberOfWeight+network->numberOfNeurons;
}

float maximum(const float *vector, const unsigned int vSize, const unsigned int vectorFirstIndex) {
	if (vSize<=0) {
		fprintf(stderr, "ERREUR : taille de tableau inférieure ou égale à 0\n");
		exit(1);
	}
	if (vectorFirstIndex>=vSize) {
		fprintf(stderr, "ERREUR : Premier index (%u) plus grand que la taille de l'array (%u)\n", vectorFirstIndex, vSize);
		exit(1);
	}

	float max = vector[vectorFirstIndex];
	for (unsigned int i = vectorFirstIndex+1; i<vSize; i++) {
		max = vector[i]>max ? vector[i] : max;
	}
	return max;
}



void softmaxVector(const float *v, float *p, const unsigned int firstIndex, const unsigned int lastIndex, const unsigned int probaVectorSize) {
	if (lastIndex==0) {
		fprintf(stderr,"ERREUR : vecteur d'entrée de softmax VIDE\n");
		exit(1);
	}
	if (firstIndex>=lastIndex) {
		fprintf(stderr, "ERREUR : index de début supérieur à l'index de fin\n");
		exit(1);
	}
	if (probaVectorSize==0) {
		fprintf(stderr, "ERREUR : taille de vecteur de sortie nulle\n");
		exit(1);
	}
	if (lastIndex-firstIndex!=probaVectorSize) {
		fprintf(stderr, "ERREUR : taille du vecteur de sortie inférieur à la taille du parcours du vecteur d'entrée\n");
		exit(1);
	}

	float max = maximum(v, lastIndex, firstIndex);
	float sumNormalisation = 0.0f;

	// Calcul des exponentielles
	for (unsigned int i = 0; i<probaVectorSize; i++) {
		p[i] = expf(v[firstIndex+i] - max); 
		sumNormalisation+=p[i];
	}

	if (sumNormalisation==0) {
		fprintf(stderr, "ERREUR : division par 0");
		exit(1);
	}

	// Normalisation
	for (unsigned int i = 0; i<probaVectorSize; i++) {
		p[i]/=sumNormalisation;
	}
}


void displayProbaVector(struct NeuralNetwork *network) {
	for (unsigned int i = 0; i<network -> probaVectorSize; i++) {
		printf("Output Layer n %u : %f\n", i, network -> probaVector[i]);
	}
}

void displayInputVector(struct NeuralNetwork *network) {
	for (unsigned int i = 0; i<network ->layerSize[0]; i++) {
		printf("Output Layer n %u : %f\n", i, network -> inputVector[i]);
	}
}


void copyDatasetInput(struct NeuralNetwork *network, struct dataset *data, unsigned int offset) {
	if (offset>data->datasetSize) {
		fprintf(stderr, "ERREUR : offset supérieur à la taille du dataset\n");
		exit(1);
	}
	memcpy(network->inputVector, data->inputDataset+data->inputOffset*offset, data->inputOffset);
}


void zeroInitialisation(float *array, unsigned int arraySize) {
	for (unsigned int i = 0; i<arraySize; i++) {
		array[i] = 0;
	}
}