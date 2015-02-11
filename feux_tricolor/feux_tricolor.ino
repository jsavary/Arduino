/*
 * Programme pour arduino uno
 * par C. Bézanger Octobre 2013
 * Licence GNU GPLv3
 * 
 * Ce programme fait fonctionner des feux tricolores.
 * Six LED (vertes, oranges et rouge) sont reliées aux sorties 4 à  9
 * Les sorties 4 à  6 forment le feu A1
 * Les sorties 7 à  9 forment le feu B1
 */
     
// Initialisation des variables
const byte A1V = 4 ;
const byte A1O = 5 ;
const byte A1R = 6 ;
const byte B1V = 7 ;
const byte B1O = 8 ;
const byte B1R = 9 ;
const byte LedArduino = 13 ;
//Délai des différents temps mis en const pour changer facilement 
// si le délai imparti ne vous satisfait pas. Il s'agit de millisecondes
const long TempsAttenteFeuRougeSeul = 1000;
const long TempsAttenteFeuVert = 7500;
const long TempsAttenteFeuOrange = 2500;
     
// Initialisation des lignes 4 à  9 en sortie
void setup () {
  pinMode (A1V, OUTPUT) ;
  pinMode (A1O, OUTPUT) ;
  pinMode (A1R, OUTPUT) ;
  pinMode (B1V, OUTPUT) ;
  pinMode (B1O, OUTPUT) ;
  pinMode (B1R, OUTPUT) ;
  pinMode (LedArduino, OUTPUT) ;
}
 
// Fonction loop
void loop () {
  // Extinction de toutes les LED au départ
  digitalWrite (LedArduino, LOW) ;   
  digitalWrite (A1V, LOW) ;
  digitalWrite (A1O, LOW) ;
  digitalWrite (A1R, LOW) ;
  digitalWrite (B1V, LOW) ;
  digitalWrite (B1O, LOW) ;
  digitalWrite (B1R, LOW) ; 

     
  // Allumage de A1V et B1R
  digitalWrite (A1V, HIGH) ;
  digitalWrite (B1R, HIGH) ;
     
  // Début de cycle
   
  // Concerne le feu A1
  delay (TempsAttenteFeuVert) ; // Feu vert A1V pendant 30 secondes
  digitalWrite (A1V, LOW) ; // Extinction de A1V
  digitalWrite (A1O, HIGH) ; // et allumage de A1O
  delay (TempsAttenteFeuOrange) ; //durée 5 secondes
  digitalWrite (A1O, LOW) ; // Extinction de A1O
  digitalWrite (A1R, HIGH) ; // et allumage de A1R
  delay (TempsAttenteFeuRougeSeul) ; // Temporisation du chauffard !

     
  // Concerne l'autre feu B1
  digitalWrite (B1R, LOW) ; // Extinction de B1R
  digitalWrite (B1V, HIGH) ; // et allumage de B1V
  delay (TempsAttenteFeuVert) ; // Feu vert B1V pendant 30 secondes
  digitalWrite (B1V, LOW) ; // Extinction de B1V
  digitalWrite (B1O, HIGH) ; // et allumage de B1O
  delay (TempsAttenteFeuOrange) ; // durée 5 secondes
  digitalWrite (B1O, LOW) ; // Extinction de B1O
  digitalWrite (B1R, HIGH) ; // et allumage de B1R
  delay (TempsAttenteFeuRougeSeul) ; // Temporisation du chauffard !
  digitalWrite (A1V, HIGH) ; // On est revenu au point de départ
     
  // Feu A1 vert et feu B1 rouge : le cycle peut recommencer
}
