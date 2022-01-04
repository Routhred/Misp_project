# Misp_project
Projet 3A CS351 Esisar  

Simulateur d'un processeur misp en c

Description des modules:
  module de gestion mémoire:
    - fonctions pour ecrire dans la mémoire
    - fonction pour lire dans la mémoire
   module de gestion des registres:
    - fonction pour modifier les registres
    - faire des opération sur les registres
   module pour appliquer les operations, appeler les fonctions des autres modules en fonction des instructions d'entrées en         binaire
___________________________________________________________________________________________________________________________________________________________________________________
Utilisateur:


3 modes d'utilisation:
 - Mode console: 
    lancer le programme emul-mips sans arguments => entrer les commandes de maniere séquentielles dans la console
    Entrer la commande "exit" pour quitter la console.
    
    Les registres s'afficheront après chaque commande
    Entrer la commande Memoire pour afficher la mémoire (commande pas encore implémentée)
 - Mode fichier:
    Lancer le programme emul-mips avec comme argument:
        - le fichier source du programme ecrit en assembleur
        - le fichier de destination de la traduction en hexadecimal du programme
              le fichier source devra se trouver dans le dossier test
              le fichier dest sera envoyé dans le dossier hexified, si il en existe deja un il sera écrasé
- Mode pas a pas:
    Lancer le programme emul-mips avec comme argument:
        - le fichier source du programme ecrit en assembleur
        - le fichier de destination de la traduction en hexadecimal du programme
              le fichier source devra se trouver dans le dossier test
              le fichier dest sera envoyé dans le dossier hexified, si il en existe deja un il sera écrasé
        - "-pas"


En premier vous aurez le nom du mode qui s'affiche, puis la traduction des instructions.
Ensuite vous aurez les instructions qui s'executerons dans l'ordre, et si vous êtes en mode pas a pas, il faudra appuyer sur la touche <return> entre chaque execution.
A la fin de l'execution, vous aurez la liste des registres avec les valeurs qu'ils auront.