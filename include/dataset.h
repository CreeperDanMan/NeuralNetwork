#ifndef DATASET_H
#define DATASET_H



/**
 * @struct dataset
 * @brief Représente le jeu de données utilisé pour entrainer le MLP contenant une paire d'entrées / sorties
 * 
 * Cette structure stocke des vecteurs plats d'entrées et sorties et gère les décalages (Offset) nécessaires pour accéder à chaque échantillon
 */

struct dataset {
    float *inputDataset;
    float *outputDataset;

    unsigned int datasetSize;

    unsigned int inputOffset;
    unsigned int outputOffset;
};

void datasetMemoryAllocation(struct dataset*);

void freeDatasetMemoryAllocation(struct dataset*);

void setDatasetXOR(struct dataset*);

void loadDatasetFromFile(struct dataset*);


#endif // DATASET_H