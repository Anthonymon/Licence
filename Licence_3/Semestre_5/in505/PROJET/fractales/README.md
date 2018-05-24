CAUMES Clément DOUDOUH Yassin
Langages Avancés IN505 

# Remise du projet 

1. Pour obtenir le listing commenté du programme, il suffit de taper la commande suivante : 

```
 $ make listing
```

2. Pour lire le compte rendu du projet, il faut taper la commande suivante :

```
 $ make rapport
```

# Mécanisme d'installation et de manipulation de l'application

1. Pour vous assurez la compilation de l'application la première fois, il faut taper la commande suivante : 

```
 $ make first
```

2. Les commandes Makefile expliquées sont les suivantes : 

```
 $ make compil 
 $ make run
 $ make all
 $ make clean 
 $ make install 
```

   La première commande permet uniquement de compiler l'application : un exécutable fractale sera généré. 
   La deuxième permet d'exécuter le projet. 
   La troisième permet de compiler et d'exécuter successivement l'application. 
   La quatrième commande permet de supprimer tous les fichiers liés à la compilation 
   La dernière est utile uniquement à chaque changement de machine virtuelle. 


# Mode d'emploi 

1. Choisir la fractale en cliquant sur le bouton Valider de l'onglet correspondant. 
   Pour la fractale Julia et Fatou, le choix du nombre complexe associé est nécessaire. 
   
2. La manipulation de la fractale peut se faire de plusieurs manières : 

- la modification de la partie réelle et de la partie imaginaire du complexe représentant la fractale (pour le cas de Julia et Fatou). 

- le changement de la valeur de zMax. 

- l'enregistrement vectoriel avec Cairo en utilisant le bouton Enregistrer. 

- le bouton Quitter permet de fermer l'application.

- le déplacement sur l'image avec les boutons Z/Q/S/D. 

- le changement de couleur de la fractale en appuyant successivement sur le bouton C 

- le zoom et le dezoom avec O et P

- le changement de la granularité de l'image de la fractale avec L et M 
   
