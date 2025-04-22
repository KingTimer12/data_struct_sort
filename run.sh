if [ ! -d "build" ]; then
    meson setup build
fi

cd build
meson compile
./data_struct_sort
cd ..
