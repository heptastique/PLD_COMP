mkdir -p ../antlr/build
mkdir -p ../antlr/install
cd ../antlr/build
cmake ../runtime_src_linux
make
DESTDIR=../install make install