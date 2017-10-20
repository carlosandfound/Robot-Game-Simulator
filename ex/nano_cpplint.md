## How to install an example of nanogui.

1. Go to the repo on GitHub: https://github.com/wjakob/nanogui
2. Find a good place on your machine to install nanogui.
3. Clone the repo with `--recursive` tag:
    ```git clone --recursive https://github.com/wjakob/nanogui
    ```
4. Use cmake to create a make file (Windows might have other directions - look at documentation).
    ```
    cd nanogui
    mkdir build
    cd build
    cmake ..
    ```
    What just happened? You created a directory in which to build. You called cmake
    on the nanogui directory, which will create a makefile.

5. Call the makefile to build the examples: `make`

6. Run example1: `./example1`. There are 4 examples.

7. Explore the source code for the example which can be found at  `cd ../src`.


## How to check Google Style Compliance on a file.

Google Style Guide: https://google.github.io/styleguide/cppguide.html
cpplint: https://github.com/google/styleguide/tree/gh-pages/cpplint

1. Obtain cpplint (this is a python script, so if you don't have Python,
  you have to start there: python.org).

2. With Python3 installed, you should be able to get cpplint with:
    `pip3 install cpplint`

3. Now run a file through the checker:
    `cpplint <filename>`

4.  Follow the style guide and the comments to get to no errors.

## Practice Google Style Compliance

Try to get the Visitor Pattern example to comply or the Duck example from
lab03. I wouldn't try it on the in-class polymorphism duck example, as that
is so far from compliance, it would require a restructuring of the files.
