#include <ezTime.h>
#include <ESP8266WiFi.h>

Timezone Austria; // A name of Your time zone and inisiating it

void setup() {
    Serial.begin(115200);
    WiFi.begin("Your SSID", "Your Password"); // Your Credentials
    Austria.setPosix("CET-1CEST,M3.5.0,M10.5.0/3"); // Posix for Your time zone
    Austria.setDefault(); // Set Your time zone as default
    setServer("ntp.se"); // Set Your NTP serverpool
    // Uncomment the line below to see what it does behind the scenes
    setDebug(INFO);
    waitForSync();
    Serial.println();
    Serial.println("DateTime :"+ dateTime());
    Serial.println("UTC:      "+ UTC.dateTime());
    Serial.println(dateTime("l"));
    Serial.println(dateTime("F"));
}

void loop() {
	events();
}
