Contenu du dossier
------------------
* Un dossier "code-source" contenant le code source utilisé pour créer le jeu.
* Un dossier "jeu compilé" contenant le jeu compilé et prêt à être utilisé (attention 64bits uniquement)
* Un dossier "videos du jeu" contenant 2 vidéos, la première montrant le jeu complet (durée 2 mn) et la seconde, une partie en jeu

Description de SkyCraft
-----------------------
Dans le jeu SkyCraft, vous incarnez Mario. Vous devez amasser des pièces tout en atteignant le château en un temps record afin 
d'obtenir le meilleur score. Pour savoir comment 
manipuler le personnage, un menu "settings" est à votre disposition.<br /> 
En jeu, vous devez éviter ou franchir les obstacles, ceux-ci peuvent être fixes (blocs, tuyaux) mais ils 
peuvent aussi être mobiles (missiles : Banzai Bill). Pour les missiles présents sur votre parcours, 
leur couleur indique leur vitesse, les noirs sont plus lents que les rouges. Alors attention à les éviter pour ne pas mourir. 
En effet, si vous touchez un Banzai Bill ou que vous tombez dans un trou, c'est perdu ! <br />
Si vous réussissez à éviter les pièges et à atteindre le château, vous serez invité à rentrer votre nom et votre score sera sauvegardé !
Vous pourrez le retrouver dans la section "Leaderboard" indiquant le classement des scores effectués.

Comment lancer le jeu
---------------------
Deux choix s'offrent à vous :
* Vous utilisez la version compilée possédant un exécutable. Elle se trouve dans le dossier "jeu compilé" 
et le nom de l'exécutable est "SkyCraft.exe".<br />
* Vous ouvrez le projet dans Qt Creator et sélectionnez "Open", naviguez dans le dossier "code-source" fourni et cherchez "secondProject.pro". 
Une fois ouvert, vous pouvez compiler le projet et modifier le code source si vous le désirez.


Améliorations
-------------
Ce projet a été réalisé dans l'environnement de développement Qt Creator (en Qt/C++). Pour créer le projet, nous avions des consignes 
à respecter. Chacun avait ensuite la possibilité d'aller au-delà de la version de base en concevant un jeu offrant plus d'options.

<h4>Les ajouts suivants ont été réalisés :</h4>
* Ajout de tuyaux (obstacles)
* Ajout de pièces (améliorant le score du joueur)
* Ajout d'ennemis mobiles (missiles : Banzai Bill)
* Ajout de graphismes type Mario
* Ajout de sons et de bruitages
* Création d'un score à partir du temps et des pièces récoltées pendant la course
* Création d'un menu (Play/Leaderboard/Settings/Credits/Exit)
* Création d'un tableau ordonné par ordre décroissant des scores (possibilité de le réinitialiser)
* Sauvegarde des scores dans un fichier texte afin qu'ils ne soient pas perdus à la fermeture de l'application

Contributions
--------------
Comme toutes les personnes ayant donné leur avis et contribué à la réalisation de ce projet, votre avis m'intéresse.<br /> 
Toutes propositions d'amélioration sont les bienvenues.<br /> 
Pour me contacter : Mail : hugo.bourreau@isen-ouest.yncrea.fr | Discord : SkY_iMlTo#1784

Licence
-------
Le code du projet est Open source, vous pouvez donc le modifier comme vous le souhaitez et le repartager librement.
