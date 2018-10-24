Projet JTiger : TD 2A
=====================

Mise en place
-------------

Récupérez et décompressez l'archive contenant le code fourni pour ce livrable <http://tahiti.prism.uvsq.fr/tigergrader/static/support/livrable-T2A.zip>.

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

Parseur
-------

Le but de ce livrable est d'écrire un parseur. Un parseur prends en entrée un
ensemble d'unitées lexicales produites par le Lexeur, et réalise une analyse
syntaxique. Le but du livrable T2 est d'écrire un parseur simple pour un
sous-ensemble de Tiger. Dans le prochain livrable, T3, nous compléterons le T2
pour générer un Arbre de Syntaxe Abstraite sur le langage complet Tiger.

Prennons un exemple, voici le code pour calculer une factorielle en Tiger:

~~~tiger
let
  function factorial(n: int) : int =
    if n=0 then 1
    else n * factorial(n - 1)
in
  print ("factorial ");
  print_int (6); 
  print (" = ");
  printint (factorial (6)) 
end
~~~

Voici le résultat attendu, en fin du TP 3. C'est un arbre de syntaxe abstraite (AST) qui capture la grammaire
du programme original.

~~~tree
      SeqExp [pos='0:0' _typeDefinition='null']
        LetExp [pos='1:1' _typeDefinition='null']
          FuncsDec [pos='2:3']
            FuncDec [pos='2:3' _label='_L2factorial' _resultTypeDefinition='null' _depth='0' name='factorial' result='int']
              VarDec [pos='2:22' _typeDefinition='null' _forVariable='null' _depth='0' _access='null' _escapes='false' name='n' type='int']
              IfExp [pos='3:5' _typeDefinition='null']
                OpExp [pos='3:9' _typeDefinition='null' op='=']
                  SimpleVar [pos='3:8' _typeDefinition='null' _declaration='null' _depth='0' name='n']
                  IntegerExp [pos='3:10' _typeDefinition='null' value='0']
                IntegerExp [pos='3:17' _typeDefinition='null' value='1']
                OpExp [pos='4:12' _typeDefinition='null' op='*']
                  SimpleVar [pos='4:10' _typeDefinition='null' _declaration='null' _depth='0' name='n']
                  CallExp [pos='4:14' _typeDefinition='null' _declaration='null' _depth='0' func='factorial']
                    OpExp [pos='4:26' _typeDefinition='null' op='-']
                      SimpleVar [pos='4:24' _typeDefinition='null' _declaration='null' _depth='0' name='n']
                      IntegerExp [pos='4:28' _typeDefinition='null' value='1']
          SeqExp [pos='10:3' _typeDefinition='null']
            CallExp [pos='7:3' _typeDefinition='null' _declaration='null' _depth='0' func='print']
              StringExp [pos='7:21' _typeDefinition='null' value='factorial ']
            CallExp [pos='8:3' _typeDefinition='null' _declaration='null' _depth='0' func='print_int']
              IntegerExp [pos='8:14' _typeDefinition='null' value='6']
            CallExp [pos='9:3' _typeDefinition='null' _declaration='null' _depth='0' func='print']
              StringExp [pos='9:14' _typeDefinition='null' value=' = ']
            CallExp [pos='10:3' _typeDefinition='null' _declaration='null' _depth='0' func='print_int']
              CallExp [pos='10:14' _typeDefinition='null' _declaration='null' _depth='0' func='factorial']
                IntegerExp [pos='10:25' _typeDefinition='null' value='6']
        IntegerExp [pos='0:0' _typeDefinition='null' value='0']
~~~


La syntaxe de Tiger est décrite par la grammaire suivante, ici exprimée dans le format _Extended Backus–Naur Form (EBNF)_: 

