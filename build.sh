export PKG_CONFIG_PATH=/home/jason/myinstall/lib/pkgconfig/
g++ -o addr --std=c++11  addr.cpp $(pkg-config --cflags --libs libbitcoin-system)
