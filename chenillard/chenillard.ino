/*
 * Programme pour arduino uno
 * Projet APTE Loco-Revue
 * par C. Bézanger Octobre 2013
 * Licence GNU GPLv3
 *
 * Ce programme réalise un chenillard.
 * Il fait flasher successivement six DEL oranges relées aux sorties 4 à 9
 * Puis il réalise une pause de 500 millisecondes avant de recommencer
 */
// Initialisation des lignes 4 à 9 en sortie
void setup () {
  pinMode (4, OUTPUT) ;
  pinMode (5, OUTPUT) ;
  pinMode (6, OUTPUT) ;
  pinMode (7, OUTPUT) ;
  pinMode (8, OUTPUT) ;
  pinMode (9, OUTPUT) ;
  pinMode (13, OUTPUT) ;
}
// Fonction loop
void loop () {
  // Extinction de toutes les DEL au départ du programme
  for (byte i = 4 ; i <= 9 ; i++) {
    digitalWrite (i, LOW) ; // éteint la DEL reliée à la broche i
  }
    digitalWrite (13, LOW) ;  
  // Boucle pour faire flasher les DEL
  for (byte i = 4 ; i <= 9 ; i++) {
    digitalWrite (i, HIGH) ; // allume la DEL sur broche i
    delay (50) ; // durée du flash 50 millisecondes
    digitalWrite (i, LOW) ; // éteint la DEL
  }
  
  // délai de 500 millisecondes
  delay (500) ;
  
  // Recommence la séquence
}
