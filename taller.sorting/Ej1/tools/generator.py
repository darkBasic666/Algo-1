import sys
import random

def usage():
	print
	print "usage: "
	print "  python generator.py N out_folder"
	print
	print "example: "
	print "  python generator.py 100 ../tests/"
	print

if __name__ == '__main__':
	ps= len(sys.argv)
	if ps != 3:
		usage()
		sys.exit()

	N= int(sys.argv[1])
	with open(str(sys.argv[2])+str(N)+'.in','w') as f:
		xs= random.sample(xrange(100000), N)
		f.write(str(N)+'\n')
		for x in xs:
			f.write(str(x)+' ')

	print "Done!"