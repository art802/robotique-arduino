char tableau[3];

char test = 32;
void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  
  Serial.begin(9600);
  Serial.println(tableau[0], DEC);
}

void loop()
{
  //Controle de la LED bleue
  if(Serial.available() >= 3)
  {
    for(char i = 0; i<3; i++)
    {
      tableau[i] = Serial.read();
    }
    
    if(tableau[0] == 'b')
    {
      if(tableau[2] == 'a')
      {
        digitalWrite(2, HIGH);
      }
      if(tableau[2] == 'e')
      {
        digitalWrite(2, LOW);
      }
    }
    
    //Controle de la led rouge
    
    if(tableau[0] == 'r')
    {
      if(tableau[2] == 'a')
      {
        digitalWrite(3, HIGH);
      }
      if(tableau[2] == 'e')
      {
        digitalWrite(3, LOW);
      }
    }
    
    // Envoi sous forme rxb, rxe, ...
  }
}