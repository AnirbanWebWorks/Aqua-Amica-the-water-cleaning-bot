#include "esp_camera.h"

#define FRAME_W 320
#define FRAME_H 240

void setup()
{
  Serial.begin(9600);

  camera_config_t config;

  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;

  config.pin_d0 = 5;
  config.pin_d1 = 18;
  config.pin_d2 = 19;
  config.pin_d3 = 21;
  config.pin_d4 = 36;
  config.pin_d5 = 39;
  config.pin_d6 = 34;
  config.pin_d7 = 35;

  config.pin_xclk = 0;
  config.pin_pclk = 22;
  config.pin_vsync = 25;
  config.pin_href = 23;

  config.pin_sscb_sda = 26;
  config.pin_sscb_scl = 27;

  config.pin_pwdn = 32;
  config.pin_reset = -1;

  config.xclk_freq_hz = 20000000;
  config.pixel_format = PIXFORMAT_GRAYSCALE;

  config.frame_size = FRAMESIZE_QVGA;
  config.jpeg_quality = 12;
  config.fb_count = 1;

  esp_camera_init(&config);
}

void loop()
{
  camera_fb_t *fb = esp_camera_fb_get();

  if(!fb)
  {
    return;
  }

  long left=0;
  long center=0;
  long right=0;

  for(int y=0;y<240;y+=4)
  {
    for(int x=0;x<320;x+=4)
    {
      int pixel=fb->buf[y*320+x];

      if(pixel<60)
      {
        if(x<106)
          left++;

        else if(x<212)
          center++;

        else
          right++;
      }
    }
  }

  if(center>300)
  {
    Serial.println("F");
  }
  else if(left>right)
  {
    Serial.println("L");
  }
  else if(right>left)
  {
    Serial.println("R");
  }

  if(center>1000)
  {
    Serial.println("C");
  }

  esp_camera_fb_return(fb);

  delay(100);
}