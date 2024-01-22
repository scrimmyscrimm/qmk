# keebmonkey bongocat 3-key macropad

![Keebmonkey Bongo Cat 3-key Macro Pad](https://www.keebmonkey.com/cdn/shop/files/4S6A7519.jpg?v=1698761594&width=4096)

A 3-key Macro Pad that seems to use a (possibly stolen) PCB build based on Binepad's BN003 but with a different MCU.

I wrote my own firmware for the bongocat after dealing with the lighting being too bright and controls not working in VIA. 
I don't recommend anyone purchase this board, but if you already did and are dealing with the pain that is the RGB's not being controlled, feel free to use this to flash.

the default for the VIA build is a bit specific to my current needs, but make a copy and modify as you need for your board or just change the default keys in VIA 
(note, I do have a bunch of the animations disabled, so if you want those, you'll need to uncomment them out in the config.h file)

if you need help flashing or updating any of the firmware, please refer to QMK help: https://docs.qmk.fm/#/newbs

(this is my first firmware build hooray! but also that means it's probably not the best it could be, but it works)
