#define uS_TO_S_FACTOR 1000000     /* Conversion factor for micro seconds to seconds */
#define TIME_TO_SLEEP  300

void setup() {
  esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR);

  Serial.begin(115200);
  Serial.println();

  initGPS();
  delay(5000);
  initSIM800L();

  Serial.println("End init");
  delay(2000);//wait 2sec
  getPosition();

  Serial.println("Go to sleep");
  esp_deep_sleep_start();
}

void loop() {}
