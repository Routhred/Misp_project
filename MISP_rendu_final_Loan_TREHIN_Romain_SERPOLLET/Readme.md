utilisateur:

## Les modes de fonctionnement :

- Mode fichier:

	Utiliser ce mode pour traduire et executer un fichier complet. On utilise cette commande:

		./emul-mips arg1 arg2 arg3 -[option]
	
	- arg1 : fichier source contenant le programme a traduire, il doit se trouver dans un dossier 
			tests/
	- arg2 : nom du fichier de destination contenant la traduction en hexa du programme, il sera envoye dans un 
			dossier hexified/
	- arg3 : nom du fichier de destination contenant l'etat des registres a la fin de l'execution du programme, 
			il sera envoye dans le dossier registres/

	- option : on peut ajouter l'option : -pas

	Cette option permet d'executer le programme en mode pas a pas, c'est a dire, l'utilisateur doit appuyer sur 
	la touche <entree> entre chaque instruction.

- Mode interaction:

	./emul-mips

	Ce mode permet d'avoir acces a une console, on ne peut entrer que des instructions de maniere sequentielle. 
	On ne peut pas faire de fonctions jump ou gec par exemple.
	L'etat des registres sera affiche entre chaque instruction pour faciliter la programmation.

## L'affichage : 

Lors de l'execution de notre programme il va y avoir 3 phases
- Affichage de la traduction:
Lors de la phase de traduction, on aura un tableau de 3 colonnes pour chaque instruction traduite:
___________________________________________________________________ 
| numero de la ligne | traduction en hexa | instruction en lettre |
|--------------------|--------------------|-----------------------|
|____________________|____________________|_______________________|
- Affichage de l'execution:
Lors de la phase de traduction, on aura un tableau de 6 colonnes pour chaque instruction executee:
_________________________________________________________________________________________________________________________________________________
|		PC			 | N° registre modifie| Valeur registre modifie |adresse memoire modifiee | valeur memoire modifiee | instruction			|
|--------------------|--------------------|-------------------------|-------------------------|-------------------------|-----------------------|
|   Valeur en hexa   | X si rien          | X si rien               | X si rien               | X si rien               |                       |
|____________________|____________________|_________________________|_________________________|_________________________|_______________________|


Lors de cette phase, si les registres sont proteges en ecriture, comme le registre 0, une erreur s'affichera mais le programme continuera son execution de maniere normale.
- Fin de l'execution:
	A la fin de l'execution, on affiche les registres sous leur forme chiffree et sous leur forme mnemonique suivie 
	de la valeur qu'ils auront a la fin du programme.
	Il y aura aussi toutes les adresses memoire utilisees ainsi que leur valeur.


/!\ L'instruction syscall n'est pas implementee /!\
/!\ Pour la compilation il est necessaire d'utiliser le parametre de gcc -lm pour include la librairie math.h/!\

## Repartition des taches:
_____________________________________________________________________________________________________________________
|																				|	Loan TREHIN  | Romain SERPOLLET	|
|-------------------------------------------------------------------------------|----------------|------------------|																		
|Mise en place de la structure des instructions									|		V		 |		  V		    |		
|Creation des tables de correspondances											|		V		 |		  X		    |
|Gestion des registres mnemoniques												|		V		 |		  X		    |
|Decoupage des lignes de code													|       X		 |        V         |
|Traduction des lignes decoupees												|       X		 |        V         |
|Creation des fonctions utilitaires												|		V		 |		  V		    |
|Creation et gestion de la memoire 												|		V		 |		  V		    |
|Creation et gestion des registres												|		V		 |		  V		    |
|Gestion des modes de fonctionnement du programme (mode fichier/mode console)	|		X		 |		  V		    |
|Gestion du deroulement de l'execution et du pc									|		X		 |		  V		    |
|Gestion de l'appel des instructions											|		V		 |		  X		    |
|Gestion de l'execution des instructions										|		X		 |		  V	        |
|_______________________________________________________________________________|________________|__________________|

Lien vers le github : https://github.com/Routhred/Misp_project.git 