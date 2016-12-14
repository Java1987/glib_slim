COMM_MAKE = 1
COMM_ECHO = 1
version=1.0
v=debug
include g.mk

########## options ##########
CFLAGS += -g -fno-strict-aliasing -O2 -Wall -export-dynamic \
	-Wall -pipe -D_GNU_SOURCE -D_REENTRANT -fPIC -Wno-deprecated

LINKS += -g -lglib

LIB_OBJS = gstrfunc.o 

PROGS = glib

all: $(PROGS)

glib: libglib.a libglib.so

libglib.a: $(LIB_OBJS)
	$(ARSTATICLIB) 
libglib.so: $(LIB_OBJS)
	$(BUILDSHARELIB)
gmain: gmain.o
	$(BUILDEXE)

#dist: clean libencrypt-$(version).src.tar.gz

#libencrypt-$(version).src.tar.gz:
#	@find . -type f | grep -v CVS | grep -v .svn | sed s:^./:libencrypt-$(version)/: > MANIFEST
#	@(cd ..; ln -s libencrypt_pub libencrypt-$(version))
#	(cd ..; tar cvf - `cat libco_pub/MANIFEST` | gzip > libencrypt_pub/libencrypt-$(version).src.tar.gz)
#	@(cd ..; rm libencrypt-$(version))

clean:
	$(CLEAN) *.o $(PROGS)
	rm -fr MANIFEST lib solib libglib-$(version).src.tar.gz libglib-$(version)

