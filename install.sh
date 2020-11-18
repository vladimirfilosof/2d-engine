#!/usr/bin/bash

rm -r /usr/local/include/Engine
rm -r /usr/local/lib/libengine.a

mkdir /usr/local/include/Engine
make -f build/makefile static_library
chown root libengine.a
chmod +rwx libengine.a
mv libengine.a /usr/local/lib/ 
rsync --exclude="*.cpp" -r source/ /usr/local/include/Engine
echo Library installed!
