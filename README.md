# Réseau de neurones from Scratch en C

Une implémentation *from scratch* d'un réseau de neurones (ici un Perceptron MultiLayer) en C.

## Présentation du projet

Ce projet vise à explorer les mécanismes fondamentaux du deep learning (la fonction de coût, les fonctions d'activation, la descente de gradient, la backpropagation), ainsi que le langage C via gestion de la mémoire explicite (malloc/free).

## Fonctionnalités du projet
- **Architecture utilisée :** Perceptron MultiLayer (*MLP*) avec gestion indépendante de la taille et du nombre de couche.
- **Activation :** Implémentation de plusieurs fonctions d'activations (Sigmoid, ReLU, leakyReLU, SoftPLUS, ELu, SiLU) et possibilité de choisir la fonction d'activation pour chaque couche.
- **Fonction de coût :** Usage de l'erreur moyenne quadratique (MSE).


## Commandes make disponibles

```shell
# Compilation du projet avec optimisations du compilateur
make
make all

# Compilation du projet avec options de débogage
make debug

# Exécution du projet
make run

# Suppression du binaire compilé et du dossier de compilation
make clean

# Recompiler le projet
make rebuild

```

## État du projet — en cours

**Fonctionnel :** forward pass, dataset XOR, fonction de coût MSE, 6 activations.  
**En cours :** pré-activations et dispatch par couche.  
**Prévu :** backpropagation (validation par gradient check), entraînement full-batch,
initialisation gaussienne Xavier/He, chargement de dataset, sauvegarde du réseau.  

## Licence

Ce projet est sous licence [MIT](LICENSE).
