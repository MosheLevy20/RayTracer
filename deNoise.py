#script that denoises output from raytracer
from PIL import Image
import numpy as np
import sys
from PIL import ImageFilter

#open image
im = Image.open("twoSpheres.png")
#convert to numpy array
im = np.array(im)
#initialize new image
thresh = 100
for _ in range(2):
    newIm = np.zeros(im.shape)
    #loop through pixels, if pixel is very different from its neighbors, take the average of its neighbors
    for i in range(2,im.shape[0]-2):
        for j in range(2,im.shape[1]-2):
            neighbors = im[i-2:i+3,j-2:j+3]
            absDiff = abs((im[i,j]-np.mean(neighbors)).sum())
            if (absDiff > thresh):
                newIm[i][j] = np.mean(neighbors)
            else:
                newIm[i][j] = im[i][j]
        Im = newIm
#convert back to image
newIm = Image.fromarray(newIm.astype('uint8'))


newIm.save("denoised.png")
