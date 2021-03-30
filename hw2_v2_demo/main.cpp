// uLCD-144-G2 basic text demo program for uLCD-4GL LCD driver library
//
#include "mbed.h"
#include "uLCD_4DGL.h"

DigitalIn bup(D6);
DigitalIn bdn(D8);
DigitalIn bst(D5);
uLCD_4DGL uLCD(D1, D0, D2); // serial tx, serial rx, reset pin;

AnalogOut aout(PA_4);
AnalogIn Ain(A0);
Thread thread;
int sample = 100;
float ADCdata[100];
int f = 1;
int h = 0;

void button()
{
  switch(count%6)
    {
      case 1:
        uLCD.locate(0,0);
        uLCD.color(RED);
        uLCD.printf("\nf=0.6 Hz\n");
        uLCD.color(GREEN);
        uLCD.printf("\nf=0.7 Hz\n");
        uLCD.printf("\nf=0.8 Hz\n");
        uLCD.printf("\nf=0.9 Hz\n");
        uLCD.printf("\nf=1.0 Hz\n");
        uLCD.printf("\nf=2.0 Hz\n");
        x = 0.6;
        break;
      case 2:
        uLCD.locate(0,0);
        uLCD.color(GREEN);
        uLCD.printf("\nf=0.6 Hz\n");
        uLCD.color(RED);
        uLCD.printf("\nf=0.7 Hz\n");
        uLCD.color(GREEN);
        uLCD.printf("\nf=0.8 Hz\n");
        uLCD.printf("\nf=0.9 Hz\n");
        uLCD.printf("\nf=1.0 Hz\n");
        uLCD.printf("\nf=2.0 Hz\n");
        x = 0.7;
        break;
      case 3:
        uLCD.locate(0,0);
        uLCD.color(GREEN);
        uLCD.printf("\nf=0.6 Hz\n");
        uLCD.printf("\nf=0.7 Hz\n");
        uLCD.color(RED);
        uLCD.printf("\nf=0.8 Hz\n");
        uLCD.color(GREEN);
        uLCD.printf("\nf=0.9 Hz\n");
        uLCD.printf("\nf=1.0 Hz\n");
        uLCD.printf("\nf=2.0 Hz\n");
        x = 0.8;
        break;
      case 4:
        uLCD.locate(0,0);
        uLCD.color(GREEN);
        uLCD.printf("\nf=0.6 Hz\n");
        uLCD.printf("\nf=0.7 Hz\n");
        uLCD.printf("\nf=0.8 Hz\n");
        uLCD.color(RED);
        uLCD.printf("\nf=0.9 Hz\n");
        uLCD.color(GREEN);
        uLCD.printf("\nf=1.0 Hz\n");
        uLCD.printf("\nf=2.0 Hz\n");
        x = 0.9;
        break;
      case 5:
        uLCD.locate(0,0);
        uLCD.color(GREEN);
        uLCD.printf("\nf=0.6 Hz\n");
        uLCD.printf("\nf=0.7 Hz\n");
        uLCD.printf("\nf=0.8 Hz\n");
        uLCD.printf("\nf=0.9 Hz\n");
        uLCD.color(RED);
        uLCD.printf("\nf=1.0 Hz\n");
        uLCD.color(GREEN);
        uLCD.printf("\nf=2.0 Hz\n");
        x = 1.0;
        break;
      case 0:
        x = 2.0;
        uLCD.locate(0,0);
        uLCD.color(GREEN);
        uLCD.printf("\nf=0.6 Hz\n");
        uLCD.printf("\nf=0.7 Hz\n");
        uLCD.printf("\nf=0.8 Hz\n");
        uLCD.printf("\nf=0.9 Hz\n");
        uLCD.printf("\nf=1.0 Hz\n");
        uLCD.color(RED);
        uLCD.printf("\nf=2.0 Hz\n");
        break;
    }
}
int main()
{
  int count=1;
  int x;
  while(1){
    if(bup == 1){  
      count++;
      button();
    }else if(bdn == 1){       
      count--;
      button();
    }
    if(bst == 1){
      f= x;
      printf("%d\r\n",f);
      break;
    }
  }

	float T=1/f;
	int k = 0;
//      thread.start(analy);

	for (h = 0; h < 10; h++) {
		for (float i = 0.0f; i < 0.91f; i += 0.031f) {
		aout = i;
		//printf("aout = %f volts\n", aout.read() * 3.3f);
		wait_us(T/100*1000000);
		}
		for (float i = 0.0f; i < 0.91f; i += 0.031f) {
		aout = i;
		//printf("aout = %f volts\n", aout.read() * 3.3f);
		wait_us(T/100*1000000);
		}
	}

	for (h = 0; h < 1; h++) {
		for (float i = 0.0f; i < 0.91f; i += 0.031f) {
		aout = i;
		ADCdata[k++] = Ain;
		//printf("aout = %f volts\n", aout.read() * 3.3f);
		wait_us(T/100*1000000);
		}
		for (float i = 0.0f; i < 0.91f; i += 0.031f) {
		aout = i;
		ADCdata[k++] = Ain;
		//printf("aout = %f volts\n", aout.read() * 3.3f);
		wait_us(T/100*1000000);
		}
	}

    for (k = 0; k < 100; k++){
      printf("%f\r\n", ADCdata[k]);
    }
}
