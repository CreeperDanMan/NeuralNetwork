#ifndef DATASET_H
#define DATASET_H



/*
 * Dataset :
 * Donne i valeurs en entrée et attends j valeurs en sortie.
 * structure utilisée pour la fonction de coût.  
 * inputOffset donne la taille POUR CHAQUE ENTREE (utilisé pour calculer l'offset d'input)
 * outputOffset donne la taille POUR CHAQUE SORTIE (utilisé pour calculer l'offset de sortie)
 * Le réseau a des entrées et sorties fixes, pas besoin d'un tableau.
 * Usage d'un type générique pour l'input et l'output (permission d'utiliser des float, doubles, int, long int) même si le tout sera casté en float
*/

// Pointeurs FLOAT (usage de casting puisque le MLP utilise des floats pour l'inférence)
// TODO : Adapter couches d'entrées et de sorties à la taille des entrées et sorties
struct dataset {
    float *inputDataset;
    float *outputDataset;

    unsigned int datasetSize;

    unsigned int inputOffset;
    unsigned int outputOffset;
};

void datasetMemoryAllocation(struct dataset*);

void freeDatasetMemoryAllocation(struct dataset*);

/*
 * dataset d'entrainement pour XOR par défaut
*/
void setDatasetXOR(struct dataset*);

void loadDatasetFromFile(struct dataset*);


#endif // DATASET_H