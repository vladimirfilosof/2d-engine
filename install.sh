sudo mkdir /usr/local/include/Engine
make -f build/makefile static_library
sudo mv libengine.a /usr/local/lib/ 
sudo rsync --exclude="*.cpp" -r --progress source/ /usr/local/include/Engine
echo Library installed!
