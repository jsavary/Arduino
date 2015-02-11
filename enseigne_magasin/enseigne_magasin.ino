/*
 * Programme pour arduino uno
 * par C. Bézanger Octobre 2013
 * Licence GNU GPLv3
 *
 * Ce programme réalise le clignotement d'une enseigne publicitaire.
 * Il fait clignoter selon un certain rythme six DEL reliées aux sorties 4 à  9.
 * Il utilise des fonctions pour alterner les rythmes.
*/
 
/*
 * Initialisation des broches 4 à 9 en sortie
 */
void setup () {
  pinMode (2, OUTPUT) ;
  pinMode (3, OUTPUT) ;
  pinMode (4, OUTPUT) ;
  pinMode (5, OUTPUT) ;
  pinMode (6, OUTPUT) ;
  pinMode (7, OUTPUT) ;
  pinMode (8, OUTPUT) ;
  pinMode (9, OUTPUT) ;
  pinMode (10, OUTPUT) ;
  pinMode (11, OUTPUT) ;
  pinMode (12, OUTPUT) ;
  pinMode (13, OUTPUT) ;
}
 
/*
 * Fonction loop
 */
void loop () {
  // Extinction de toutes les DEL au départ du programme
  for (byte i = 2 ; i <= 13 ; i++) 
  {
    digitalWrite (i, LOW) ; // éteint la DEL reliée à la broche i
  }
      
      
  // Séquence N°1 ; chenillard
  sequence_Un () ;
  delay (500) ;  // délai de 500 millisecondes
 
  // Séquence N°2 : cumul sur la gauche du mouvement de DEL
  sequence_Deux () ;
  delay (500) ;  // délai de 500 millisecondes
  
  // Séquence N°3 : clignotement de l'ensemble 3 fois
  sequence_Trois () ;
  delay (2000) ; // délai de 2 secondes
 
  // Séquence 4 : extinction successive de la gauche vers la droite
  sequence_Quatre () ;
  delay (2000) ; 
  
  // Recommence la séquence
}
 
/*
 * Séquence N°1 ; chenillard
 */
void sequence_Un ()
{
  for (byte n = 0 ; n <= 2 ; n++)
  {
    for (byte i = 2 ; i <= 13 ; i++)
    {
      digitalWrite (i, HIGH) ;    // allume la DEL sur broche i
      delay (100) ;               // durée du flash 150 millisecondes
      digitalWrite (i, LOW) ;     // éteint la DEL
      delay (50) ;
    }
  }
}
 
/*
 * Séquence N° 2 : cumul sur la gauche du mouvement de DEL
 */
void sequence_Deux ()
{
  for (byte n = 0 ; n <= 11 ; n++)
  {
    for (byte i = 2 ; i <= (13-n) ; i++)
    {
      digitalWrite (i, HIGH) ; // allume la DEL sur broche i
      delay (150) ;            // durée du flash 150 millisecondes
      digitalWrite (i, LOW) ;  // éteint la DEL
    }
    digitalWrite ( (13 - n) , HIGH ) ; // dernière DEL reste allumée
  }
}
 
/*
 * Séquence N°3 : clignotement de l'ensemble 3 fois
 */
void sequence_Trois ()
{
  for (byte j = 1 ; j <= 3 ; j++) 
  {
    for (byte k = 2 ; k <= 13 ; k++) 
    {
      digitalWrite (k , LOW) ;
    }
    delay (500) ;
    for (byte l = 2 ; l <= 13 ; l++) 
    {
      digitalWrite (l, HIGH) ;
    }
    delay (500) ;
  }
}
 
/*
 * Séquence 4 : extinction successive de la gauche vers la droite
 */
void sequence_Quatre ()
{
  for (byte i = 13 ; i >= 2 ; i--) 
  {
    digitalWrite (i, LOW) ;
    delay (150);
  }
}
