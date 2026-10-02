#include "loss.h"
#include "network.h"
#include "dataset.h"
#include "forward-pass.h"
#include <math.h>

float loss(struct NeuralNetwork* network, struct dataset* data) {
    
    float lossResult = 0.0f;
    
    for (unsigned int i = 0; i<data ->datasetSize; i++) {

        copyDatasetInput(network, data, i);
        forwardPass(network);

        for (unsigned int j = 0; j<data->outputOffset;j++) {
            lossResult += pow((data->outputDataset[data->outputOffset*i+j]-network->probaVector[j]),2);
        }

    }
    return lossResult/(float)data->datasetSize;
}

float lossUnique(struct NeuralNetwork* network, struct dataset* data, unsigned int offset) {
    if (offset>=data->datasetSize) {
        fprintf(stderr, "ERREUR : offset supérieur à la taille du dataset\n");
        exit(1);
    }
    float lossResult = 0.0f;
    unsigned int sampleOffset = offset * data->outputOffset;
    copyDatasetInput(network, data, offset);
    forwardPass(network);
    
    for (unsigned int i = 0; i<data->outputOffset; i++) {
        lossResult = pow((data->outputDataset[sampleOffset+i]-network->probaVector[i]),2);
    }
    
    return lossResult;
}