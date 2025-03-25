# mini_pv

## Objectif

L'objectif de cet exercice est de recoder une version simplifiée de `pv` (Pipe Viewer), un outil permettant de visualiser la progression de la lecture d'un fichier en affichant le nombre d'octets lus ainsi que le débit.

## Fonctionnalités attendues

- Lire un fichier en entrée.
- Afficher la progression en pourcentage.
- Afficher le débit en bytes/sec.
- Gérer le temps écoulé entre chaque mise à jour de la progression.

## Compilation

Pour compiler votre programme, utilisez la commande suivante :

```bash
gcc -Wall -Wextra -Werror -o mini_pv mini_pv.c
```

### Exemple 0

Exécutez le programme avec un fichier en entrée :

```bash
$> ./mini_pv fichier_test > sortie
2025-03-25 17:27:19.868907: Progress 166519424 b / 4294967296 b (3.87 %). Bitrate: 166519520 bytes/sec.
2025-03-25 17:27:20.876843: Progress 334522368 b / 4294967296 b (7.78 %). Bitrate: 168002992 bytes/sec.
2025-03-25 17:27:21.884721: Progress 502005760 b / 4294967296 b (11.68 %). Bitrate: 167483552 bytes/sec.
2025-03-25 17:27:22.892597: Progress 669670656 b / 4294967296 b (15.59 %). Bitrate: 167664912 bytes/sec.
2025-03-25 17:27:23.900123: Progress 833292928 b / 4294967296 b (19.40 %). Bitrate: 163622352 bytes/sec.
2025-03-25 17:27:24.907544: Progress 994985984 b / 4294967296 b (23.16 %). Bitrate: 161693136 bytes/sec.
2025-03-25 17:27:25.915024: Progress 1158492288 b / 4294967296 b (26.97 %). Bitrate: 163506368 bytes/sec.
2025-03-25 17:27:26.921425: Progress 1316412032 b / 4294967296 b (30.65 %). Bitrate: 157919776 bytes/sec.
2025-03-25 17:27:27.928573: Progress 1477306752 b / 4294967296 b (34.39 %). Bitrate: 160894752 bytes/sec.
2025-03-25 17:27:28.936097: Progress 1637797632 b / 4294967296 b (38.13 %). Bitrate: 160491040 bytes/sec.
2025-03-25 17:27:29.943150: Progress 1796450816 b / 4294967296 b (41.82 %). Bitrate: 158653184 bytes/sec.
2025-03-25 17:27:30.950656: Progress 1959593344 b / 4294967296 b (45.62 %). Bitrate: 163142624 bytes/sec.
2025-03-25 17:27:31.957532: Progress 2116024704 b / 4294967296 b (49.26 %). Bitrate: 156431376 bytes/sec.
2025-03-25 17:27:32.965141: Progress 2275001600 b / 4294967296 b (52.96 %). Bitrate: 158977040 bytes/sec.
2025-03-25 17:27:33.970734: Progress 2424810880 b / 4294967296 b (56.45 %). Bitrate: 149809296 bytes/sec.
2025-03-25 17:27:34.977380: Progress 2566817408 b / 4294967296 b (59.76 %). Bitrate: 142006576 bytes/sec.
2025-03-25 17:27:35.983071: Progress 2713697664 b / 4294967296 b (63.18 %). Bitrate: 146880288 bytes/sec.
2025-03-25 17:27:36.988171: Progress 2848586624 b / 4294967296 b (66.32 %). Bitrate: 134888992 bytes/sec.
2025-03-25 17:27:37.993815: Progress 2990971520 b / 4294967296 b (69.63 %). Bitrate: 142384992 bytes/sec.
2025-03-25 17:27:39.000646: Progress 3137989248 b / 4294967296 b (73.06 %). Bitrate: 147017808 bytes/sec.
2025-03-25 17:27:40.006698: Progress 3279858048 b / 4294967296 b (76.36 %). Bitrate: 141868896 bytes/sec.
2025-03-25 17:27:41.011256: Progress 3404151424 b / 4294967296 b (79.25 %). Bitrate: 124293392 bytes/sec.
2025-03-25 17:27:42.015662: Progress 3518768768 b / 4294967296 b (81.92 %). Bitrate: 114617400 bytes/sec.
2025-03-25 17:27:43.019780: Progress 3625742336 b / 4294967296 b (84.41 %). Bitrate: 106973592 bytes/sec.
2025-03-25 17:27:44.023838: Progress 3739557120 b / 4294967296 b (87.06 %). Bitrate: 113814864 bytes/sec.
2025-03-25 17:27:45.029254: Progress 3850974208 b / 4294967296 b (89.66 %). Bitrate: 111417152 bytes/sec.
2025-03-25 17:27:46.030798: Progress 3953750400 b / 4294967296 b (92.05 %). Bitrate: 102776392 bytes/sec.
2025-03-25 17:27:47.035760: Progress 4076539008 b / 4294967296 b (94.91 %). Bitrate: 122788624 bytes/sec.
2025-03-25 17:27:48.041029: Progress 4190738944 b / 4294967296 b (97.57 %). Bitrate: 114200008 bytes/sec.
2025-03-25 17:27:48.953295: Progress 4294967296 b / 4294967296 b (100.00 %). Bitrate: 94727632 bytes/sec.
Done !
```

### Example 1

```bash
$> md5sum fichier_test
0926adf5480365f3c85d620706213d70  fichier_test
$> ./mini_pv fichier_test > sortie
...
Done !
$> md5sum sortie
0926adf5480365f3c85d620706213d70  sortie
```

### Example 2

```bash
$> ./mini_pv /dev/urandom > sortie_random
2025-03-25 17:28:14.464121: Progress 116654080 b / 0 b (inf %). Bitrate: 116654160 bytes/sec.
2025-03-25 17:28:15.470127: Progress 234068480 b / 0 b (inf %). Bitrate: 117414456 bytes/sec.
... 
```

L\'utilisateur appuie sur <Ctrl+C>

```
Done !
```

### Example 3

```bash
$> ./mini_pv fichier_test 2> /dev/null 1> sortie
$> md5sum sortie
0926adf5480365f3c85d620706213d70  sortie
```


## Remarques

- Nous prendrons en compte le travail d\'optimisation de votre code.