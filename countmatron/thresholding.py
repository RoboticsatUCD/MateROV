import numpy as np
import scipy as sp
import matplotlib.pyplot as plt
from scipy import ndimage
from skimage import filter

# Load image into np.array.
img = plt.imread('mussels-gray.png')

# Apply Gaussian blur with 3 pixel std. deviation.
# TODO: Determine proper blur radius [interactively?].
imgf = ndimage.gaussian_filter(img, 3)

# Find threshold using Otsu's method.
threshold = filter.threshold_otsu(imgf)

# Label image areas.
labels, n = ndimage.label(imgf > threshold)

print(n)
