# Modern C++ Project Template
C++ Project template that is built with CMake and Conan Package Manager. This project is a "work in progress".

## Build Status
[![Build Status](https://travis-ci.com/Portfence/cpp_project.svg?branch=main)](https://travis-ci.com/Portfence/cpp_project)


## Pre-requisites

```
$ sudo snap install conan
```

## Install as Conan Package
Located under ```~/.conan/data```
```
$ cd cpp_project
$ conan create . <user>/<version>
# e.g.
$ conan create . mando/stable
```
To use the created pacakge in another project, add ```"requires = cpp_project/1.0.0@mando/stable"``` to the other projects conanfile.py

## To develop in project

### Install dependencies
```
$ cd cpp_project
$ conan install . -if build
```
### Build project
Run CMake generate and build from Conan

```
$ conan build . -bf build
```

alternatively with CMake command

```
$ cmake . -Bbuild -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr/local
$ cmake --build build
```

### Traditional installation of project 

```
$ sudo cmake --install build
```
