
void tog_green(void);
void set_green(uint8_t);
void tog_red(void);
void set_red(uint8_t);

uint8_t greenOn = 0;
uint8_t redOn = 0;

#define ocrc OCR1C
#define ocrb OCR1B
#define ocra OCR1A

const uint8_t backlight_pins[] = {B7, B6, B5};
const uint16_t com1x1[] = {COM1C1, COM1B1, COM1A1};
uint8_t reverseLevels[BACKLIGHT_LEVELS];



  void tog_green(void){
    if(greenOn){
      greenOn = 0;
      set_green(0);
    }else{
      greenOn = 1;
      set_green(BACKLIGHT_LEVELS);
    }
  }

void tog_red(void){
    if(redOn){
    redOn = 0;
    set_red(0);
  }else{
    redOn = 1; 
    set_red(BACKLIGHT_LEVELS);
  }
}

  void set_red(uint8_t level){
    uint8_t pin = B6;
      _SFR_IO8((pin>> 4) + 2) &= ~_BV(pin & 0xF);

      if ( level == 0 ) {
      // Turn off PWM control on backlight pin, revert to output low.
      TCCR1A &= ~(_BV(pin));
      ocrb =  0x0;
    } else if ( level == BACKLIGHT_LEVELS ) {
      // Turn on PWM control of backlight pin
      TCCR1A |= _BV(pin);
      // Set the brightness
       ocrb= 0xFFFF;
    } else {
      // Turn on PWM control of backlight pin
      TCCR1A |= _BV(pin);
      // Set the brightness
      ocrb = 0xFFFF >> ((BACKLIGHT_LEVELS - level) * ((BACKLIGHT_LEVELS + 1) / 2));
    }
}

void set_green(uint8_t level){
  uint8_t pin = B5;
  _SFR_IO8((pin>> 4) + 2) &= ~_BV(pin & 0xF);

  if ( level == 0 ) {
  // Turn off PWM control on backlight pin, revert to output low.
  TCCR1A &= ~(_BV(pin));
  ocra =  0x0;
} else if ( level == BACKLIGHT_LEVELS ) {
  // Turn on PWM control of backlight pin
  TCCR1A |= _BV(pin);
  // Set the brightness
  ocra= 0xFFFF;
} else {
  // Turn on PWM control of backlight pin
  TCCR1A |= _BV(pin);
  // Set the brightness
  ocra = 0xFFFF >> ((BACKLIGHT_LEVELS - level) * ((BACKLIGHT_LEVELS + 1) / 2));
}
}


  __attribute__ ((weak))
void backlight_init_ports(void){
  ICR1 = 0xFFFF;
  // setup pins as output and HIGH, these are revesed. Pins are ground
  for(int x = 0; x < 3; x++){
  _SFR_IO8((backlight_pins[x] >> 4) + 1) |= _BV(backlight_pins[x] & 0xF);
  _SFR_IO8((backlight_pins[x] >> 4) + 2) &= ~_BV(backlight_pins[x] & 0xF);
  }

  TCCR1A = _BV(com1x1[0]) | _BV(com1x1[1]) | _BV(com1x1[2]) | _BV(WGM11);

  TCCR1B = _BV(WGM13) | _BV(WGM12) | _BV(CS10); // = 0b00011001;
  backlight_set(0); 
}

  __attribute__ ((weak))
void backlight_set(uint8_t level){
  level = reverseLevels[level];
  for(int x = 0; x < 3; x++){
    _SFR_IO8((backlight_pins[x] >> 4) + 2) &= ~_BV(backlight_pins[x] & 0xF);

    if ( level == 0 ) {
        // Turn off PWM control on backlight pin, revert to output low.
        TCCR1A &= ~(_BV(com1x1[x]));
        ocrc = ocrb = ocra = 0x0;
    } else if ( level == BACKLIGHT_LEVELS ) {
        // Turn on PWM control of backlight pin
        TCCR1A |= _BV(com1x1[x]);
        // Set the brightness
        ocrc = ocrb = ocra = 0xFFFF;
    } else {
        // Turn on PWM control of backlight pin
        TCCR1A |= _BV(com1x1[x]);
        // Set the brightness
        ocrc = ocrb = ocra = 0xFFFF >> ((BACKLIGHT_LEVELS - level) * ((BACKLIGHT_LEVELS + 1) / 2));
    }
  }
}
