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



bool statusForward_f_r = 0;
bool statusBack_f_r = 0;
bool statusForward_b_r = 0;
bool statusBack_b_r = 0;
bool statusForward_f_l = 0;
bool statusBack_f_l = 0;
bool statusForward_b_l = 0;
bool statusBack_b_l = 0;

void loop() {
  if (Serial.available() > 0) {
  String str = Serial.readString();

  int v=100;
  int theta = str.toInt();
  double vx = v*sin(theta*DEG_TO_RAD);
  double vy = v*cos(theta*DEG_TO_RAD);
 double leftFront = vx-vy;
  double rightFront = vx+vy;
  double leftBack = vx+vy;
  double rightBack =vx-vy;



  int speed = 255;
  analogWrite(pin_speed_f_r,rightFront);
  digitalWrite(pin_directionForward_f_r, rightFront>=0);
  digitalWrite(pin_directionBack_f_r,rightFront<0);

  analogWrite(pin_speed_f_l,leftFront);
  digitalWrite(pin_directionForward_f_l, leftFront>=0);
  digitalWrite(pin_directionBack_f_l, leftFront<0);

  analogWrite(pin_speed_b_r,rightBack);
  digitalWrite(pin_directionForward_b_r, rightBack>=0);
  digitalWrite(pin_directionBack_b_r, rightBack<0);

  analogWrite(pin_speed_b_l,leftBack);
  digitalWrite(pin_directionForward_b_l, leftBack>=0);
  digitalWrite(pin_directionBack_b_l, leftBack<0);
  Serial.println(str);
  }
}
