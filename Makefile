find_images: find_images.c
	gcc ./find_images.c -o ./find_images

clean:
	rm -rf out find_images urls webpage

