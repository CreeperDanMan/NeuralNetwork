#ifndef ACTIVATIONS_H
#define ACTIVATIONS_H


#include <math.h>

// TODO : enum pour choisir la fonction d'activation

// Sigmoide
float sigmoid(const float x);

// Fonction de dérivation de la sigmoide
// f'(x) = f(x)(1-f(x))
float sigmoidDerivative(const float x);

// Unité de rectification linéaire
float ReLU(const float x);

float ReLUDerivative(const float x);

// SoftPLUS (RELU continue) / LA DERIVEE DE SOFTPLUS EST LA SIGMOIDE
float SoftPlus(const float x);

// Leaky RELU -> ReLU avec un facteur A pour les valeurs sous x (évite les dead neurons) -- mettre a dans une constante
float leakyReLU(const float a, const float x);

// Exponential Linear Unit (jsp)

float eLU(const float a, const float x);

float eLUDerivative(const float a, const float x);

// Sigmoid Linear Unit (SiLU)

float SiLU(const float x);

float SiLUDerivative(const float x);







# endif // ACTIVATIONS_H