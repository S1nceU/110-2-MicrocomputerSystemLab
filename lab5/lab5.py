import Jetson.GPIO as GPIO
import time

SPICLK = 11
SPIMISO = 9
SPIMOSI = 10
SPICS = 8
output_pin = 7
LED_out1 = 18
LED_out2 = 17
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
    GPIO.setup(LED_out1,GPIO.OUT)
    GPIO.setup(LED_out2,GPIO.OUT)

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
    try:
        while True:
            adc_value = readadc(photo_ch,SPICLK,SPIMOSI,SPIMISO,SPICS)
            print("Photoresistor's value:{0}".format(adc_value))#光敏電阻數值
            if(adc_value > 800):
                GPIO.output(LED_out1,True)
                GPIO.output(LED_out2,True)
                print("LED1 on LED2 on")
            elif(adc_value > 200):
                GPIO.output(LED_out1,True)
                GPIO.output(LED_out2,False)
                print("LED1 on LED2 off")
            else:
                GPIO.output(LED_out1,False)
                GPIO.output(LED_out2,False)
                print("LED off on LED2 off")
            time.sleep(1)
    finally:
        GPIO.cleanup()

if __name__ == '__main__':
    main()
