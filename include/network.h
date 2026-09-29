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

/**
 * @brief Fonction permettant d'initialiser le réseau par rapport à un dataset
 * 
 * @param network   Pointeur vers l'instance courrante du réseau de neurones (NeuralNetwork)
 * @param data      Pointeur vers l'instance courrante du jeu de données utilisé
 * 
 * Initialise les entrées et sorties du réseau par rapport à la taille des données en entrée et sortie du dataset.
 * 
 * appelle neuralNetworkInitialisation
 * 
 * @see neuralNetworkInitialisation()
 */
void initFromDataset(struct NeuralNetwork *network, struct dataset *data);


/**
 * @brief Fonction permettant d'initialiser le réseau
 * 
 * @param network			Pointeur vers l'instance courrante du réseau de neurones (NeuralNetwork)
 * @param inputLayerSize 	Taille du layer d'entrée
 * @param outputLayerSize	Taille du layer de sortie
 * 
 * Initialise les variables de base du réseau, appelle la fonction networkMemoryInitialisation.
 * 
 * @see networkMemoryInitialisation()
 */

void neuralNetworkInitialisation (struct NeuralNetwork *network, unsigned int inputLayerSize, unsigned int outputLayerSize);

/**
 * @brief Fonction initialisant les array et allouant la mémoire pour le réseau
 * 
 * @param network			Pointeur vers l'instance courrante du réseau de neurones (NeuralNetwork)
 * @param inputLayerSize 	Taille du layer d'entrée
 * @param outputLayerSize	Taille du layer de sortie
 * 
 * @note Il est important de free le réseau une fois que son usage est terminé
 * @see freeNetworkAllocation
 */
void networkMemoryInitialisation(struct NeuralNetwork *network, unsigned int inputLayerSize, unsigned int outputLayerSize);

/**
 * @brief Fonction libérant la mémoire utilisée par le réseau
 * 
 * @param network			Pointeur vers l'instance courrante du réseau de neurones (NeuralNetwork)
 */

void freeNetworkAllocation(struct NeuralNetwork *network);

/**
 * @brief Fonction d'initialisation de l'array d'offset du réseau
 * 
 * @param weightOffset	Pointeur vers l'array d'Offset des poids
 * @param layerOffset	Pointeur vers l'array d'Offset des layers
 * @param layerSize		Pointeur vers la taille indépendante de chaque layer
 * @param numLayers		Nombre de layers du réseau
 */

void weightOffsetInitialisation(unsigned int *weightOffset, const unsigned int *layerOffset, const unsigned int *layerSize, const unsigned int numLayers);


/**
 * @brief Fonction d'initialisation des biais
 * 
 * @param biasArray			Pointeur vers l'array de biais
 * @param arraySize			Taille de l'array de biais (nombre de neurones)
 * @param arbitraryNumber	taille des biais pour tous les neurones (0.01 par défaut)
 * 
 */
void biaisInitialisation(float *biaisArray, const unsigned int arraySize, const float arbitraryNumber);


/** @brief Fonction d'initialisation des biais de manière aléatoire
 * 
 * @param biasArray			Pointeur vers l'array de biais
 * @param arraySize			Taille de l'array de biais (nombre de neurones)
 * 
 * Cette fonction choisis des biais entre -1 et 1
 * 
 */
void randomBiaisInitialisation(float * biaisArray, const unsigned int arraySize);



//TODO : Déplacer l'initialisation des poids dans un autre fichier + Créer une initialisation gaussienne

/**
 * @brief Fonction d'initialisation des poids aléatoire
 * 
 * @param weightTotalNumber Nombre de poids dans le réseau
 * @param weight			Pointeur vers l'array de poids
 */

void randomWeightInitialisation(const unsigned int weightTotalNumber, float *weight);



#endif // NETWORK_H