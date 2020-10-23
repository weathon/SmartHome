void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
//  pinMode(A0,INPUT);  bu ran yi zhi 1023 hai shi bu xing
// yuan lai bu ke yi zhi jie lian jie an     yao chuan lian dian zu qq da duan 
// fen ya dian lu  hysm
// aaaaaa zen me fen fa
// hysm qq kan dao?
// zao ying hen da:wq
// ele 
mei you mian bao ban 
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(analogRead(A0));
}
