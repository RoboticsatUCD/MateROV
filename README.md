Stitchmaton, the Mechanical Turk of Image Stitching
===================================================
Proof-of-concept for our "stupid" image stitcher. The script crop.sh takes a
series of *n* photographs and excises successive *n*ths. These strips are then
"stitched" together with join.sh, producing stitched.jpg.

crop.sh
-------
Usage:
	crop.sh IMGS
In the examples, it was run as:
	crop.sh imgin/*
Producing the excised strips in the imgout directory.

join.sh
-------
Usage:
	join.sh IMGS
In the examples, it was rus as:
	join.sh imgout/*
Producing the file stitched.jpg in the working directory.


Testing/Examples
----------------
### imgin
Five example images for testing purposes. These photographs were taken manually
with a smartphone with no mechanical support.

### imgout
The excised strips from imgin/\* as produced by crop.sh.

### stitched.jpg
A satisfactory result given the stupidity of the method.

### stitched-adj.jpg
A manually adjusted version of stitched.jpg. This shows the potential for
creating a simple GUI to slide the strips vertically for human-aided drift
adjustments.
