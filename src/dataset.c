#include "dataset.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void datasetMemoryAllocation(struct dataset* networkDataset) {
    networkDataset -> inputDataset  = malloc(networkDataset->datasetSize*networkDataset->inputOffset*sizeof(float));
    networkDataset -> outputDataset = malloc(networkDataset->datasetSize*networkDataset->outputOffset*sizeof(float)); 
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
    XORDataset -> inputOffset = 2;
    XORDataset -> outputOffset = 1;
    XORDataset -> datasetSize = 4;
    datasetMemoryAllocation(XORDataset);
    memcpy(XORDataset ->    inputDataset,   (float[]){0,0, 0,1, 1,0, 1,1},4*XORDataset -> inputOffset*sizeof(float));
    memcpy(XORDataset ->    outputDataset,  (float[]){0, 1, 1, 0}, 4*XORDataset -> outputOffset*sizeof(float));
}