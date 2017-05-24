# DAHLIA-BodyIndex
DAHLIA-BodyIndex is a decoder for Body Index files from the DAHLIA dataset.

This decoder converts raw binaries files in black and white tif images.

- To learn more about DAHLIA, read the article
- To download the DAHLIA dataset, visit us on the [mobilemii website](http://www-mobilemii.cea.fr)

Usage
-----

To compile this decoder you need OpenCV (&ge; 2.0.0).

In the project directory, run these command lines :
```
mkdir build && cd build
cmake ..
make
```
To launch the decoder, follow the command line below :
```
./BodyIndex first-frame-number last-frame-numbe input/directory/path/ output/directory/path/
```
Refer in input/directory/path/ the location of raw binaries files, in output/directory/path/ the location where you want to get the tif images. The decoder will transform frame from first-frame-number to last-frame-number.
