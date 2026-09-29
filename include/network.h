#ifndef NETWORK_H
#define NETWORK_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "utils.h"
#include <stdbool.h>


// À ce jour les layers sont définis par des constantes (plus tard par arguments de lancement)

#define HIDDEN_LAYERS 2
#define HIDDEN_LAYERS_SIZE 32


// == DATASTRUCTURE DU RÉSEAU DE NEURONES ==

// Fonctionnement : sigmoid_activation(SOMME(output⁻1 * poids))
// Usage de tableaux 1D pour la linéarité + vectorisation automatique
// Calcul de coordonnées d'un neurone : index = neuronOffset[L]+j
// Neurone étant inférieur à layerSize

// Calcul de coordonnées d'un poids (reliant un neurone i à un neurone j de la couche L
// index = weightOffset[L] + (i*layerSize[L]) + j

// LayerOffset et layerSize de même taille mais layerOffset[n+1] =  layerOffset[n]+layerSize[n]
struct NeuralNetwork {

	float *biais;  // Contiens les biens de tous les neurones
	float *weight; // Contiens les poids de toutes les couches pour chaque neurone
	float *output; // Contiens toutes les activations de neurones actuelles

	unsigned int    numLayers; // Nombre de couches (input et output comprises)
	unsigned int   *layerSize; // Tailles de couches (ex. 64, 128, 256, 784)
	unsigned int   *nbWeightPerLayer; // Tableau appposant le nombre de poids par neurone POUR CHAQUE LAYER - pourrais faciliter l'implémentation future de hidden layers à taiiles variables

	unsigned int   *layerOffset; // Sers au calcul de coordonnees du réseau (=> layerOffset[2] = 1er neurone de la 2e couche du réseau)
	unsigned int   *weightOffset;

	unsigned int    numberOfNeurons; // Data Supplémentaire au cas où
	unsigned int    numberOfWeight;
	unsigned int	probaVectorSize;

	float *inputVector; // Permet de faciliter la forward pass ET d'éviter des réallocation couteuses par malloc
	float *probaVector;
};

struct dataset;

void initFromDataset(struct NeuralNetwork *network, struct dataset *data);

void neuralNetworkInitialisation (struct NeuralNetwork *network, unsigned int inputLayerSize, unsigned int outputLayerSize);

void networkMemoryInitialisation(struct NeuralNetwork *network, unsigned int inputLayerSize, unsigned int outputLayerSize);

void freeNetworkAllocation(struct NeuralNetwork *network);



void weightOffsetInitialisation(unsigned int *weightOffset, const unsigned int *layerOffset, const unsigned int *layerSize, const unsigned int numLayers);

void biaisInitialisation(float *biaisArray, const unsigned int arraySize, const float arbitraryNumber);

void randomBiaisInitialisation(float * biaisArray, const unsigned int arraySize);

void randomWeightInitialisation(const unsigned int weightTotalNumber, float *weight);




#endif // NETWORK_H