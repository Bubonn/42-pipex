# 42-pipex

Bienvenue dans le projet pipex de l'école 42. Ce projet consiste à recréer le fonctionnement de l'opérateur de pipe "|" en utilisant les fonctions execve, dup2 et fork en C. L'objectif est de comprendre le concept de redirection des flux de données entre deux processus.

## Table des matières

- [Introduction](#introduction)
- [Objectif](#objectif)
- [Instructions](#instructions)
- [Utilisation](#utilisation)
- [Exemple](#exemple)

## Introduction

Le projet pipex nous permet de comprendre comment les opérations de pipe sont effectuées en interne par le système d'exploitation. Nous devons créer un programme qui prend deux fichiers en entrée, effectue une opération de pipe entre le premier fichier et redirige la sortie vers le deuxieme fichier.

## Objectif

L'objectif principal de ce projet est d'apprendre à manipuler les descripteurs de fichiers, à créer des processus en utilisant fork, et à gérer les redirections de flux de données. Nous devons également gérer les erreurs et les cas d'utilisation inattendus.

## Instructions

Le projet pipex est divisé en plusieurs étapes :

1. Parsez les arguments de la ligne de commande pour obtenir les noms des fichiers d'entrée, de sortie et la commande à exécuter.

2. Utilisez fork pour créer deux processus enfants.

3. Redirigez les descripteurs de fichiers standard (stdin, stdout) pour que le premier processus lise à partir du premier fichier d'entrée et que le second écrive dans le second fichier de sortie.

4. Exécuter la commande spécifiée dans le premier processus et s'assurer que la sortie est redirigée vers le deuxième processus.

5. Attendre que les deux processus se terminent.

6. Gérer les erreurs et affichez les messages appropriés en cas d'échec.

## Utilisation

Pour compiler le projet, exécutez la commande `make` dans le répertoire du projet. Cela créera un exécutable appelé `pipex`.

Pour utiliser le programme, vous pouvez l'appeler de la manière suivante :

```shell
./pipex file1 cmd1 cmd2 file2
```

- `file1` : Le premier fichier d'entrée.
- `cmd1` : La première commande à exécuter.
- `cmd2` : La deuxième commande à exécuter.
- `file2` : Le deuxième fichier de sortie.

## Exemple

`./pipex infile "ls -l" "grep pipex" outfile`

Ce commandement exécutera la commande "ls -l" avec infile comme entrée, puis prendra la sortie de cette commande et l'utilisera comme entrée pour la commande "grep pipex". Enfin, la sortie de "grep pipex" sera stockée dans outfile.


## Bonus

### Gestion de plusieurs pipes

Pour gagner des points bonus, j'ai du implémenter la gestion de plusieurs pipes. Cela signifie que mon programme doit être capable de prendre en charge plusieurs commandes connectées par des pipes de la manière suivante :

```shell
./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
```

La gestion de plusieurs pipes constitue un défi supplémentaire, car vous j'ai du créer des processus enfants pour chaque commande et gérer les pipes entre eux de manière appropriée.

### Gestion de l'opérateur "here_doc"

Un autre bonus que j'ai implémenté est de gérer l'opérateur "here_doc" lorsque le premier paramètre est "here_doc". Cela signifie que mon programme doit être capable de gérer une entrée spéciale de type "here document", qui est utilisée pour fournir des données à la première commande. Voici comment cela fonctionne :
`./pipex here_doc LIMITER cmd cmd1 file`

Mon programme doit fonctionner de manière identique à la commande suivante en utilisant l'opérateur "here_doc" :
`cmd << LIMITER | cmd1 >> file`

La gestion de l'opérateur "here_doc" implique de lire des données depuis l'entrée standard jusqu'à ce que la limite spécifiée soit atteinte, puis de les fournir en tant qu'entrée à la première commande.
