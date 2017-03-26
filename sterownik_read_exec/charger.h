
#define  CHARGER    8    // IN4
#define  CELL_1     7    // IN2 
#define  CELL_2     6    // IN1
#define  CELL_3     5    // IN1

#define  LED        13    

#define  OFF        HIGH // neg
#define  ON         LOW  // neg

void set_up();
void charge();
void cell_1();
void cell_2();
void off();
void off_emergency();
void on();

/*----------------------------------------*/

void set_up()
             {
  digitalWrite(LED, 1);
  pinMode(CHARGER, OUTPUT); 
  pinMode(CELL_1,  OUTPUT);
  pinMode(CELL_2,  OUTPUT);
  pinMode(CELL_3,  OUTPUT);
  pinMode(LED,  OUTPUT);
  off();
             }
            
void charge(){
  digitalWrite(CHARGER, !ON);
  digitalWrite(CELL_1,  OFF);
  digitalWrite(CELL_2,  OFF);
  
  for(int i=0; i<20; i++){
  delay(50);
  digitalWrite(LED, 0);
  delay(50);
  digitalWrite(LED, 1);
  }
}

void cell_1(){
  digitalWrite(CHARGER, !OFF);digitalWrite(LED, 0);
  digitalWrite(CELL_1,  ON);
  digitalWrite(CELL_2,  OFF);
  digitalWrite(LED, 0);
  
}

void cell_2(){
  digitalWrite(CHARGER, !OFF);
  digitalWrite(CELL_1,  OFF);
  digitalWrite(CELL_2,  ON);
  digitalWrite(LED, 0);
}

void off(){
  digitalWrite(CHARGER, !OFF);
  digitalWrite(CELL_1,  OFF);
  digitalWrite(CELL_2,  OFF);
  digitalWrite(CELL_3,  OFF);
  digitalWrite(LED, 0);
}
void off_emergency(){
  while(1)
  {
  digitalWrite(CHARGER, !OFF);
  digitalWrite(CELL_2,  OFF);
  digitalWrite(CELL_1,  OFF);
  digitalWrite(CELL_3,  OFF);
  delay(100);
  digitalWrite(LED, 1);
  delay(100);
  digitalWrite(LED, 0);
  }
}
void on(){ /* BE CAREFULL */ 
  digitalWrite(CHARGER, !ON);
  digitalWrite(CELL_1,  ON);
  digitalWrite(CELL_2,  ON);
  digitalWrite(CELL_3,  ON);
  digitalWrite(LED, 1);
}

