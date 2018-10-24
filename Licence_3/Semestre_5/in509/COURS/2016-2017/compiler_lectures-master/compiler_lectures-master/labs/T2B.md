Projet JTiger : TD 2B
=====================

Mise en place
-------------

Récupérez et décompressez l'archive contenant le code fourni pour ce livrable <http://tahiti.prism.uvsq.fr/tigergrader/static/support/livrable-T2B.zip>.

Un fichier build.xml (équivalent d'un Makefile) est inclus.
Pour compiler les sources tapez :

~~~bash
$ ant
...
BUILD SUCCESSFUL
Total time: 1 second
~~~

Si tout ce passe bien, un ficher ``JTiger.jar`` est produit dans ``dist/lib``.
Pour que Java puisse le trouver il faut le rajouter à la variable 
d'environnement ``CLASSPATH``. Le script ``setenv.sh`` s'en charge:

~~~bash
$ . setenv.sh  # ATTENTION: le point (équivalent de source) est important!
~~~

Nous pouvons maintenant essayer de lancer notre compilateur:

~~~bash
$ java jtiger.cli.Compile
usage: jtiger {-l} input.tig
 -s,--scaner   dump lexer output
 -p,--parser   dump parser output
Missing required option: [-s dump lexer output, -p dump parser output]
~~~

Pour envoyer votre projet au serveur de notation, il faut créer une archive des sources:

~~~bash
$ ant zip-src
~~~

### Reconnaître et manipuler les expressions arithméthiques (Partie 2) 

Nous allons modifier le parseur que vous avez effectué dans la première partie
de ce TP.  Cette fois ci au lieu de calculer le résultat d'une expression
arithmétique on va construire l'arbre de syntaxe abstraite associé.

Nous allons également rajouter une nouvelle règle à la grammaire qui va
nous permettre de concatener plusieurs expressions à la suite. Cela permettra
d'écrire des programmes comme (1+2 ; 3*54+2; 42).

Un arbre de syntaxe abstraite associe un noeud à chaque règle de production de la grammaire.
Nous donnons ci-dessous la correspondance entre règle de production
et noeud dans l'AST produit.

~~~ebnf
     program ::= exp                    (AST: noeud Exp) 

     exp ::= intExp                     (AST: noeud Exp)
           | seqExp
           | opExp
           | negExp

     intExp ::= INT                     (AST: noeud IntegerExp)
     seqExp ::= ( exps )                (AST: noeud Exp)  

     exps ::= [ exp { ; exp } ]         (AST: SeqExp)

     opExp ::= exp op exp               (AST: OpExp)
             | exp & exp                (AST: IfExp, on produit l'arbre IF (e1) THEN e2 ELSE 0)
             | exp | exp                (AST: IfExp, on produit l'arbre IF (e1) THEN 1 ELSE e2)

     negExp ::= - exp                   (AST: OpExp, on produit l'arbre 0 - exp) 

     op ::= + | - | * | / | = | <> | > | < | >= | <=
~~~

Par exemple, le programme

~~~tiger
(1+2; 3*(4+5))
~~~

va produire l'arbre suivant:

~~~tree
  SeqExp [pos='1:8' _typeDefinition='null']
    OpExp [pos='1:3' _typeDefinition='null' op='+']
      IntegerExp [pos='1:2' _typeDefinition='null' value='1']
      IntegerExp [pos='1:4' _typeDefinition='null' value='2']
    OpExp [pos='1:8' _typeDefinition='null' op='*']
      IntegerExp [pos='1:7' _typeDefinition='null' value='3']
      SeqExp [pos='1:11' _typeDefinition='null']
        OpExp [pos='1:11' _typeDefinition='null' op='+']
          IntegerExp [pos='1:10' _typeDefinition='null' value='4']
          IntegerExp [pos='1:12' _typeDefinition='null' value='5']
~~~

<img src="/tigergrader/static/support/ast.png" height="300px">

Le noeud racine est de type SeqExp et correspond à la concatenation
de plusieurs expressions. Ici les deux expressions filles, sont de
type OpExp.

Le fichier ``src/jtiger/parser/tiger.cup`` définit les règles de la grammaire.

(@) Étudier les fichiers dans ``src/jtiger/ast/`` pour comprendre comment sont
    définis les noeuds de l'AST.

(@) Implémenter toutes les règles sauf ``seqExp``, ``negExp`` et ``opExp`` avec ``&`` et ``|``.

(@) Implémenter la règle pour ``negExp``. Ici l'idée c'est que lorsque le programme ``-4`` est
    reconnu on génère l'AST pour ``0 - 4`` en utilisant un noeud ``opExp``.

(@) Implémenter la règle pour ``&`` et ``|``. L'idée est d'utiliser un noeud ``ifExp``. 

(@) Implémenter la règle pour ``seqExp``. Attention le parseur doit reconnaître la
    liste vide ``()``. Il n'est pas légal d'utiliser un point virgule s'il n'est pas suivi d'une expression.
    Par exemple, ``(1+3;)`` doit lever une erreur de parser.