~~~ebnf
     program ::=
         exp
       | decs
     
     exp ::=
       # Literals.
         nil
       | integer
       | string
     
       # Array and record creations.
       | type-id [ exp ] of exp
       | type-id {[ id = exp { , id = exp } ] }
     
       # Variables, field, elements of an array.
       | lvalue
     
       # Function call.
       | id ( [ exp { , exp }] )
     
       # Operations.
       | - exp
       | exp op exp
       | ( exps )
     
       # Assignment.
       | lvalue := exp
     
       # Control structures.
       | if exp then exp [else exp]
       | while exp do exp
       | for id := exp to exp do exp
       | break
       | let decs in exps end
     
     lvalue ::= id
       | lvalue . id
       | lvalue [ exp ]
     exps ::= [ exp { ; exp } ]
     
     decs ::= { dec }
     dec ::=
       # Type declaration.
         type id = ty
       # Variable declaration.
       | vardec
       # Function declaration.
       | function id ( tyfields ) [ : type-id ] = exp
     
     vardec ::= var id [ : type-id ] := exp
     
     # Types.
     ty ::=
        # Type alias.
          type-id
        # Record type definition.
        | { tyfields  }
        # Array type definition.
        | array of type-id
     tyfields ::= [ id : type-id { , id : type-id } ]
     type-id ::= id
     
     op ::= + | - | * | / | = | <> | > | < | >= | <= | & | |
~~~

Cette grammaire, est _Context Free_. Pour la reconnaître nous allons utiliser
l'analyse _Look-Ahead Left Recursive(LALR)_ décrite en cours.  Comme il est
fastidieux d'implémenter les différents automates et tables à la main, nous
utiliserons le générateur de parseur _JCUP_, dont la documentation est disponible
à l'adresse <http://www2.cs.tum.edu/projects/cup/manual.html>.


(@) Lisez la section 1 de la documentation de JCup.

### Reconnaître et manipuler les expressions arithméthiques 

Vous allez d'abord reconnaître un sous-ensemble simple de Tiger, de manière à
vous familiariser avec l'outil. Le sous-ensemble simple est celui des expressions
arithmétiques et logiques, il est décrit par la grammaire suivante:

~~~ebnf
     program ::=
         exp

     exp ::=
       # Literals.
       integer
     
       # Operations.
       | - exp
       | exp op exp
       | ( exp )
     
     op ::= + | - | * | / | = | <> | > | < | >= | <= | & | |
~~~
 

Précédence des opérateurs (de la plus haute à la plus faible)
~~~
     - unaire
     * /
     + -
     >= <= = <> < >
     &
     |
~~~

Les opérateurs de comparaison (``<``, ``<=``, ``=``, ``<>``, ``>``, ``>=``) sont non associatifs.
Tous les autres opérateurs associent à gauche.

Le fichier ``src/jtiger/parser/tiger.cup`` définit les règles de la grammaire.


Le but du parseur que nous allons écrire et de reconnaître une expression arithméthique et de calculer
le résultat.

Par exemple, si on appelle le programme sur le fichier contenant ``(14 + 6) *
2`` nous afficherons la valeur 40.  Pour les opérateurs logiques, 0 est faux et
toute autre valeur est vraie.  Par ailleurs, les opérateurs logiques
retourneront 0 pour faux et 1 pour vrai. Par exemple, si on appelle le parseur
sur ``20 = (20 + 1)`` il affichera la valeur 0. 

(@) Écrire les règles de la grammaire. Ici tous les non-terminaux doivent retourner un type ``Integer``.

(@) Il est possible que vous rencontriez des conflits Shift/Reduce, rajoutez
les règles de précédence sur les opérateurs pour les corriger.

Normalement, si vous n'avez pas commis d'erreurs, vous devez passer les tests 1 à 10.

(@) Comment est parsée l'expression ``- 4 * 5`` ? Est-ce sous la forme de l'arbre de droite ou de gauche ?

~~~tree
        *               - 
       / \              |
      -   5             *
     /                 / \
    4                 4   5
~~~

Pour le langage Tiger, peut importe quel arbre de parsing est choisi. Néanmoins dans d'autres
langages on souhaite que le ``-`` unaire soit plus prioritaire que la multiplication. 
Pour résoudre le problème, JCUP implemente le méchanisme de *Contextual precedence assignments*.
Regardez dans la documentation comment ce méchanisme fonctionne. 

(@) Implémentez le *Contextual precedence assignment* pour le ``-`` unaire.









