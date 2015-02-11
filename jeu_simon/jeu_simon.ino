//Simon

//---------------------------------------------------------
//Initialisation des LEDs et boutons poussoirs.
int led1 = 2; //LED rouge
int led2 = 3; //LED verte
int led3 = 4; //LED bleue
int led4 = 5; //LED jaune
int bouton1 = 6; //Bouton rouge
int bouton2 = 7; //Bouton vert
int bouton3 = 8; //Bouton bleu
int bouton4 = 9; //Bouton jaune
int speaker = 10; //Speaker

//Les numéros correspondent aux numéros d'entrées/sorties.
//Les 0 et 1 sont réservés aux transmissions/réceptions.

//Fréquences des sons de chaque couleur
int son[] = {261, 330, 392, 523};
//            Do,  Mi, Sol,  Do

//Tableau de séquence à jouer
int sequence[50];
//Personne ne dépasse jamais le niveau 50...

//---------------------------------------------------------
// Routine d'initialisation.
// Le setup sera appelée à chaque démarrage ou reset.

void setup()
{
  //Initialisation des entrées/sorties
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(bouton1, INPUT);
  pinMode(bouton2, INPUT);
  pinMode(bouton3, INPUT);
  pinMode(bouton4, INPUT);
  pinMode(speaker, OUTPUT);
}

//---------------------------------------------------------
// Boucle principale.
// La loop tournera jusqu'à extinction ou reset.

void loop()
{
  randomSeed(analogRead(A0));

  //Attente de pression sur une touche.
  lectureBouton();

  //Témoin de lancement du jeu.
  melodieLancement();
  delay(2000);

  //Début du jeu
  boolean gameOver = false;
  int presse;
  int niveau = 0;
  while(!gameOver)
  {
    nouvelleNote(niveau); //Rajoute une note à la séquence.
    jouerSequence(niveau); //Joue la séquence

    for(int i=0; i<=niveau; i++) //Attend que le joueur tape chaque note de la séquence
    {
      presse = lectureBouton(); //Lecture du bouton appuyé par le joueur
      jouerNote(presse); //Joue la note du joueur
      if(presse!=sequence[i]) //Si la note est bonne, on continue, sinon GameOver
      {
        gameOver = true;
        melodieGameOver();
      }
      if(gameOver) {break;}
    }
    niveau++;
    delay(1000);
  }
}

//---------------------------------------------------------
//Fonction de lecture des boutons.
  //L'arduino vérifie les boutons un par un, mais comme la vitesse d'une vérification
  //est de l'ordre de la nanoseconde, l'ensemble est presque instantané.
int lectureBouton()
{
  int boutonPresse = 0;

  while(!boutonPresse)
  {
    if(digitalRead(bouton1))
    {
      boutonPresse = 1;
    }
    if(digitalRead(bouton2))
    {
      boutonPresse = 2;
    }
    if(digitalRead(bouton3))
    {
      boutonPresse = 3;
    }
    if(digitalRead(bouton4))
    {
      boutonPresse = 4;
    }
  }
  return boutonPresse;
}
//---------------------------------------------------------
//Fonction de lumière et de son
void jouerNote(int numero)
{
  switch(numero)
  {
    case 1:
      digitalWrite(led1, HIGH);
      break;
    case 2:
      digitalWrite(led2, HIGH);
      break;
    case 3:
      digitalWrite(led3, HIGH);
      break;
    case 4:
      digitalWrite(led4, HIGH);
      break;
  }
  tone(speaker, son[numero-1]); //Le tableau commence à 0 (non à 1)
  delay(800);

  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  noTone(speaker);

  delay(200);
}

//---------------------------------------------------------
//Joue toute la séquence
void jouerSequence(int niveau)
{
  for(int i=0; i<=niveau; i++)
  {
    jouerNote(sequence[i]);
  }
}
//---------------------------------------------------------
//Nouvelle note aléatoire
void nouvelleNote(int niveau)
{
  sequence[niveau] = (int)random(1,5);
}

//---------------------------------------------------------
//Témoin lancement (petite séquence lumineuse)
void melodieLancement()
{
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  tone(speaker, son[0]);
  delay(300);
  tone(speaker, son[1]);
  delay(300);
  tone(speaker, son[2]);
  delay(300);
  tone(speaker, son[3]);
  delay(300);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  noTone(speaker);
}

//---------------------------------------------------------
//Témoin Game Over
void melodieGameOver()
{
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  tone(speaker, son[3]);
  delay(150);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  delay(150);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  tone(speaker, son[2]);
  delay(150);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  tone(speaker, son[1]);
  delay(150);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  tone(speaker, son[0]);
  delay(150);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  delay(500);
  noTone(speaker);
}


