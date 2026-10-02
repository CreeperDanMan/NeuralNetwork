# Réseau de neurones from Scratch en C

Une implémentation *from scratch* d'un réseau de neurones (ici un Perceptron MultiLayer) en C.

## Présentation du projet

Ce projet vise à explorer les mécanismes fondamentaux du deep learning (la fonction de coût, les fonctions d'activation, la descente de gradient, la backpropagation), ainsi que le langage C via gestion de la mémoire explicite (malloc/free).

## Fonctionnalités du projet
- **Architecture utilisée :** Perceptron MultiLayer (*MLP*) avec gestion indépendante de la taille et du nombre de couche.
- **Apprentissage :** Propagation en avant (**Forward Pass**) et Propagation en arrière (**Backpropagation**).
- **Activation :** Implémentation de plusieurs fonctions d'activations (Sigmoid, ReLU, leakyReLU, SoftPLUS, ELu, SiLU) et possibilité de choisir la fonction d'activation pour chaque couche.
- **Fonction de coût :** Usage de l'erreur moyenne quadratique (MSE).
- **Gestion mémoire :** Usage d'allocation dynamiques et libération de la mémoire allouée (garentie sans fuite mémoire par Valgrind).


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


## Avancement actuel du projet

- [x] Implémentation de la structure du réseau de Neurones
- [x] Implémentation d'une initialisation aléatoire des poids dans [-0.1,0.1]
- [x] Implémentation de la Forward Pass
- [x] Implémentation du dataset par defaut XOR
- [x] Ajout de la fonction de coût et de son calcul par rapport au dataset
- [ ] Implémentation d'une taille et d'un nombre variable de couches cachées
- [ ] Implémentation d'une initialisation gausienne des poids
- [ ] Implémentation de la Backpropagation
- [ ] Possibilité de charger un dataset depuis un fichier
- [ ] Possibilité de charger ou sauvegarder un réseau


## Licence

Ce projet est sous licence [MIT](LICENSE).