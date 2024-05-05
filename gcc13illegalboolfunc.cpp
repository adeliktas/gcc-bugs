#include <iostream>

bool foo()
{
	std::cout << "does foo and doesn't need to return" << std::endl;
}

int main()
{
	foo();
	std::cout << "foo was called" << std::endl;
	return 0;
}

/*
> g++ -o gcc13illegalboolfunc gcc13illegalboolfunc.cpp
In gcc 12 this would not crash/SIGILL.
In gcc 13 this does return SIGILL and gives a warning when building
Program received signal SIGILL, Illegal instruction.
0x000055555555519c in foo() ()
>0x55555555519c <_Z3foov+51>     ud2


COLLECT_GCC=gcc
COLLECT_LTO_WRAPPER=/usr/libexec/gcc/x86_64-pc-linux-gnu/13/lto-wrapper
Target: x86_64-pc-linux-gnu
Configured with: /var/tmp/portage/sys-devel/gcc-13.2.1_p20240210/work/gcc-13-20240210/configure --host=x86_64-pc-linux-gnu --build=x86_64-pc-linux-gnu --prefix=/usr --bindir=/usr/x86_64-pc-linux-gnu/gcc-bin/13 --includedir=/usr/lib/gcc/x86_64-pc-linux-gnu/13/include --datadir=/usr/share/gcc-data/x86_64-pc-linux-gnu/13 --mandir=/usr/share/gcc-data/x86_64-pc-linux-gnu/13/man --infodir=/usr/share/gcc-data/x86_64-pc-linux-gnu/13/info --with-gxx-include-dir=/usr/lib/gcc/x86_64-pc-linux-gnu/13/include/g++-v13 --disable-silent-rules --disable-dependency-tracking --with-python-dir=/share/gcc-data/x86_64-pc-linux-gnu/13/python --enable-languages=c,c++,fortran --enable-obsolete --enable-secureplt --disable-werror --with-system-zlib --enable-nls --without-included-gettext --disable-libunwind-exceptions --enable-checking=release --with-bugurl=https://bugs.gentoo.org/ --with-pkgversion='Gentoo 13.2.1_p20240210 p14' --with-gcc-major-version-only --enable-libstdcxx-time --enable-lto --disable-libstdcxx-pch --enable-shared --enable-threads=posix --enable-__cxa_atexit --enable-clocale=gnu --enable-multilib --with-multilib-list=m32,m64 --disable-fixed-point --enable-targets=all --enable-libgomp --disable-libssp --disable-libada --enable-cet --disable-systemtap --disable-valgrind-annotations --disable-vtable-verify --disable-libvtv --with-zstd --without-isl --enable-default-pie --enable-default-ssp --disable-fixincludes --with-build-config=bootstrap-cet
Thread model: posix
Supported LTO compression algorithms: zlib zstd
gcc version 13.2.1 20240210 (Gentoo 13.2.1_p20240210 p14)

*/
