const int sensorPin = A0;
const float baselineTemp = 20;

void setup() {
  Serial.begin(9600); // open a serial port

  for(int pinNumber = 2; pinNumber < 5; pinNumber++) {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop() {
  int sensorVal = analogRead(sensorPin);
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);

  float voltage = (sensorVal/1024.0)*5.0;
  Serial.print(", Volts: ");
  Serial.print(voltage);

  float temperature = (voltage - 0.5)*100;
  Serial.print(", degrees °C: ");
  Serial.println(temperature);

  int led2 = temperature >= baselineTemp + 2 ? HIGH : LOW;
  int led3 = temperature >= baselineTemp + 4 ? HIGH : LOW;
  int led4 = temperature >= baselineTemp + 6 ? HIGH : LOW;
  digitalWrite(2, led2);
  digitalWrite(3, led3);
  digitalWrite(4, led4);

  delay(1);
}
