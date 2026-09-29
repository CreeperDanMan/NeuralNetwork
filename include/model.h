#ifndef MODEL_H
#define MODEL_H


struct NeuralNetwork;

/**
 * @todo Implémenter cette fonction
 * @brief Fonction de chargement d'un réseau depuis un fichier
 * 
 * @param network   Pointeur vers l'instance courrante du réseau de neurones (NeuralNetwork)
 * 
 */
void loadNetwork(struct NeuralNetwork *network);


/**
 * @todo Implémenter cette fonction
 * @brief Fonction de sauvegarde d'un réseau dans un fichier
 * 
 * @param network   Pointeur vers l'instance courrante du réseau de neurones (NeuralNetwork)
 * 
 */
void saveNetwork(struct NeuralNetwork *network);


#endif //MODEL_H