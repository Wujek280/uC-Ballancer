#include "soc.h"
#include "charger.h"

void reading();
void serialPrint();
void measure();

float A,B,C = 0;
float diff;
float U1,U2; 
unsigned long int a,b,c=0; 

float Ubal  = 4.20;   // 4.20 for LiPol
float Uem   = 4.35;  // 4.30
float Uthre = 0.02; // 0.01 default

float maxVoltage = 5.00;
float Ratio=2.00;
int d = 128; 
int precision = 2; //decimal precision 

float C1[2]={0,0};
float C2[2]={0,0};
float threshold = 0.010;
int t = 2000;   //ballancing time

/**********************************************************************/

void setup()
{
 Serial.begin(115200);
 
 set_up();
 reading();

Serial.print("Umax");
Serial.print("  \t ");Serial.print( "C1" );Serial.print("  \t ");Serial.print( "C2" );Serial.print("  \t ");Serial.println( "Diff" );
Serial.println("+-----------------------------+");
 
   if(U1<Ubal && U2<Ubal) charge();
   if(U1>Ubal || U2>Ubal) off_emergency();
}

void loop()
{
 charge();
 reading(); 
 measure();
 
 if(U1>Uem || U2>Uem) off_emergency();
 
 if(U1 > Ubal || U1 - U2 > Uthre){ cell_1(); delay(t); charge(); } 
 if(U2 > Ubal || U2 - U1 > Uthre){ cell_2(); delay(t); charge(); }
  
}

/**********************************************************************/

void reading()
{
  
for(int i=0; i<d; i++){a+=analogRead(A1);} A=a/d/1023.00*maxVoltage;
for(int i=0; i<d; i++){b+=analogRead(A2);} B=b/d/1023.00*maxVoltage;
for(int i=0; i<(d/2); i++){c+=analogRead(A3);} C=c/d/1023.00*maxVoltage; 

C1[1] = A*Ratio-B;
C2[1] = B-C;
if(abs(C1[1]-C1[0])>threshold){  C1[0] = C1[1];  }
if(abs(C2[1]-C2[0])>threshold){  C2[0] = C2[1];  }

diff= abs(C2[0]-C1[0]);

U1=C1[0];
U2=C2[0];
a=b=c=0;
}

void serialPrint()
{
Serial.print("Umax: ");
Serial.print(  A*Ratio,  3  ); Serial.print("  \t "); 
Serial.print(" SOC = ");Serial.print(soc(A));Serial.print(" %");Serial.print("  \t ");

Serial.print(  "  Cell 1:  "  );
Serial.print(  C1[0], precision     ); Serial.print("   ");Serial.print( abs((C1[0]-C1[1])*1000),0  ); Serial.print("    \t ");
Serial.print(  "  Cell 2:  "  );
Serial.print(  C2[0], precision     ); Serial.print("   ");Serial.print( abs((C1[0]-C1[1])*1000),0  ); Serial.print("    \t ");

Serial.print(  "diff: "  );
Serial.print(  diff, 2   ); 

if((C2[1]-C1[1])>0)
    {
      if((C2[1]-C1[1]) > Uthre) {Serial.print( "   Ballance: Cell_2" );}else{Serial.print( "   Ballance: no ballance"   );}
    }
    else
    {
      if((C1[1]-C2[1]) > Uthre) {Serial.print( "   Ballance: Cell_1" );}else{Serial.print( "   Ballance: no ballance"   );}
    }
Serial.println();
}

void measure()
{
Serial.print(A*Ratio,  3);
Serial.print("  \t ");Serial.print(  C1[0], precision     );
Serial.print("  \t ");Serial.print(  C2[0], precision     );
Serial.print("  \t ");Serial.print(  diff, 2  ); 
Serial.println();
}
