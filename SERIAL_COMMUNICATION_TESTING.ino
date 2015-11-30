int val[4]; //THIS HOLDS WHAT TO DISPLAY
int currMillis = 0;
 int prevMillis = 0;
 int num = 0;
 int counter = 0;
void setup() {
  
  //CONFIGURING ALL OF THE PINS
  PORTD_PCR0 = (1 << 8);
  PORTD_PCR1 = (1 << 8);
  PORTD_PCR2 = (1 << 8);
  PORTD_PCR3 = (1 << 8);
  PORTD_PCR4 = (1 << 8);
  PORTD_PCR5 = (1 << 8);
  PORTD_PCR6 = (1 << 8);
  PORTD_PCR7 = (1 << 8);

  GPIOD_PDDR = B11111111;

  //STARTING SERIAL COMMUNICATION
  Serial.begin(9600);

  //MAKE SURE THAT THE ARDUINO IS CONNECTED
  establishContact();
}

void loop() {

  //UPDATING THE VALUE TO DISPLAY IF SOMETHING IS SENT
  if(Serial.available() > 0)
  {
    int counter;
    while(counter < 4)
    {
      //IF IT RECIEVES SOMETHING IT WILL SAVE IT TO THE ARRAY AND INCREMENT THE COUNTER TO MOVE TO THE NEX SPOT IN THE ARRAY
      if(Serial.available() > 0)
      {
        val[counter] = Serial.read();
        counter++;
      }
    }
  }


  //CHANGES WHICH ELEMENT IN THE ARRAY IS DISPLAYING EVERY SECOND
  currMillis = millis();
if(currMillis - prevMillis > 1000)
{
  num++;
  prevMillis = millis();
}

if(num == 4) num = 0;

//SETTING THE PINS TO THE VALUE
  GPIOD_PCOR = B11111111;
    GPIOD_PSOR = val[num];

   
  
}

void establishContact()//THIS FUNCTION LOOPS UNTIL PROCESSING SENDS A VALUE BACK TO CONFIRM A SERIAL CONNECTION HAS HAPPENED
{
  while(Serial.available() <= 0)
  {
    Serial.println("Y");
    delay(200);
  }
}

