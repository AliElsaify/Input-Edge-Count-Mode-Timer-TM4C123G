#include <IntCtrl.h>
#include <Mcu_Hw.h>

unsigned int counter                                                        ;

int main ( void )
{
	 Timer3ACaptureCount_init()                                                    ; 
  while(1)
	{
      GPTMCTL_Timer_3_R                          |= 1                       ;   /* enable timer3A */
      timer1A_delaySec(1)                                                   ;   /* use timer to delay 1 second*/
      counter                                     = Timer3A_countCapture()  ;   /* get the no. of counts in this second*/ 
      GPTMCTL_Timer_3_R                          &= ~1                      ;   /* disable TIMER3A during setup */
      GPTMTAV_TimerA_3_R                          = 0                       ;   /* reset the value fo counts*/
      GPTMTAR_TimerA_3_R                          = 0                       ;   /* reset the value fo counts*/
      /*sprintf(mesg, "\r\nRPM = %d RPM", counter*60);  convert float to string */
     /* printstring(mesg);  print frequency on serial monitor*/
	}
	
	return 0                                                                  ;
	
}
