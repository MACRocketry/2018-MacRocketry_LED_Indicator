#define redPin 5
#define bluePin 3
#define greenPin 6

int message = 0;

void setup(){
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  
  Serial.begin(9600);
}
void loop() {  
  //message %= 7;
  //message++;
  while(Serial.available() == 0){};
  message = Serial.parseInt();
  if(message > 8 || message < 1){
    Serial.println("Invalid input. Please enter an integer between 1 and 8.");
  }else{
    Serial.print(message);
    Serial.print(": ");
    displayLED(message);
  }
  delay(1000);      
}

void displayLED(int msg){
  switch (msg){
    case 1:
      analogWrite(redPin, 255);
      analogWrite(bluePin, 0);
      analogWrite(greenPin, 0);
      Serial.println("red");
      break;
    case 2: 
      analogWrite(redPin, 0);
      analogWrite(bluePin, 255);
      analogWrite(greenPin, 0);
      Serial.println("blue");
      break;
    case 3:
      analogWrite(redPin, 0);
      analogWrite(bluePin, 0);
      analogWrite(greenPin, 255);
      Serial.println("green");
      break;
    case 4: 
      analogWrite(redPin, 255);
      analogWrite(bluePin, 255);
      analogWrite(greenPin, 0);
      Serial.println("purple");
      break;
    case 5:
      analogWrite(redPin, 255);
      analogWrite(bluePin, 0);
      analogWrite(greenPin, 255);
      Serial.println("yellow");
      break;
    case 6:
      analogWrite(redPin, 0);
      analogWrite(bluePin, 255);
      analogWrite(greenPin, 255);
      Serial.println("cyan");
      break;
    case 7:
      analogWrite(redPin, 255);
      analogWrite(bluePin, 255);
      analogWrite(greenPin, 255);
      Serial.println("white");
      break;
    case 8:
      analogWrite(redPin, 0);
      analogWrite(bluePin, 0);
      analogWrite(greenPin, 0);
      Serial.println("off");
      break;
  }
}
