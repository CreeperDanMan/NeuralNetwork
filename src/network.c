#include "network.h"
#include "activations.h"
#include "dataset.h"

// initFromSave et initFromDataset

// Ajouter LayerSize
void initFromDataset(struct NeuralNetwork *network, struct dataset *data) {
	neuralNetworkInitialisation(network, data->inputOffset, data->outputOffset);
}

void neuralNetworkInitialisation (struct NeuralNetwork *network, unsigned int inputLayerSize, unsigned int outputLayerSize) {
	network -> numLayers = 2+HIDDEN_LAYERS;

	network -> numberOfNeurons = inputLayerSize+outputLayerSize+(HIDDEN_LAYERS*HIDDEN_LAYERS_SIZE);

	networkMemoryInitialisation(network, inputLayerSize, outputLayerSize);

	// Initialisation des poids et du tableau d'offset

	weightOffsetInitialisation(network -> weightOffset, network -> layerOffset, network -> layerSize, network -> numLayers);
	randomWeightInitialisation(network -> numberOfWeight, network -> weight);

	// Initialisation des biais
	biaisInitialisation(network -> biais, network -> numberOfNeurons, 0.01);
}





void networkMemoryInitialisation(struct NeuralNetwork *network, unsigned int inputLayerSize, unsigned int outputLayerSize) {
	// ALLOCATION DE LA MEMOIRE

	network -> layerSize 	 = malloc(network -> numLayers*sizeof(int)); // Tableaux d'entiers
	network -> nbWeightPerLayer = malloc(network -> numLayers*sizeof(int));
	network -> biais 		 = malloc(network -> numberOfNeurons*sizeof(float)); // Tableaux de float
	network -> output		 = malloc(network -> numberOfNeurons*sizeof(float));

	network -> layerOffset = malloc(network -> numLayers*sizeof(int));


	if (network -> layerSize==NULL || network -> biais == NULL ||
	    network -> output == NULL || network -> layerOffset == NULL || network -> nbWeightPerLayer==NULL) {
		fprintf(stderr, "ERREUR D'ALLOCATION, POINTEUR NULL RETOURNE"); // si un pointeur est null à partir d'ici, alors l'utilisateur l'a voulu. gestion plus robuste plus tard si un jour j'ai le temps.
		exit(1);
	}

	// INITIALISATION DES ARRAYS
	network -> layerSize[0] = inputLayerSize;
	network -> layerOffset[0] =  0;
	network -> nbWeightPerLayer[0] = 0;

	network -> inputVector = malloc(network -> layerSize[0]*sizeof(float));

	if (network -> inputVector == NULL) {
		fprintf(stderr, "ERREUR D'ALLOCATION, POINTEUR NULL RETOURNE"); // si un pointeur est null à partir d'ici, alors l'utilisateur l'a voulu. gestion plus robuste plus tard si un jour j'ai le temps.
		exit(1);
	}

	network -> numberOfWeight = 0;
	for (unsigned int i = 1; i<network -> numLayers-1; i++) {
		network -> layerSize[i] = HIDDEN_LAYERS_SIZE; // Taille de hidden layers fixe
		network -> layerOffset[i] = network -> layerSize[i-1]+ network -> layerOffset[i-1]; // La coordonnée du 1er neurone de la couche actuelle est celle du dernier neurone de la couche précédente (nombre de neurone de cette couche) + 1

		network -> nbWeightPerLayer[i] = network -> layerSize[i-1] * network -> layerSize[i];

		network -> numberOfWeight += network -> nbWeightPerLayer[i];
	}


	network -> layerSize[network -> numLayers-1] = outputLayerSize;

	network -> probaVector = malloc(network -> layerSize[network->numLayers-1]*sizeof(float));
	network -> probaVectorSize = network -> layerSize[network->numLayers-1]; // égal à 0

	network -> layerOffset[network -> numLayers-1] = network -> layerSize[network -> numLayers-2] + network -> layerOffset[network -> numLayers-2]; // La taille du réseau ne sera jamais inférieure à 2 (entrée + sortie), donc pas de débordement de tableau ici
	network -> nbWeightPerLayer[network -> numLayers-1] = network -> layerSize[network -> numLayers-2] * network -> layerSize[network -> numLayers-1];

	network -> numberOfWeight += network -> nbWeightPerLayer[network -> numLayers-1];

    network -> weight = malloc(network -> numberOfWeight*sizeof(float));
	network -> weightOffset = malloc(network -> numberOfNeurons*sizeof(int));

	if (network -> weight == NULL || network -> weightOffset == NULL || network -> probaVector == NULL) {
		fprintf(stderr, "ERREUR D'ALLOCATION, POINTEUR NULL RETOURNE");
		exit(1);
	}
}



void freeNetworkAllocation(struct NeuralNetwork *network) {
	free(network -> layerSize);
	free(network -> biais);
	free(network -> output);
	free(network -> layerOffset);
	free(network -> inputVector);
	free(network -> probaVector);
	free(network -> weight);
	free(network -> weightOffset);
	free(network -> nbWeightPerLayer);
}




// == Initialisation du réseau ==

void biaisInitialisation(float *biaisArray, const unsigned int arraySize, const float arbitraryNumber) {
	if (arraySize==0) {
		fprintf(stderr, "ERREUR : array de biais vide");
		exit(1);
	}
	for (unsigned int i = 0; i<arraySize; i++) {
		biaisArray[i] = arbitraryNumber;
	}
}

void randomBiaisInitialisation(float * biaisArray, const unsigned int arraySize) { // ACTUELLEMENT NON UTILISÉ
	if (arraySize==0) {
		fprintf(stderr, "ERREUR : array de biais vide");
		exit(1);
	}
    for (unsigned int i = 0; i<arraySize; i++) {
           biaisArray[i] = (float)random()/(float)RAND_MAX;
    }

}


void randomWeightInitialisation(const unsigned int weightTotalNumber, float *weight) {
	if (weightTotalNumber==0) {
		fprintf(stderr, "Erreur : array de poids vide");
		exit(1);
	}
	for (unsigned int i = 0; i<weightTotalNumber; i++) {
		weight[i] = ((float)random()/(float)RAND_MAX)*0.1f-0.05f; // variable aléatoire pour les poids
	}
}



void weightOffsetInitialisation(unsigned int *weightOffset, const unsigned int *layerOffset, const unsigned int *layerSize, const unsigned int numLayers) {
	for (unsigned int i = 0; i<layerSize[0]; i++) {
		weightOffset[i] = 0;
	}

	unsigned int currentOffset = 0;

	for (unsigned int i = 1; i<numLayers; i++) {
		for (unsigned int j = 0; j<layerSize[i]; j++) {
			weightOffset[layerOffset[i]+j] = currentOffset+i;

			currentOffset+=layerSize[i-1];
		}
	}
	return;
}
