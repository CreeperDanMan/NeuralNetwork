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


/**
 * @struct NeuralNetwork
 * @brief Représente le réseau de neurones (ici un MultiLayer Perceptron / MLP)
 * 
 * Cette structure contiens les poids, biais et sorties du réseaux de neurones applatis en une dimension unique.
 * Chaque Neurone est accessible via un Offset par Layer, Chaque poids est accessible via un Offset par neurone. 
 * 
 * Les entrées et sorties du réseau sont différenciées de son état interne.
 */

struct NeuralNetwork {

	float *biais;  /**< Array à une dimension contenant les biais des neurones */
	float *weight; /**< Array à une dimension contenant les poids des neurones  */
	float *output; /**< Array à une dimension contenant la valeur de sortie des neurones */
	unsigned int *activationFunction; // A INITIALISAER /**< Array à une dimension attribuant une fonction d'activation par Layer */

	unsigned int    numLayers; /**< Variable contenant le nombre de layer du réseau */
	unsigned int   *layerSize; /**< Array à une dimension contenant la taille de chaque layer, permettant des tailles indépendantes par layer */
	unsigned int   *nbWeightPerLayer; /**< Array à une dimension contenant le nombre de poids par layer */

	unsigned int   *layerOffset; /**< Array à une dimension contenant l'offset de chaque layer dans output et biais, chaque index représentant la coordonnée du premier neurone de la couche sélectionnée */
	unsigned int   *weightOffset; /**< Array à une dimension contenant l'offset de chaque poids par neurone */

	unsigned int    numberOfNeurons; /**< Variable contenant le nombre de neurones du réseau */
	unsigned int    numberOfWeight; /**< Variable contenant le nombre de poids du réseau */
	unsigned int	probaVectorSize; /**< Variable contenant la taille de la couche de sortie */

	float *inputVector; /**< Array à une dimension contenant les entrées du réseau */
	float *probaVector; /**< Array à une dimension contenant la sortie normalisée par Softmax du réseau */
};

struct dataset;

void initFromDataset(struct NeuralNetwork *network, struct dataset *data);

void neuralNetworkInitialisation (struct NeuralNetwork *network, unsigned int inputLayerSize, unsigned int outputLayerSize);

void networkMemoryInitialisation(struct NeuralNetwork *network, unsigned int inputLayerSize, unsigned int outputLayerSize);

void freeNetworkAllocation(struct NeuralNetwork *network);


void weightOffsetInitialisation(unsigned int *weightOffset, const unsigned int *layerOffset, const unsigned int *layerSize, const unsigned int numLayers);

void biaisInitialisation(float *biaisArray, const unsigned int arraySize, const float arbitraryNumber);

void randomBiaisInitialisation(float * biaisArray, const unsigned int arraySize);

//TODO : Déplacer l'initialisation des poids dans un autre fichier

void randomWeightInitialisation(const unsigned int weightTotalNumber, float *weight);




#endif // NETWORK_H