#ifndef LOSS_H
#define LOSS_H

struct NeuralNetwork;
struct dataset;

// moindes carrés
float loss(struct NeuralNetwork*, struct dataset*);

float lossUnique(struct NeuralNetwork*, struct dataset*, unsigned int);

#endif // LOSS_H