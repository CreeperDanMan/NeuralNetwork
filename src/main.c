#include "network.h"
#include "forward-pass.h"
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
	
	printf("Le réseau utilisera le dataset XOR intégré\n");
	setDatasetXOR(&data);

	initFromDataset(&network, &data);
	printf("Nombre de paramètres du réseau : %u\n",getParameterNumber(&network));
	printf("Nombre de neurones : %u\n", network.numberOfNeurons);
	printf("Nombre de poids : %u\n", network.numberOfWeight);

	printf("Loss : %f\n",loss(&network, &data));

	// == Libération de la mémoire ==
	freeNetworkAllocation(&network);
	freeDatasetMemoryAllocation(&data);

	return 0;
}

