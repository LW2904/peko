mkdir _temp
./hazedumper.exe -c haze-config.json -o _temp/hazedumper
mv _temp/hazedumper.hpp include/hazedumper.h
rm -r _temp
