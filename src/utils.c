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

float maximum(const float *v, const unsigned int vSize, const unsigned int vectorFirstIndex) {
	if (vSize<=0) {
		fprintf(stderr, "ERREUR : taille de tableau inférieure ou égale à 0");
		exit(1);
	}
	if (vectorFirstIndex>=vSize) {
		fprintf(stderr, "ERREUR : first index (%u) greater than size of the array (%u)\n", vectorFirstIndex, vSize);
		exit(1);
	}

	float max = v[vectorFirstIndex];
	for (unsigned int i = vectorFirstIndex+1; i<vSize; i++) {
		max = v[i]>max ? v[i] : max;
	}
	return max;
}



void softmaxVector(const float *v, float *p, const unsigned int firstIndex, const unsigned int lastIndex, const unsigned int probaVectorSize) {
	if (lastIndex==0) {
		fprintf(stderr,"ERREUR : vecteur d'entrée de softmax VIDE");
		exit(1);
	}
	if (firstIndex>=lastIndex) {
		fprintf(stderr, "ERREUR : index de début supérieur à l'index de fin");
		exit(1);
	}
	if (probaVectorSize==0) {
		fprintf(stderr, "ERREUR : probaVectorSize nul\n");
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
		printf("Output Layer n %u value : %f\n", i, network -> probaVector[i]);
	}
}

void displayInputVector(struct NeuralNetwork *network) {
	for (unsigned int i = 0; i<network ->layerSize[0]; i++) {
		printf("Output Layer n %u value : %f\n", i, network -> inputVector[i]);
	}
}


void copyDatasetInput(struct NeuralNetwork *network, struct dataset *data, unsigned int offset) {
	if (offset>data->datasetSize) {
		fprintf(stderr, "ERREUR : offset supérieur à la taille du dataset");
		exit(1);
	}
	memcpy(network->inputVector, data->inputDataset+data->inputOffset*offset, data->inputOffset);
}

