#include "network.h"
#include "feed-forward.h"
#include "dataset.h"
#include "loss.h"

/* TODO : 
 * - Créer des tests unitaires pour tester individuellement les fonctions et leurs foncitonnement correct
 * - Implémenter de la gestion d'exception
*/


int main() { //int argc, char* argv[]

	// INITIALISATION DES VARIABLES

	struct dataset data;
	struct NeuralNetwork network;

	srand(time(NULL));
	
	setDatasetXOR(&data);

	initFromDataset(&network, &data);
	printf("Nombre de paramètres du réseau : %u\n",getParameterNumber(&network));
	printf("neurons = %u\n", network.numberOfNeurons);
	printf("weights = %u\n", network.numberOfWeight);

	printf("La loss est de : %f\n",loss(&network, &data));

	// == Libération de la mémoire ==
	freeNetworkAllocation(&network);
	freeDatasetMemoryAllocation(&data);

	return 0;
}

