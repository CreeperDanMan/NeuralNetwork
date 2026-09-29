#ifndef DATASET_H
#define DATASET_H



/**
 * @struct dataset
 * @brief Représente le jeu de données utilisé pour entrainer le MLP contenant une paire d'entrées / sorties
 * 
 * Cette structure stocke des vecteurs plats d'entrées et sorties et gère les décalages (Offset) nécessaires pour accéder à chaque échantillon.
 * Les entrées et sorties du réseau seront adaptés automatiquement à la taille du dataset utilisé.
 */

struct dataset {
    float *inputDataset; /**< Array à une dimension contenant les entrées du dataset */
    float *outputDataset; /**< Array à une dimension contenant les sorties du dataset */

    unsigned int datasetSize; /**< Variable contenant la taille du dataset */

    unsigned int inputOffset; /**< Variable contenant l'offset des entrées du dataset (taille des entrées) */
    unsigned int outputOffset; /**< Variable contenant l'offset des sorties du dataset (taille des sorties) */
};

/**
 * @brief Fonction d'allocation de la mémoire pour le dataset
 * 
 * @param networkDataset    Pointeur vers le dataset utilisé
 */
void datasetMemoryAllocation(struct dataset *networkDataset);

/**
 * @brief Fonction de libération de la mémoire allouée pour le dataset
 * 
 * @param networkDataset    Pointeur vers le dataset utilisé
 */
void freeDatasetMemoryAllocation(struct dataset*);

/**
 * @todo Implémenter cette fonction
 * @brief Fonction chargeant un dataset depuis un fichier
 * 
 * @param networkDataset    Pointeur vers le dataset utilisé
 * 
 */
void loadDatasetFromFile(struct dataset*);

/**
 * @brief Dataset XOR, implémenté par défaut
 * 
 * @param networkDataset    Pointeur vers le dataset utilisé
 * 
 * Ce dataset permet d'apprendre le très connu problème du XOR au réseau
 * 
 * Formule du XOR :
 * 0 + 0 = 0
 * 0 + 1 = 1
 * 1 + 0 = 1
 * 1 + 1 = 0
 */

void setDatasetXOR(struct dataset*);

#endif // DATASET_H