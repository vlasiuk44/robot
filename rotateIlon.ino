#define pin_speed_f_r 10
#define pin_speed_f_l 11
#define pin_speed_b_r 5
#define pin_speed_b_l 6
#define pin_directionForward_f_r 13
#define pin_directionBack_f_r 12
#define pin_directionForward_f_l 8
#define pin_directionBack_f_l 9
#define pin_directionForward_b_r 2
#define pin_directionBack_b_r 3
#define pin_directionForward_b_l 7
#define pin_directionBack_b_l 4


void setup() {
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  Serial.begin(9600);

}


void loop() {
  if (Serial.available() > 0) {
  String str = Serial.readString();

  int V= 255;

  Serial.println(V);
  double r = str.toInt();
  r = (r+150)/r;
  Serial.println(V);
  double f =V/(r);//40 r=1000
  Serial.println(f);
  analogWrite(pin_speed_f_r,f);
  digitalWrite(pin_directionForward_f_r, 0);
  digitalWrite(pin_directionBack_f_r,1);

  analogWrite(pin_speed_f_l,f);
  digitalWrite(pin_directionForward_f_l, 1);
  digitalWrite(pin_directionBack_f_l, 0);

  analogWrite(pin_speed_b_r,V);
  digitalWrite(pin_directionForward_b_r, 1);
  digitalWrite(pin_directionBack_b_r, 0);

  analogWrite(pin_speed_b_l,V);
  digitalWrite(pin_directionForward_b_l, 0);
  digitalWrite(pin_directionBack_b_l, 1);

  }

  }
