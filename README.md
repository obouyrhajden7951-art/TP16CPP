# TP17CPP

# Exercice 1 : Singleton

Pourquoi le constructeur est privé ?
Pour que personne ne puisse créer d’objet avec Configuration c;. Seule la méthode getInstance() peut le créer, donc il n’y a qu’un seul objet.

Limites en multithread ?
Si deux threads créent l’objet en même temps, on peut avoir deux objets. Il faut utiliser un mutex. Aussi, si deux threads modifient les données en même temps, il y a des problèmes.

<img width="782" height="360" alt="image" src="https://github.com/user-attachments/assets/ab23a9f4-907a-44e8-b2e2-93549179db54" />

# Exercice 2 : Factory

Utilité pour l’extension future ?
Pour ajouter une nouvelle forme, on ajoute juste une classe et une ligne dans la fabrique. Le code client ne change pas.

Avec FabriqueAbstraite ?
Chaque forme a sa propre fabrique. Pour ajouter une forme, on crée une nouvelle fabrique sans modifier les autres.

<img width="779" height="322" alt="image" src="https://github.com/user-attachments/assets/6a613a80-7387-4864-857a-14ad937d39fe" />

# Exercice 3 : Observer

Éviter la dépendance ?
La station connaît seulement l’interface Observateur, pas les vrais affichages. On peut ajouter ou enlever un affichage facilement.

Alternative moderne ?
std::function avec des lambdas (callbacks).

<img width="775" height="355" alt="image" src="https://github.com/user-attachments/assets/933c7611-63a4-4440-a31c-d934e553e401" />


# Exercice 4 : Strategy

Maintenabilité ?
Chaque tri est dans sa propre classe. On peut ajouter un tri sans modifier le reste, et changer de tri pendant l’exécution.

Différence avec Template Method ?

Strategy : on utilise la composition, et on change tout l’algorithme.
Template Method : on utilise l’héritage, et on change seulement certaines étapes.
<img width="778" height="249" alt="image" src="https://github.com/user-attachments/assets/5521a6d1-822a-4c48-a5a3-70b4f94c1d96" />

