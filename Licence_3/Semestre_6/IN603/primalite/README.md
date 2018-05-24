# Test de primalité de Solovay-Strassen

Ce programme permet de tester si un nombre en problablement premier 
ou non selon le test probabiliste Solovay-Strassen.
Il a été réalisé par CAUMES Clément et DOUDOUH Yassin dans le cadre 
d'un projet proposé par Christina BOURA. 

## Installation

* GMP : il faut préalablement télécharger le dossier compressé 
  gmp-6.1.2.tar.xz pour assurer le succès de l'installation suivante. 
```
 $ make install_gmp
 $ cd gmp-6.1.2
 $ make
 $ make check
 $ make install
 $ make check
```

* CUNIT : 
```
 $ make install_cunit
```

* Documentation :
```
 $ make doxygen
```

## Compilation du projet :

```
 $ make compil
```

## Exécution du projet :

Un fichier TESTME.txt a été fourni pour réaliser des tests sur des 
nombres premiers : il est possible de copier-coller les nombres à tester 
en ligne de commande. 
[n] correspond au nombre à tester et [k] correspond au nombre d'itérations 
pour le test de Solovay-Strassen. 

* Présentation du projet :
```
 $ make run
```
OU
```
 $ ./primalite
```

* Exécution d'un test sur un nombre premier : 
```
 $ ./primalite [n] [k]
```

* Compilation et Exécution de tests unitaires : 
Des tests unitaires ont été réalisés notamment avec les 10 nombres 
premiers proposés dans le fichier "Big Prime Numbers" sur e-campus. 
```
 $ make test
```

## Explications des algorithmes :

* Exponentiation modulaire (exponent.c/.h) :
```
void square_and_multiply(mpz_t r,mpz_t a, mpz_t h, mpz_t n); 
```
Cet algorithme va calculer l'exponentiation modulaire en utilisant 
la décomposition binaire de l'exposant. Il a une boucle de t-1 à 0 avec 
t le nombre de d'éléments dans la décomposition binaire de l'exposant. 
La complexité de cet algorithme est donc O(log_2(e)) avec e l'exposant 
en base de 10 puisque cela correspond au nombre d'éléments dans sa 
représentation binaire. 

* Solovay-Strassen (strassen.c/.h) : 
```
int teste_primalite_strassen(mpz_t n,mpz_t k);
```
Le test de Solovay-Strassen est un test probabiliste de nombres premiers. 
Il utilise le calcul du symbole de Jacobi avec un nombre aléatoire a et 
le nombre à tester n pour déterminer si n est probablement premier. 
k représente le nombre de répétitions dans le test et plus k est grand, 
moins on a de chances que le test fasse une erreur (1/2^k). 

* Jacobi (jacobi.c/.h) : 
```
int jacobi(mpz_t num,mpz_t denum);
```
Le symbole de Jacobi ne peut prendre que 3 valeurs (0, 1 ou -1). C'est pour 
cela que nous retournons un entier. 
Si n est premier alors le symbole de Jacobi et le symbole de Legendre sont 
égaux. 

* Déterminisation de la primalité entre deux nombres (jacobi.c/.h)
```
int premier_entre_eux_iteratif(mpz_t a,mpz_t b);
int premier_entre_eux_recursif(mpz_t a,mpz_t b);
int premier_entre_eux_binaire(mpz_t a,mpz_t b);
```
Pour le calcul du symbole de Jacobi, il est nécessaire de savoir si deux 
nombres sont premiers entre eux. Pour cela, il a fallu l'implémenter. 
Nous avons essayé d'améliorer le plus possible la complexité car nous nous 
sommes rendus compte que c'était l'opération la plus longue. 
Les complexités du calcul du PGCD en itératif et en récursif ont la 
même complexité de O(log(a)) avec a>b. Mais, la récursive est légèrement 
plus longue à cause de ses nombreux appels récursifs. 
Une troisième solution consistait à calculer le pgcd en utilisant la 
décomposition binaire et à utiliser les shifts (équivalents aux x2 et /2) 
en base de 10. Le problème de cette solution pour ce projet est le fait 
que nous n'avons pas trouvé de fonctions GMP shiftant à droite ou à gauche. 
De ce fait, nous avons fait des divisions et multiplications qui sont 
très coûteuses. 
L'algorithme le plus rapide est donc la méthode itératif pour ce projet 
(voir Section "Notes"). 

Pour déterminer quel algorithme nous utiliser pour le calcul du 
PGCD et déterminer si deux nombres sont premiers entre eux, nous 
avons fait un banc d'essais. 
Pour cela, pour chaque test de nombre premier du fichier "Big Prime Numbers"
sur e-campus nous avons regardé combien durait le test avec 1 itération 
(en secondes). 
En sachant que 100 itérations permet d'être sûr cryptographiquement que le 
nombre est réellement premier. 

+--------------+-----------------+--------------------+---------------------+ 
|  Nombre      | Tps 1 itération |   Tps 1 itération  |  Tps 1 itération    | 
|  à tester    | méthode binaire |  méthode récursive |  méthode itérative  | 
+--------------+-----------------+--------------------+---------------------+ 
|   2^581 - 1  |      0.0255     |        0.0055      |         0.004       | 
+--------------+-----------------+--------------------+---------------------+ 
|  2^1279 - 1  |      0.158      |        0.036       |         0.0295      | 
+--------------+-----------------+--------------------+---------------------+ 
|   2^2281 - 1 |      0.6245     |        0.131       |         0.092       | 
+--------------+-----------------+--------------------+---------------------+ 
|   2^3217 - 1 |      1.524      |        0.2755      |         0.206       | 
+--------------+-----------------+--------------------+---------------------+ 
|   2^4423 - 1 |      3.5205     |        0.5695      |         0.4275      | 
+--------------+-----------------+--------------------+---------------------+ 
|   2^9941 - 1 |      28.337     |        3.851       |         2.944       | 
+--------------+-----------------+--------------------+---------------------+ 
|  2^11213 - 1 |      38.987     |       5.3895       |         4.019       | 
+--------------+-----------------+--------------------+---------------------+ 
|  2^19937 - 1 |      174.586    |       26.8665      |        17.9045      | 
+--------------+-----------------+--------------------+---------------------+ 
|  2^21701 - 1 |     214.9865    |       36.5815      |        22.1435      | 
+--------------+-----------------+--------------------+---------------------+ 
|  2^23209 - 1 |     261.5635    |       40.819       |        26.782       | 
+--------------+-----------------+--------------------+---------------------+ 

En étudiant ce BenchMark, nous en avons déduit qu'il était mieux d'utiliser 
la méthode itérative pour calculer le PGCD et ainsi trouver si deux nombres 
sont premiers entre eux. 
