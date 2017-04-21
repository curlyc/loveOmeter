
const int sensorPin = A0;
const int ledpin = 11;
// room temperature in Celcius
float baselineTemp = 0.00;// took out constant

void setup() {
  // open a serial connection to display values
  Serial.begin(9600);
  // set the LED pins as outputs
  // the for() loop saves some extra coding
  for (int pinNumber = 2; pinNumber < 11; pinNumber++) {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop() {
  // read the value on AnalogIn pin 0
  // and store it in a variable
  int sensorVal = analogRead(sensorPin);

  // send the 10-bit sensor value out the serial port
  Serial.print("sensor Value: ");
  Serial.print(sensorVal);

  // convert the ADC reading to voltage
  float voltage = (sensorVal / 1024.0) * 5.0;

  // Send the voltage level out the Serial port
  Serial.print(", Volts: ");
  Serial.print(voltage);

  // convert the voltage to temperature in degrees C
  // the sensor changes 10 mV per degree
  // the datasheet says there's a 500 mV offset
  // ((volatge - 500mV) times 100)
  Serial.print(", degrees C: ");
  float temperature = (voltage - .5) * 100;
  if (baselineTemp == 0) { //takes the temperature at startup
    baselineTemp = temperature; //defines baseline temp at that temperature
  }
  Serial.println(temperature);

  // if the current temperature is lower than the baseline
  // turn off all LEDs
  //if (temperature < baselineTemp + 1) {
    //digitalWrite(2, LOW);
    //digitalWrite(3, LOW);
    //digitalWrite(4, LOW);
    //digitalWrite(5, LOW);
    //digitalWrite(6, LOW);
    //digitalWrite(7, LOW);
    //digitalWrite(8, LOW);
    //digitalWrite(9, LOW);
  //  digitalWrite(10, LOW);
 // } // if the temperature lowers 10-12 degrees, turn 1LED on
   if (temperature >= baselineTemp - 10 && temperature < baselineTemp - 12) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
  } // if the temperature lowers 6-8 degrees, turn 3rd LED on
  else if (temperature >= baselineTemp - 6 && temperature <= baselineTemp - 8) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    } // if the temperature rises more than 3-4 degrees, turn 3 LEDs on
    // if temperature is 3 -5 degrees below baseline
      else if (temperature >= baselineTemp - 3 && temperature <= baselineTemp - 5) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);

  } //
   //if temperature is within 1-2 degrees of baseline temp
        else if (temperature >= baselineTemp + 2 && temperature < baselineTemp + 3 or temperature <= baselineTemp - 2 && temperature > baselineTemp - 3) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);

  } // if the temperature rises more than 5-6 degrees, turn 5 LEDs
        else if (temperature >= baselineTemp + 3 && temperature < baselineTemp + 5) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);

  } // if the temperature rises  6-7 degrees, turn 6 LEDs
        else if (temperature >= baselineTemp + 6 && temperature < baselineTemp + 8) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);

  } // if the temperature rises  7-8 degrees, turn 7 LEDs
        else if (temperature >= baselineTemp + 9 && temperature < baselineTemp + 11) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);

  } // if the temperature rises 8-9 degrees, turn 8 LEDs
  else if (temperature >= baselineTemp + 12 && temperature < baselineTemp + 14) {      
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);

  } // if the temperature rises more than 6 degrees, turn all LEDs
  else if (temperature >= baselineTemp + 15) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
  }
  delay(1);
}
