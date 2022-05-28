# Corner detection for chessboaard/checkerboard
Corner detection code adapted from https://github.com/hengli/camodocal

## Building the code
```
mkdir build
cd build
cmake ..
make
```

## Running the code
```
./test_chessboard <directory_path>
```
There should be a file named ```image_paths.txt``` int the directory path containing the absolute path of all the images in the directory.