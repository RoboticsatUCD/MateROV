Countmatron, Automatic Object Counting
======================================

thresholding.py
---------------
Basic proof-of-concept using Otsu thresholding.
Requires grayscale input as input.
The image is first blurred to remove high frequency data.

Usage:

	python3 thresholding.py

Testing Images
----------------
### mussels.png
Image extracted from competition document, full color.

### mussels-gray.png
The testing image, which give n=63 mussels verified by manual count.
It was produced with:

	convert mussels.png -colorspace Gray mussel-gray.png
