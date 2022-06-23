import Jetson.GPIO as GPIO
import time

SPICLK = 11
SPIMISO = 9
SPIMOSI = 10
SPICS = 8
output_pin = 7
LED1 = 18
LED2 = 17
photo_ch = 0

def init():
    GPIO.setmode(GPIO.BCM)
    #GPIO.setup(output_pin,GPIO.OUT,initial = GPIO.HIGH)
    #GPIO.setwarning(False)
    #GPIO.cleanup()
    #GPIO.setmode(GPIO.BCM)

    GPIO.setup(SPIMOSI,GPIO.OUT)
    GPIO.setup(SPIMISO,GPIO.IN)
    GPIO.setup(SPICLK,GPIO.OUT)
    GPIO.setup(SPICS,GPIO.OUT)
    GPIO.setup(LED1,GPIO.OUT)
    GPIO.setup(LED2,GPIO.OUT)

def readadc(adcnum,clockpin,mosipin,misopin,cspin):
    if((adcnum>7) or (adcnum<0)):
        return -1
    GPIO.output(cspin,True)
    GPIO.output(clockpin,False)
    GPIO.output(cspin,False)

    commandout = adcnum
    commandout |= 0x18
    commandout <<= 3
    for i in range(5):
        if(commandout & 0x80):
            GPIO.output(mosipin,True)
        else:
            GPIO.output(mosipin,False)

        commandout <<= 1
        GPIO.output(clockpin,True)
        GPIO.output(clockpin,False)

    adcout = 0
    for i in range(12):
        GPIO.output(clockpin,True)
        GPIO.output(clockpin,False)
        adcout <<= 1
        if(GPIO.input(misopin)):
            adcout |= 0x1
    
    GPIO.output(cspin,True)

    adcout >>= 1

    return adcout


def main():
    init()
    LEDlist=[LED1,LED2]
    adc_value = readadc(0, SPICLK, SPIMOSI, SPIMISO, SPICS)
    # print("adc_value : %d \n\t" %(adc_value),end ='')
    if(adc_value < 200):
        GPIO.output(LEDlist[0],False)
        GPIO.output(LEDlist[1],False)
        # print(" LED1 : ON\tLED2 : OFF\n")
    elif(adc_value > 900):
        GPIO.output(LEDlist[0],True)
        GPIO.output(LEDlist[1],True)
        # print(" LED1 : OFF\tLED2 : ON\n")
    else:
        GPIO.output(LEDlist[0],True)
        GPIO.output(LEDlist[1],False)
        # print("LED1 : OFF \tLED2 : OFF\n")
    print(adc_value)
main()

