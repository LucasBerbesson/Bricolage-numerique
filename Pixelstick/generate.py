from PIL import Image
text_file = open("output.txt", "w")
im = Image.open('test.png')
pixels = list(im.getdata())
for pixel in pixels:
	red,green,blue,brightness = pixel
	text_file.write("{}, {}, {}\n".format(red,green,blue))

text_file.close()