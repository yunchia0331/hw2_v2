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
* 按按鈕
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

* 先產生十個sawtooth波觀察
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
* 一邊產生波，一邊存sample的值
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
* 將sample的質印出
```C++
    for (k = 0; k < 100; k++){
      printf("%f\r\n", ADCdata[k]);
    }
}
```
# hw2.py FFT

* 和板子連結 <br>
>serdev = '/dev/ttyACM0' <br>
>s = serial.Serial(serdev)<br>

* 讀select的頻率
> freq=int(s.readline()) # Read an echo string from B_L4S5I_IOT01A terminated with '\n'

Fs = 100.0*freq;  # sampling rate
Ts = 1.0/Fs; # sampling interval

* 橫軸t需在0到一週期之間
>t = np.arange(0,1/freq,Ts) # time vector; create Fs samples between 0 and 1.0 sec.
>y = np.arange(0,1/freq,Ts) # signal vector; create Fs samples

 
n = len(y) # length of the signal<br>
k = np.arange(n)<br>
T = n/Fs<br>
frq = k/T # a vector of frequencies; two sides frequency range<br>
frq = frq[range(int(n/2))] # one side frequency range<br>


for x in range(0, int(100)):

>    line=s.readline() # Read an echo string from B_L4S5I_IOT01A terminated with '\n'
* print line
>    y[x] = float(line)

>Y = np.fft.fft(y)/n*2 # fft computing and normalization
>Y = Y[range(int(n/2))] # remove the conjugate frequency parts

* print圖
>fig, ax = plt.subplots(2, 1)
>ax[0].plot(t,y)
>ax[0].set_xlabel('Time')
>ax[0].set_ylabel('Amplitude')
>ax[1].plot(frq,abs(Y),'r') # plotting the spectrum
>ax[1].set_xlabel('Freq (Hz)')
>ax[1].set_ylabel('|Y(freq)|')
>plt.show()
>s.close()
