#ifndef ACTIVATIONS_H
#define ACTIVATIONS_H


/**
 * @enum activationFonction
 * @brief indique le choix de la fonction d'activation
 */
enum activationFonction {
    SIGMOID,
    RELU,
    LEAKYRELU,
    SOFTPLUS,
    ELU,
    SILU
};

// Sigmoide
/**
 * @brief Fonction d'activation sigmoid 
 * 
 * @param x Valeur de sortie du neurone
 * 
 * @return La valeur de sigmoid appliquée à la valeur d'entrée
 * 
 * Formule : f(x) = 1/(1+e^{-x})
 */
float sigmoid(const float x);


/**
 * @brief Dérivé de la sigmoid
 * 
 * @param x Valeur de sortie du neurone
 * 
 * @return La valeur de la dérivée de sigmoid
 * 
 * Formule : f'(x) = f(x)(1-f(x))
 */
float sigmoidDerivative(const float x);


/**
 * @brief Fonction d'activation ReLU / Unité de Rectification Linéaire / Rectified Linear Unit
 * 
 * @param x Valeur de sortie du neurone
 * 
 * @return La valeur de ReLU
 * 
 * Formule : max(0,x)
 */
float ReLU(const float x);


/**
 * @brief Dérivée de ReLU
 * 
 * @param x Valeur de sortie du neurone
 * 
 * @return La valeur de la dérivée de ReLU
 * 
 * Formule : x>=0 : 1 sinon 0
 */
float ReLUDerivative(const float x);


/**
 * @brief Fonction d'activation SoftPlus
 * 
 * @param x Valeur de sortie du neurone
 * 
 * @return La valeur de SoftPlus
 * 
 * @note La dérivée de SoftPlus est la Sigmoid
 * 
 * Formule : log(1+e^{x})
 */
float SoftPlus(const float x);


// Leaky RELU -> ReLU avec un facteur A pour les valeurs sous x (évite les dead neurons) -- mettre a dans une constante
/**
 * @brief Fonction d'activation leakyRelu, basée sur ReLU
 * 
 * @param a Valeur de la pente négative
 * @param x Valeur de sortie du neurone
 * 
 * @return La valeur de leakyRelu
 * 
 * @note Le fonctionnement est similaire à ReLU, de même pour sa dérivée
 * 
 * Formule max(a*x, x), où a est un nombre inférieur à 1 (ex : 0.05 ou 0.01)
 */
float leakyReLU(const float a, const float x);

/**
 * @brief Dérivée de LeakyReLU
 * 
 * @param a Valeur de la pente négative
 * @param x Valeur de sortie du neurone
 * 
 * @return La dérivée de leakyReLU
 * 
 * Formule : x>=0 : 1 sinon a 
 */
float leakyReLUDerivative(const float a, const float x);


/**
 * @brief Fonction d'activation exponential Linear Unit
 * 
 * @param a Valeur de la pente négative
 * @param x Valeur de sortie du neurone
 * 
 * @return La valeur de ELu
 * 
 * Formule : x>=0.0f ? x sinon a*(e^{x}-1)
 */

float ELu(const float a, const float x);


/**
 * @brief Dérivée de ELu
 * 
 * @param a Valeur de la pente négative
 * @param x Valeur de sortie du neurone
 * 
 * @return La dérivée de ELu
 * 
 * Formule : x>=0.0f ? 1 : a*expf(x)
 */
float ELuDerivative(const float a, const float x);


/**
 * @brief Fonction d'activation Sigmoid Linear Unit (SiLU)
 * 
 * @param x Valeur de sortie du neurone
 * 
 * @return La valeur de SiLU
 * 
 * Formule : x*(1/(1+e^{-x}))
 */

float SiLU(const float x);


/**
 * @brief Dérivée de SiLU
 * 
 * @param x Valeur de sortie du neurone
 * 
 * @return La dérivée de SiLU
 * 
 * Formule : x*SiLU(x)+sigmoid(x)
 */

float SiLUDerivative(const float x);


# endif // ACTIVATIONS_H