
int trig=12;
int echo=13;

void setup() {
  // put your setup code here, to run once:
pinMode(trig, OUTPUT);
pinMode(echo, INPUT);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trig, LOW);
delay(2);
digitalWrite(trig, HIGH);
delay(10);
digitalWrite(trig,LOW);
int duration=pulseIn(echo, HIGH);

int oneway=duration/2;
int distance=oneway*0.032;
// Serial.println(oneway);
Serial.println(distance);
delay(100);


}
