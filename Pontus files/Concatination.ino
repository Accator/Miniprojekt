String a = "Good";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  a.concat(" ");
  a.concat("bye");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(a);
  delay(1500);
}
