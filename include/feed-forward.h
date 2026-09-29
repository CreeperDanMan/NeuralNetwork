#ifndef FEED_FORWARD_H
#define FEED_FORWARD_H

struct NeuralNetwork;


/**
 * @brief fonction calculant l'output pour un neurone donné
 * 
 * @param network       Pointeur vers l'instance courrante du réseau de neurones (NeuralNetwork)
 * @param layerNumber   Numéro du layer du neurone prédit
 * @param neuronNumber  Index du neurone dans l'array output
 * 
 * @warning ne pas tenter d'exécuter cette fonction sur un neurone du layer d'entrée ou sur un index hors array
 */

void neuronActivity(struct NeuralNetwork *network, const unsigned int layerNumber, const unsigned int neuronNumber);


/**
 * @brief Fonction de la passe en avant (feedForward)
 * 
 * @param network   Pointeur vers l'instance courrante du réseau de neurones (NeuralNetwork)
 * 
 * Efface les états précédents du réseau (remise à zero du tableau d'output),
 * Envoie les données de l'array d'entrée à l'offset 0 de l'array output,
 * Exécute la passe en avant sur chaque layer en appelant la fonction neuronActivity,
 * Et enfin normalise la sortie en probabilités avec softmax.
 * Si la taille de sortie du réseau est de 1, la sortie n'est pas normalisée.
 * 
 * @see neuronActivity
 * 
 */
void feedForward(struct NeuralNetwork *network);



#endif // FEED_FORWARD_H