# photon-dance-simhash

To efficiently generate 64-bit simhash.

## Requirements

The following minimum versions are required to build the library

* CMake 3.5
* GCC 4.9

## Installation

```text
# Check out the library.
$ git clone https://github.com/amazingchow/photon-dance-simhash.git

# Go to the library root directory
$ cd photon-dance-simhash

# Make a build directory to place the build output.
$ cmake -E make_directory "build"

# Generate build system files with cmake.
$ cmake -E chdir "build" cmake -DCMAKE_BUILD_TYPE=Release ../

# Build the library.
$ cmake --build "build" --config Release

# Install the library globally.
$ sudo cmake --build "build" --config Release --target install
```

## Contributing

### Step 1

* 🍴 Fork this repo!

### Step 2

* 🔨 HACK AWAY!

### Step 3

* 🔃 Create a new PR using https://github.com/amazingchow/photon-dance-simhash/compare!

## Support

* Reach out to me at <jianzhou42@163.com>.

## License

* This project is licensed under the MIT License - see the **[MIT license](http://opensource.org/licenses/mit-license.php)** for details.
