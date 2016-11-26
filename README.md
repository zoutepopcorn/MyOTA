# MyOTA
A lib for esp8266 to update your firmware OTA.

Make sure you installed the librarie(s):
- WiFiManager
- Arduino for esp (https://github.com/esp8266/Arduino)

# How to use?
Open the example. Make sure your esp connects with your gateway, by connecting to the setup network.
`wifiManager.autoConnect("setup", "00000000");`

Build your new OTA firmware in Arduino: 
Sketch > Export compiled Binary. 
Sketch > Show sketch folder. Here is your bin file.

Open your mobile phone and setup a hotspot with the name:
"upadress/firm"
Now your esp8266 will check in his setup loop, for the url: "http://adress/firm.bin"

You can host your local files by example by using: 
https://www.npmjs.com/package/http-server

Cu.
