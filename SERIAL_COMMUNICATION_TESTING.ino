int val; //THIS HOLDS WHAT TO DISPLAY
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
    val = Serial.read(); 
  }

  //SETTING THE PINS TO THE VALUE
  GPIOD_PDOR = val;

}

void establishContact()//THIS FUNCTION LOOPS UNTIL PROCESSING SENDS A VALUE BACK TO CONFIRM A SERIAL CONNECTION HAS HAPPENED
{
  while(Serial.available() <= 0)
  {
    Serial.println("Y");
    delay(200);
  }
}

