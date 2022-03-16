<!--

	DETAILS.md

	By: xbeheydt <xavier.beheydt@gmail.com>

	Created: 2022/02/21

-->
# 42 Cursurs - Push Swap - Détails et Explications

Le projet doit permet le tri de nombres entiers aléatoires donnés en argument
en se limitant à avoir deux piles de stockage de données (soit deux tableaux, 
`stack_a` et `stack_b`) sans duplication des valeurs, tout en se limitant à
des fonctions modificatrices impossées.

## Recherches et Tests

Ce projet introduit de manière formelle la comprehension de l'algorithmie et
d'une mise en application plus profonde. Cela inclut de voir le code en tant
qu'algorithme et de part ce fait de voir qu'un besoin - ici le tri - peut être
réalisé par plusieurs algorithmes différents.

Une autre notion qui va être abordé est la performance d'un algorithme.

**Algorithmie - Le tri de valeurs**

Le tri est la partie centrale du projet et cette partie est sujet à plusieurs
réflexions.

En algorithmie, il existe pas mal d'algorithmes différents mais ayant des
performances chageantes selon plusieurs critères (nombre de valeurs à trier,
tableau plus ou moins déjà trié, ...).

Voici une liste non exaustives d'algorithme de tri :

- trie par bulle,
- trie par selection,
- trie par insertion,
- trie rapide,
- trie de tas,
- trie par fusion,
- trie de base,
- trie par comptage.

> Il en existe certainement encore pas mal et une partie plus exotique.
> Certains ne seront pas forcement adaptés car ils sont adaptés à d'autres
> types de données.


## Mandatory

**Les arguments**

Le projet demande d'avoir des un nombre d'arguments en nombre indéfini. Ces
arguments doivent être des nombres entiers donc de `INT_MIN = -2147483648` à
`INT_MAX = +2147483647`, soit `4294967296` valeurs possibles par argument.

Il faudra donc gérer l'erreur d'une valeur non numérique et peut être d'une
valeur dépassant `INT_MIN` et `INT_MAX` (vu que le projet indique nombres
entiers).

Le parsing peut être fait sur plusieurs chaînes de caractères ou une seule avec
des espaces entre les valeurs. Exemple :

```bash
# Une chaine avec espace
./push_swap "1 35 643 433 12"

# Une chaine avec espace depuis une variable
ARGS="1 35 643 433 12"; ./push_swap $ARGS_

# Plusieurs chaines
./push_swap 1 35 643 433 12
```

**Les fonctions modificatrices**

Le projet impose des fonctions de modifications des piles afin d'effectuer
le trie des valeurs. Nous avons donc :

- `sa` (swap a) : intervertir les deux premiers éléments de la pile a.
- `sb` (swap b) : intervertir les deux premiers éléments de la pile b.
- `ss` : swap a et swap b en même temps.
- `pa` (push a) : prendre le premier élément du haut de la pile b et le mettre
	en haut de la pile a.
- `pb` (push b) : prendre le premier élément du haut de la pile a et le mettre
	en haut de la pile b.
- `ra` (rotate a) : remonter les éléments de la pile a vers le haut en
	replaçant le premier élément au pied de la pile.
- `rb` (rotate b) : remonter les éléments de la pile b vers le haut en
	replaçant le premier élément au pied de la pile.
- `rr` : la rotation sur les piles a et b en même temps.
- `rra` (reverse rotate a) : redescendre les éléments de la pile a vers le bas
	en replaçant le dernier élément en haut de la pile.
- `rrb` (reverse rotate b) : redescendre les éléments de la pile b vers le bas
	en replaçant le dernier élément en haut de la pile.
- `rrr` : la rotation inverse des piles a et b en même temps.

**Analyse des valeurs**

Durant la phase de parsing des arguments et afin de remplir la pile a. Il sera
possible d'effectuer une analyse des données. Afin de déterminer quel est
l'état de tri au démarrage.

