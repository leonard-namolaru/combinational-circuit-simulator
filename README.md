                     Guide d'utilisation du projet :

## Installation

Pour installer l'application , rendez-vous sur le lien  ci-dessous pour récupérer le projet .
Une fois , on a recupéré le depot git , on se déplace dans le dossier projet-cpp puis dans src et on exécute les commandes "make all"   et  "make test"  comme suit : 

$ git clone https://gaufre.informatique.univ-paris-diderot.fr/aitbenal/projet-cpp.git 
$ cd projet-cpp/src
$ make all 
$ make test 

Les deux dernières commandes permettent de compiler le projet et de l'exécuter.

Une fois le projet exécuté , un menu sera affiché.

************************************ Pour afficher le circuit tapez 1 : ************************************************************

Remarque : -------------------------------------------------------------------------------------------------------------------------

Si vous tapez 1 directement après la première exécution du programme , cela affichera le cicruit correspondant au code existant dans le main.ccp . Ce code correspond à un circuit codé en dur servant juste d'affichage standard à l'utilisateur au démarage de l'application. l'utilisateur pourra voir les fonctionnaltés du programme sans taper de circuit au préalable.

------------------------------------------------------------------------------------------------------------------------------------


-************************** Pour démarer la simulation en mode pas à pas , tapez 2 ************************************************

Cela affichera l'evolution de l'information au fur et à mesur de son passage par des portes logiques.
En tapant 2 directement après l'éxécution du programme , ça lance la simulation du circuit standard déja existant. 


-************************** Pour changer les valeurs des portes d'entrée tapez 3  ************************************************

Pour chaque entrée , le programme affiche l'ancienne valeur , sous forme :
Nom de l'entrée : " NOM D'ENTRÉE"  ; Valeur : "VALEUR DE L'ENTRÉE" 
Le programme demande à l'utilisateur de rentrer la nouvelle valeur ( soit 0 , soit 1 )


-************************** Pour Afficher le circruit sous forme textuelle tapez 4  ************************************************

Pour voir la forme textuelle du circuit tapez 4
La première exécution renvoie  A=AND(OR_(XOR(OR_(a,b),AND(a,b)),AND(OR_(c,d),AND(c,d))),XOR(OR_(AND(e,f),AND(a,b)),XOR(OR_(a,f),OR_(d,f)))) , qui correspond au circuit standard existant 


************** Synthétiser un circuit à partir d'une expression textuelle  tapez 5 *********************************

En tapant 5 , on aura à donner l'expression textuelle du circuit qu'on voudrait créer


************** Sauvegarder un circuit dans un fichier tapez 6 ********************************


************** Relire un circuit qui est dans un fichier tapez 7 *********************************



