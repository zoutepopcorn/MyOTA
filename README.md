# MyOTA
A lib for esp8266 to update your firmware OTA.

Make sure you installed the librarie(s):
- Arduino for esp (https://github.com/esp8266/Arduino)
- WiFiManager

# How to use?
Open the example. Make sure your esp connects with your gateway, by connecting to the setup network.
`wifiManager.autoConnect("setup", "00000000");`

##Build your new OTA firmware in Arduino: 
`Sketch > Export compiled Binary. `
`Sketch > Show sketch folder. Here is your bin file.`

## Host your local bin file, using: 
- https://www.npmjs.com/package/http-server
- just upload it to any server.

## Open your mobile phone and setup a hotspot with the name:
"**up**adress/firm"  .
Now your esp8266 will check in his setup loop, for the url: "http://**adress/firm**.bin". So dont include http:// OR .bin in your hotspot name.

Note: the esp will download the firmware from the connected hotspot. So by default not from the "upadress/firm" hotspot.


