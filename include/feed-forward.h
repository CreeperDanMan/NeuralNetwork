#ifndef FEED_FORWARD_H
#define FEED_FORWARD_H

struct NeuralNetwork;

// Lorsque le code sera plus avancé, implémentation de fonctions d'activations multiples

void neuronActivity(struct NeuralNetwork *network, const unsigned int layerNumber, const unsigned int neuronNumber);

void feedForward(struct NeuralNetwork *network);



#endif // FEED_FORWARD_H