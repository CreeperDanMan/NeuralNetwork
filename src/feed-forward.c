#include <feed-forward.h>
#include <network.h>
#include <activations.h>


// FONCTION D'INFERENCE

void neuronActivity(struct NeuralNetwork *network, const unsigned int layerNumber, const unsigned int neuronNumber) { // Lorsque le code sera plus avancé, implémentation de fonctions d'activations multiples
	if (layerNumber==0 || neuronNumber>=network -> numberOfNeurons) {
		fprintf(stderr, "ERREUR : indice de neurone invalide (%u/%u)", neuronNumber, network->numberOfNeurons);
		exit(1);
	}
	
	for (unsigned int k = 0; k<network -> layerSize[layerNumber-1]; k++) {
		network ->output[neuronNumber] += (network -> output[network -> layerOffset[layerNumber - 1]+k]) * (network -> weight[network -> weightOffset[neuronNumber]+k]); 
	}
	network -> output[neuronNumber] = sigmoid(network -> output[neuronNumber] + network->biais[neuronNumber]);

}



void feedForward(struct NeuralNetwork *network){

	// Traitement de la couche 0 (input Layers)
	for (unsigned int i = network ->layerOffset[1]; i < network -> numberOfNeurons; i++) {
	    	network -> output[i] = 0.0f;
	}


	// Envoi des données d'entrées au réseau
	for (unsigned int i = 0; i<network -> layerSize[0]; i++) {
		network -> output[i] = network -> inputVector[i];
	}

	for (unsigned int i = 1; i<network -> numLayers; i++) {
		for (unsigned int j = network -> layerOffset[i]; j<network->layerOffset[i]+network->layerSize[i]; j++) {
			neuronActivity(network, i, j);
		}
	}

	if (network->probaVectorSize>1) {
		// Envoi du résultat de la Forward Pass dans l'array de probabilités
		softmaxVector(network->output, 
			network->probaVector, 
			network -> layerOffset[network -> numLayers-1], 
			network -> layerOffset[network -> numLayers-1]+network->layerSize[network->numLayers-1], 
			network->probaVectorSize
		);
	}
	else {
		network->probaVector[0] = network->output[network->numberOfNeurons-1];
	}
}