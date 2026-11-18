#include "dataset.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void datasetMemoryAllocation(struct dataset* networkDataset) {
    networkDataset -> inputDataset  = malloc(networkDataset->datasetSize*networkDataset->inputStride*sizeof(float));
    networkDataset -> outputDataset = malloc(networkDataset->datasetSize*networkDataset->outputStride*sizeof(float)); 
    if (networkDataset -> inputDataset == NULL || networkDataset -> outputDataset == NULL) {
        fprintf(stderr, "ERREUR D'ALLOCATION, POINTEUR NULL RETOURNE");
        exit(1);
    }
}

void freeDatasetMemoryAllocation(struct dataset* networkDataset) {
    free(networkDataset -> inputDataset);
    free(networkDataset -> outputDataset);
}


void setDatasetXOR(struct dataset* XORDataset) {
    XORDataset -> inputStride = 2;
    XORDataset -> outputStride = 1;
    XORDataset -> datasetSize = 4;
    datasetMemoryAllocation(XORDataset);
    memcpy(XORDataset ->    inputDataset,   (float[]){0,0, 0,1, 1,0, 1,1},XORDataset -> inputStride*XORDataset->datasetSize*sizeof(float));
    memcpy(XORDataset ->    outputDataset,  (float[]){0, 1, 1, 0}, XORDataset -> outputStride*XORDataset->datasetSize*sizeof(float));
}