#ifndef LOSS_H
#define LOSS_H

struct NeuralNetwork;
struct dataset;

/**
 * @brief Fonction de coût, calcule l'erreur quadratique moyenne sur l'ensemble du jeu de donnée
 * 
 * Effectue une passe sur le réseau pour chaque échantillon du jeu de données 
 * et accumule l'écart entre la prédiction et les données réelles.
 * 
 * @param network   Pointeur vers l'instance courrante du réseau de neurones (NeuralNetwork)
 * @param data      Pointeur vers l'instance courrante du jeu de données utilisé
 * 
 * @return La valeur de la perte (résultat de la fonction de coût). 
 * Peut être 0.0f si le dataset est vide ou si le réseau retourne des valeurs "parfaites".
 */
float loss(struct NeuralNetwork *network, struct dataset *data);


/** @brief Fonction de coût, calcule l'erreur quadratique moyenne sur un unique échantillon
 * 
 * Effectue une passe sur le réseau pour l'échantillon pointé par l'offset donné sur le jeu de données.
 * 
 * @param network   Pointeur vers l'instance courrante du réseau de neurones (NeuralNetwork)
 * @param data      Pointeur vers l'instance courrante du jeu de données utilisé
 * @param offset    Décalage vers l'échantillon comparé à une prédiction
 * 
 * @return La valeur de la perte (résultat de la fonction de coût) sur l'échantillon donné.
 * Peut être 0.0f si le dataset est vide ou si le réseau retourne une valeur "parfaite".
 */
float lossUnique(struct NeuralNetwork *network, struct dataset *data, unsigned int offset);

#endif // LOSS_H