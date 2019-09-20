# Shining_Force_II_Blacksmith
Simple utility to edit a Shining Force II savestate so I don't have to visit the blacksmith and reset a bunch.

This program was written with the Terraonion MegaSD save state format in mind. It should be pretty simple to modify for other file formats. It just needs
an offset to be adjusted.

CMake is required to build. Please use your package manager of choice to install it prior to building this if you have not already done so. Or you can simply
run the following from the `src` folder.
```
gcc -o blacksmith blacksmith.c readItemList.c readSaveState.c displayCharacterItems.c getIntFromUser.c freeBuffers.c transformItem.c 
```

This guide was used as a reference.
https://gamefaqs.gamespot.com/genesis/563341-shining-force-ii/faqs/11359

# Building and running
To build run the following commands.
```
 rm -rf build
 cmake -H. -Bbuild
 cmake --build build -- -j2
```

The application expects the save file to be called `shining.sta`. Copy the save file from the SD card into the working directory and run the command `blacksmith`.
It will print out a list of items with their numeric representation. Then it will iterate through each character allowing you to select an item slot and convert it
to your item of choice.
