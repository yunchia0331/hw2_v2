# hw2_v2
* void button() 依按鈕指令顯示在ulcd上
```C++
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
      .
      .
      .
```
int main()
{
*按按鈕
 ```C++
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
  ```

*先產生十個sawtooth波觀察
```C++
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
```
*一邊產生波，一邊存sample的值
```C++
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
 ```
*將sample的質印出
```C++
    for (k = 0; k < 100; k++){
      printf("%f\r\n", ADCdata[k]);
    }
}
```
