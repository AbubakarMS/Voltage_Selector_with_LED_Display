int Reader = A0;
int Read;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Reader, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

 Read = analogRead(Reader);
// int Vt = (Read / 10)
 Serial.println(Read);
 delay(300);
}
