.POSIX:

# commented out word target, you can append it here if you want
all: clean hW reverseStr

hW:
	${CXX} hW.cpp -o hW

reverseStr:
	${CXX} reverseStr.cpp -o reverseStr

# file 'world' is missing, I won't remove it but I will just comment out the
# make target
#world:
#	${CXX} world.cpp -o world

clean:
	rm -f world hW reverseStr
