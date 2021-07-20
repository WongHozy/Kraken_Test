
libAES.so:aes.o PKCSNPadding.o base64.o AES128_CBC_PKCS5Padding.o
	g++ -shared $^ -o $@
aes.o:aes.cpp
	g++ -c -fpic $^ -o $@
PKCSNPadding.o:PKCSNPadding.cpp
	g++ -c -fpic $^ -o $@
base64.o:base64.cpp
	g++ -c -fpic $^ -o $@
AES128_CBC_PKCS5Padding.o:AES128_CBC_PKCS7Padding.cpp
	g++ -c -fpic $^ -o $@

.PHONY:clean
clean:
	rm *.o libAES.so
