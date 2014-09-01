# Generated automatically from Makefile.in by configure.
srcdir = /root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/gdb/testsuite/gdb.java
VPATH = /root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/gdb/testsuite/gdb.java

all info install-info dvi install uninstall installcheck check:
	@echo "Nothing to be done for $@..."

.SUFFIXES: .java .class .o .exe .exp .check

# Do 'make javamisc.check' to run just the javamisc.exp test.

.exp.check:
	rootme=`pwd`/; export rootme; \
	cd .. ; \
	$(MAKE) just-check RUNTESTFLAGS="${RUNTESTFLAGS} $*.exp" \
	  EXPECT=${EXPECT}

clean mostlyclean:
	-rm -f *.o ${OBJS}  *.class *.exe *~ core

distclean maintainer-clean realclean: clean
	-rm -f Makefile config.status config.log
