#ifndef UTILS_H
#define UTILS_H

#include "utils.h"
#include <stdio.h>
#include <math.h>

struct NeuralNetwork;
struct dataset;

/**
 * @brief Fonction pour récupérer l'array de probabilité
 * 
 * @param network		Pointeur vers l'instance courrante du réseau de neurones (NeuralNetwork)
 * 
 * @return Un pointeur vers le tableau de float récupéré
 */
float* getProbaVector(struct NeuralNetwork *network);


/**
 * @brief Fonction pour copier les valeurs d'un array donné au vecteur d'entrée du réseau
 * 
 * @param network	Pointeur vers l'instance courrante du réseau de neurones (NeuralNetwork)
 * @param vector    Pointeur vers un array de float de taille identique au vecteur d'entrée du réseaus
 * 
 * @return Un pointeur vers le tableau de float récupéré
 */
void setInputVector(struct NeuralNetwork *network, const float *vector);


/**
 * @brief Fonction pour le nombre de paramètres du réseaux (le nombre de poids + le nombre de biais)
 * 
 * @param network	Pointeur vers l'instance courrante du réseau de neurones (NeuralNetwork)
 * 
 * @return Un entier non signé contenant le nombre de paramètre du réseau
 */
unsigned int getParameterNumber(struct NeuralNetwork *network);


/**
 * @brief Fonction pour récupérer le maximum d'un array entre un index donné et la fin de l'array
 * 
 * @param vector            Pointeur vers un array donné
 * @param vSize             Taille de l'array donné
 * @param vectorFirstIndex  Premier index du calcul du maximum
 * 
 * @return le maximum de l'array donné
 * @warning Si vSize ne correspond pas à la taille du tableau, il existe un risque de lecture hors mémoire
 */
float maximum(const float *vector, const unsigned int vSize, const unsigned int vectorFirstIndex);


/**
 * @brief applique Softmax sur un array et le sauvegarde dans un autre array
 * 
 * @param v                 Pointeur vers l'array contenant les valeurs à transformer
 * @param p                 Pointeur vers l'array de sortie qui contiendra des probabilités
 * @param firstIndex        Premier index de la normalisation sur le vecteur d'entrée
 * @param lastIndex         Dernier index de la normalisation sur le vecteur d'entrée
 * @param probaVectorSize   Taille de l'array de sortie
 * 
 * @warning La différence entre lastIndex et FirstIndex doit être égale à la taille de l'array de sortie
 */
void softmaxVector(const float *v, float *p, const unsigned int firstIndex, const unsigned int lastIndex, const unsigned int probaVectorSize);



void displayProbaVector(struct NeuralNetwork *network);

void displayInputVector(struct NeuralNetwork *network);

void copyDatasetInput(struct NeuralNetwork *network, struct dataset *data, unsigned int offset);

void zeroInitialisation(float *array, unsigned int arraySize);


#endif // UTILS_H