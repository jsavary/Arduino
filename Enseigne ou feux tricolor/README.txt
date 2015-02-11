Voici un petit schema de montage fait avec Fritzing ainsi que le code source pour ce montage.

le fichier INO est développé pour un Arduino UNO.
il permet de lancer un fonction A ou une fonction B selon la position de l'interrupteur du montage.

les fonctions A ( http://www.locoduino.org/spip.php?article2 ) et B ( http://www.locoduino.org/spip.php?article3 )  sont ici reprises depuis le site http://www.locoduino.org.

la partie personnelle ( void loop ) n'est pas tres compliquée.
elle regarde la tension sur la broche 2 du montage.

si la tension est de 5V, la fonction A est lancée.
si la tention est de 0V, la fonction B est lancée.

NB: le montage sur la broche N° 3 n'est pas utile, mais l'interrupteur que j'avais sous la main me permet d'avoir 2 sorties.
