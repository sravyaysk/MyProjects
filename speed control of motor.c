void main()
{
short duty1 = 16; //initial value for duty
TRISD = 0xFF; //PORTD as input
TRISC = 0x00; //PORTC as output
TRISB = 0x00; //PORTB as output
PORTB = 0x02; //Run motor in anticlock wise
PWM1_Init(1000); //Initialize PWM1
PWM1_Start(); //start PWM1
PWM1_Set_Duty(duty1); //Set current duty for PWM1

while (1) // endless loop
{

if (PORTD.F0==0) //Checking the button pressed or not
{
Delay_ms(1);
duty1++; // increment duty cycle
PWM1_Set_Duty(duty1); //Change the duty cycle
}

if (PORTD.F1==0) // Checking the button pressed or not
{
Delay_ms(1);
duty1–; // decrement duty cycle
PWM1_Set_Duty(duty1);
}
Delay_ms(10);
} } 